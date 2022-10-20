#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

int main() {

	int i, j;
	int tenElem[SIZE];

	srand((unsigned)time(NULL));

	for (i = 0; i < SIZE; i++) {		
		int randNum = rand() % 10 + 1;
		tenElem[i] = randNum;
	} //1부터 10까지 난수 저장하기

	for (i = 0; i < SIZE; i++) {
		printf("%d : ", tenElem[i]);
		for (j = 0; j < tenElem[i]; j++) {
			printf("*");
		}
		printf("\n");
	} //난수만큼 * 출력하기

	return 0;
}