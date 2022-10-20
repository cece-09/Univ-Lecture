#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void mulMatrix(int(*A)[3], int, int(*B)[4], int(*R)[4]);
int main() {
	int A[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int B[3][4] = { 11,12,13,14,21,22,23,24,31,32,33,34 };
	int R[3][4];

	int rowA = sizeof(A) / sizeof(A[0]); //최대 행 수

	mulMatrix(A, rowA, B, R);
	int rowR = sizeof(R) / sizeof(R[0]); //R의 최대 행 수
	int colR = sizeof(R[0]) / sizeof(int); //R의 최대 열 수 
	int i, j;
	for (i = 0; i < rowR; i++) {
		for (j = 0; j < colR; j++) {
			printf("%3d ", *(R[i] + j));
		}
		printf("\n");
	}

	return 0;
}

void mulMatrix(int(*A)[3], int rowA, int(*B)[4], int(*R)[4]) {
	int i, j, k;
	int count = 0;
	int colB = sizeof(B[0]) / sizeof(int); //최대 열 수

	for (i = 0; i < rowA; i++) {
		for (j = 0; j < colB; j++) {
			*(R[i] + j) = 0;
			for (k = 0; k < rowA; k++) {
				*(R[i] + j) += *(A[i] + k) * *(B[k] + j);
			}
		}
	}

	return;
}