#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ROW_SIZE 3
#define COL_SIZE 4

int main() {

	int i, j;
	int matrix[ROW_SIZE][COL_SIZE];  //[3][4] 배열 선언

	for (i = 0; i < ROW_SIZE; i++) {
		for (j = 0; j < COL_SIZE; j++) {
			matrix[i][j] = (i + 1) + (j * 3);  //배열 값 할당
			printf("%d ", matrix[i][j]);       //배열 값 출력
		}
		printf("\n");  //행 구분
	}

	return 0;
}