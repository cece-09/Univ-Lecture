#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10


int main() {
	int arrScore[SIZE]; //점수 배열
	int arrRank[SIZE]; //석차 배열
	int i, j = 0;
	

	srand((unsigned)time(NULL));
	
	for (i = 0; i < SIZE; i++) {
		int randScore = rand() % 30 + 70; //70~99난수 생성
		arrScore[i] = randScore;
	}

	for (i = 0; i < SIZE; i++) {
		arrRank[i] = 1;
	}

	//석차 매기기
	int larger = arrScore[0];
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			if (arrScore[i] < arrScore[j]) {
				++arrRank[i];
			}
			
		}
	}

	for (i = 0; i < SIZE; i++) {
		printf("%d student(%d) : %d\n", i + 1, arrScore[i], arrRank[i]);
	}

	return 0;
}
