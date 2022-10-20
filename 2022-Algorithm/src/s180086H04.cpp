#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void mergeXid(int, int, unsigned*, unsigned*, unsigned*, double*); // Xid merge function
void mergeYid(unsigned, unsigned, unsigned, unsigned*, unsigned*, double*); // Yid merge function
void sortYid(unsigned, unsigned, unsigned*, double*); // Yid merge function
double dist(double, double, double, double); // calculate distance function
double combine(unsigned*, unsigned, unsigned, unsigned*, double*, double*, double, double, unsigned*, unsigned*);

double closestPairDC(
	unsigned L, unsigned R,            // leftmost and rightmost indices
	unsigned* pt1, unsigned* pt2,      // closest pair points indices
	double* X, double* Y,              // (x, y) positions array (input)
	unsigned* Xid,                     // point index array (sorted by x coords)
	unsigned* Yid,                     // point index array (gradually sorted by y coords)
	unsigned* TMP,                     // temporal index array
	unsigned THR                       // threshold value
) {
	if ((R - L + 1) <= THR) { // threshold보다 작은 경우
		// brute force method
		*(pt1) = Xid[L];
		*(pt2) = Xid[R];
		double d = dist(X[*(pt1)], X[*(pt2)], Y[*(pt1)], Y[*(pt2)]);
		double tmp;
		for (int i = L; i < R; i++) {
			for (int j = i+1; j < R; j++) {
				tmp = dist(X[i], X[j], Y[i], Y[j]);
				if (tmp < d) {
					d = tmp;
					*(pt1) = i;
					*(pt2) = j; 
				}
			}
		}

		for (int i = L; i <= R; i++) {
			Yid[i] = Xid[i];
		}

		// sort the Yid[L:R]
		sortYid(L, R, Yid, Y);
		return d;
	}
	
	// divide
	unsigned M = floor((L + R) / 2);

	// conquer
	unsigned Lpt1, Lpt2, Rpt1, Rpt2;
	double dL = closestPairDC(L, M, &Lpt1, &Lpt2, X, Y, Xid, Yid, TMP, THR);    // closest pair in range(L,   M)
	double dR = closestPairDC(M+1, R, &Rpt1, &Rpt2, X, Y, Xid, Yid, TMP, THR);  // closest pair in range(M+1, R)
	
	// merge Yid
	mergeYid(L, M, R, Yid, TMP, Y);  // merge Yid[L:M], Yid[M+1, R]

	// get dLR
	double dLR;
	if (dL == 0 && dR == 0) {
		dLR = dist(X[Lpt1], X[Rpt1], Y[Lpt1], Y[Rpt1]);
	}
	else {
		if (dL < dR) {
			dLR = dL;
			*(pt1) = Lpt1;
			*(pt2) = Lpt2;
		}
		else {
			dLR = dR;
			*(pt1) = Rpt1;
			*(pt2) = Rpt2;
		}
	}	

	// combine
	double Xmid = (X[Xid[M]] + X[Xid[M + 1]]) / 2;   // 중간 영역 추출
	double d = combine(Yid, L, R, TMP, X, Y, dLR, Xmid, pt1, pt2);

	return d;
}

double combine(
	unsigned* Yid, unsigned L, unsigned R,
	unsigned* TMP, double* X, double* Y,
	double dLR, double Xmid,
	unsigned* pt1, unsigned* pt2 ) {

	int cnt = 0;
	// Yid에서 중간 영역에 해당하는 점 index 를 TMP로 복사
	for (int i = L; i <= R; i++) {
		if (X[Yid[i]] >= Xmid - dLR && X[Yid[i]] <= Xmid + dLR) {
			TMP[cnt] = Yid[i];
			cnt++;
		}
	}

	// TMP에서 dLR보다 작은 pair 탐색
	for (int i = 0; i < cnt; i++) {
		for (int j = i + 1; j < cnt; j++) {
			if (Y[TMP[j]] - Y[TMP[i]] >= dLR) break;
			double d = dist(X[TMP[i]], X[TMP[j]], Y[TMP[i]], Y[TMP[j]]);
			if (d < dLR) {
				*(pt1) = TMP[i]; *(pt2) = TMP[j];
				dLR = d;
			}
		}
	}
	return dLR;
}

// merge two sorted Yid array
void mergeYid(unsigned L, unsigned M, unsigned R, unsigned* Yid, unsigned* TMP, double* Y) {
	int i, j, k;
	i = L; j = M + 1; k = L;

	while (i <= M && j <= R) {
		if (Y[Yid[i]] < Y[Yid[j]]) {
			TMP[k] = Yid[i];
			i++;
		}
		else {
			TMP[k] = Yid[j];
			j++;
		}
		k++;
	}

	if (i > M) {
		while (j <= R && k <= R) {
			TMP[k] = Yid[j];
			k++; j++;
		}
	}
	else {
		while (i<= M && k <= R) {
			TMP[k] = Yid[i];
			k++; i++;
		}
	}
	// copy U to Yid
	for (int i = L; i <= R; i++) {
		Yid[i] = TMP[i];
	}
}

// sort point indices by x-coords
void sortXid(double* X, unsigned* Xid, unsigned* TMP, unsigned N) {
	if (N > 1) {
		const int h = floor(N / 2);
		const int m = N - h;

		unsigned* U, * V;
		U = new unsigned[h];
		V = new unsigned[m];
		if (U == NULL || V == NULL) exit(1);

		for (int i = 0; i < h; i++) {
			U[i] = Xid[i];
		}
		for (int i = 0; i < m; i++) {
			V[i] = Xid[h + i];
		}

		sortXid(X, U, TMP, h);
		sortXid(X, V, TMP, m);
		mergeXid(h, m, U, V, Xid, X);
	}
}

// merge two sorted Xid array
void mergeXid(int h, int m, unsigned* U, unsigned* V, unsigned* Xid, double* X) {
	int i, j, k;
	i = 0, j = 0, k = 0;
	while (i < h && j < m) {
		if (X[U[i]] < X[V[j]]) {
			Xid[k] = U[i]; i++;
		}
		else {
			Xid[k] = V[j]; j++;
		}
		k++;
	}
	if (i >= h) {
		while (j < m && k < h + m) {
			Xid[k] = V[j];
			j++;
			k++;
		}
	}
	else {
		while (i < h && k < h + m) {
			Xid[k] = U[i];
			i++;
			k++;
		}
	}

	delete[] U;
	delete[] V;
}

// selection sort
void sortYid(unsigned L, unsigned R, unsigned* Yid, double* Y) {
	int min;
	double tmp;
	for (int i = L; i <= R ; i++) {
		min = i; // index of Yid
		for (int j = i + 1; j <= R; j++) {
			if (Y[Yid[j]] < Y[Yid[min]])
				min = j;
		}

		// swap
		tmp = Yid[min];
		Yid[min] = Yid[i];
		Yid[i] = tmp;
	}
}

// calculate distance
double dist(double x1, double x2, double y1, double y2) {
	double dist = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	return dist;
}