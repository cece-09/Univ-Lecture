#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int** make2dArray(int, int);

int main() {
	int** p;
	int rows = 3;
	int cols = 5;
	p = make2dArray(rows, cols);

	// 할당된 메모리에 rand() 값 넣기
	for (int i = 0; i < rows; i++) {
		printf("%d th row\n", i+1);
		printf("*p  adress : %p, value : %p\n", p + i, *(p + i));
		for (int j = 0; j < cols; j++) {
			int val = rand();
			*(*(p + i) + j) = val;
			printf("%d th column ", j+1);
			printf("**p adress : %p, value %d\n", *(p + i) + j, *(*(p + i) + j));
		}
		printf("\n");
	}

	// 할당 free
	for (int i = 0; i < rows; i++) {
		free(p[i]);
	}
	free(p);
	return 0;
}

int** make2dArray(int rows, int cols) {
	int** x;
	int i;

	/* allocate memory for row pointers */
	x = (int**)malloc(rows * sizeof(*x)); // x는 배열 포인터 배열의 포인터

	/* allocate memory for each row */
	for (i = 0; i < rows; i++) {
		x[i] = (int*)malloc(cols * sizeof(**x));
	}
	return x;
}