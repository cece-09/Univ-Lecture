#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int arr[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	int* p = arr;
	int arrSize = sizeof(arr) / sizeof(*p); //배열 원소 수
	int i;

	printf("********** Original Array *************\n");
	for (i = 0; i < arrSize; i++) {
		printf(" %3d", *(p + i));
	}
	printf("\n");

	printf("********** Reversed Array *************\n");
	for (i = 0; i < arrSize; i++) {
		printf(" %3d", *(p + (arrSize - 1) - i));
	}
	printf("\n");

	return 0;
}