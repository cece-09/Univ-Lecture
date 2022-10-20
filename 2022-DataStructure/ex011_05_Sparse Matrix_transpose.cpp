#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 101 /*maximum number of terms + 1*/

typedef struct {
	int row;
	int col;
	int value;
}term;

void transpose(term*, term*);
void printMatrix(term*);
void initArrAll(int*, int, int);

/*
* 0 1 2 3 4 5
* 
* 0 0 0 1 0 0   0
* 3 0 0 0 6 0   1
* 0 4 0 0 0 0   2
* 0 0 0 0 0 0   3
* 0 0 0 0 0 0   4
*/

int main() {
	term a[MAX_TERMS] = {
		{5, 6, 4},        //the numbers of the rows, cols, nonzero vals
		{0, 3, 1},
		{1, 0, 3},
		{1, 4, 6},
		{2, 1, 4}
	};

	term b[MAX_TERMS] = { 0 };
	transpose(a, b);

	printMatrix(a);
	printf("\n**********\n");
	printMatrix(b);

	return 0;
}

void transpose(term a[], term b[]) {
	/* b is set to the transpose of a */
	int n, currentb;
	n = a[0].value;
	b[0].row = a[0].col;
	b[0].col = a[0].row;
	b[0].value = n;

	if (n > 0) { // if 'a' is a non-zero matrix
		currentb = 1;
		for (int i = 0; i < a[0].col; i++) {
			for (int j = 1; j < n + 1; j++) {
				if (a[j].col == i) {
					// col = 0 부터 시작해서 순차적으로 transpose
					b[currentb].row = a[j].col;
					b[currentb].col = a[j].row;
					b[currentb].value = a[j].value;
					currentb++;
				}
			}
		}

	}

	return;
}

void printMatrix(term t[]) {
	int rows = t[0].row;  //5
	int cols = t[0].col;  //6
	int num = t[0].value; //4 non-zero elements

	//값을 저장할 일차원 배열
	int n = rows * cols;  //30
	int* arr = (int*)malloc(sizeof(int) * n);
	if (arr == NULL) {
		printf("not allocated\n");
		exit(1);
	}

	//먼저 0으로 모두 초기화하고, 
	initArrAll(arr, n, 0);

	//triple로 선언한 배열 요소만 값을 지정함
	for (int i = 1; i < num + 1; i++) {
		int t_row = t[i].row;
		int t_col = t[i].col;
		int t_val = t[i].value;
		arr[(t_row * cols) + t_col] = t_val;		
	}

	//this is actual print action
	for (int i = 0; i < n; i++) {
		if (i % cols == 0 && i != 0) {
			printf("\n");
		}
		printf("%d ", *(arr + i));
	}

	free(arr);
}

void initArrAll(int* arr, int num, int initVal) {
	for (int i = 0; i < num; i++) {
		arr[i] = initVal;
	}
}

