#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 3

void inputMtx(int m[][SIZE], char mName);
void printMtx(int m[][SIZE]);
void addMtx(int A[][SIZE], int B[][SIZE], int R[][SIZE]);
void subMtx(int A[][SIZE], int B[][SIZE], int R[][SIZE]);
void mulMtx(int A[][SIZE], int B[][SIZE], int R[][SIZE]);

int main() {
	int i, j;

	char mtxNameA = 'A';
	char mtxNameB = 'B';
	int mtxA[SIZE][SIZE]; //3*3 배열
	int mtxB[SIZE][SIZE]; //3*3 배열
	int mtxAddAB[SIZE][SIZE]; //합 저장 배열
	int mtxSubAB[SIZE][SIZE]; //차 저장 배열
	int mtxMulAB[SIZE][SIZE]; //곱 저장 배열

	inputMtx(mtxA, mtxNameA);
	inputMtx(mtxB, mtxNameB);
	addMtx(mtxA, mtxB, mtxAddAB);
	subMtx(mtxA, mtxB, mtxSubAB);
	mulMtx(mtxA, mtxB, mtxMulAB);

	//print all matrix
	printf("\n*************** Matrix A:\n"); printMtx(mtxA);
	printf("\n*************** Matrix B:\n"); printMtx(mtxB);
	printf("\n*************** Matrix A + B:\n"); printMtx(mtxAddAB);
	printf("\n*************** Matrix A - B:\n"); printMtx(mtxSubAB);
	printf("\n*************** Matrix A x B:\n"); printMtx(mtxMulAB);

	return 0;
}

//배열 값을 입력받는 함수
void inputMtx(int m[][SIZE], char mName) {
	int i, j;

	printf("************** Inputing Matrix %c\n", mName);
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			printf("Enter element of %c Matrix [%d][%d] : ", mName, i, j);
			rewind(stdin);
			scanf("%d", &m[i][j]);
		}
	} //함수 값 입력

	return;
}

//배열 값을 출력하는 함수
void printMtx(int m[][SIZE]) {
	int i, j;

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			printf(" %2d", m[i][j]);
		}
		printf("\n");
	}

	return;
}

//배열 값의 합 함수
void addMtx(int A[][SIZE], int B[][SIZE], int R[][SIZE]) {
	int i, j;

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			R[i][j] = A[i][j] + B[i][j];
		}
	}

	return;
}

//배열 값의 차 함수
void subMtx(int A[][SIZE], int B[][SIZE], int R[][SIZE]) {
	int i, j;

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			R[i][j] = A[i][j] - B[i][j];
		}
	}

	return;
}

//배열 값의 곱 함수
void mulMtx(int A[][SIZE], int B[][SIZE], int R[][SIZE]) {
	int i, j, k;

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			R[i][j] = 0; //초기화
			for (k = 0; k < SIZE; k++) {
				R[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	return;
}