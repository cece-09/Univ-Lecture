#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10


int main() {
	int arrScore[SIZE]; //���� �迭
	int arrRank[SIZE]; //���� �迭
	int i, j = 0;
	

	srand((unsigned)time(NULL));
	
	for (i = 0; i < SIZE; i++) {
		int randScore = rand() % 30 + 70; //70~99���� ����
		arrScore[i] = randScore;
	}

	for (i = 0; i < SIZE; i++) {
		arrRank[i] = 1;
	}

	//���� �ű��
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
