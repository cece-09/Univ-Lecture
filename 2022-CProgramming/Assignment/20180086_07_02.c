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
	int mtxA[SIZE][SIZE]; //3*3 �迭
	int mtxB[SIZE][SIZE]; //3*3 �迭
	int mtxAddAB[SIZE][SIZE]; //�� ���� �迭
	int mtxSubAB[SIZE][SIZE]; //�� ���� �迭
	int mtxMulAB[SIZE][SIZE]; //�� ���� �迭

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

//�迭 ���� �Է¹޴� �Լ�
void inputMtx(int m[][SIZE], char mName) {
	int i, j;

	printf("************** Inputing Matrix %c\n", mName);
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			printf("Enter element of %c Matrix [%d][%d] : ", mName, i, j);
			rewind(stdin);
			scanf("%d", &m[i][j]);
		}
	} //�Լ� �� �Է�

	return;
}

//�迭 ���� ����ϴ� �Լ�
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

//�迭 ���� �� �Լ�
void addMtx(int A[][SIZE], int B[][SIZE], int R[][SIZE]) {
	int i, j;

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			R[i][j] = A[i][j] + B[i][j];
		}
	}

	return;
}

//�迭 ���� �� �Լ�
void subMtx(int A[][SIZE], int B[][SIZE], int R[][SIZE]) {
	int i, j;

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			R[i][j] = A[i][j] - B[i][j];
		}
	}

	return;
}

//�迭 ���� �� �Լ�
void mulMtx(int A[][SIZE], int B[][SIZE], int R[][SIZE]) {
	int i, j, k;

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			R[i][j] = 0; //�ʱ�ȭ
			for (k = 0; k < SIZE; k++) {
				R[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	return;
}