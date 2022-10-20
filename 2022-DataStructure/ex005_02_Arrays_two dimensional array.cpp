#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int** make2dArray(int, int);

int main() {
	int** p;
	int rows = 3;
	int cols = 5;
	p = make2dArray(rows, cols);

	// �Ҵ�� �޸𸮿� rand() �� �ֱ�
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

	// �Ҵ� free
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
	x = (int**)malloc(rows * sizeof(*x)); // x�� �迭 ������ �迭�� ������

	/* allocate memory for each row */
	for (i = 0; i < rows; i++) {
		x[i] = (int*)malloc(cols * sizeof(**x));
	}
	return x;
}