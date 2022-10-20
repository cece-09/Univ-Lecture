#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct fakeCoin {
	int first;
	int second;
}fc;

void findFakeCoin(int*, int, fc);

int main() {
	int n = 8;
	int S[] = { 1, 1, 0, 1, 0, 1, 1, 1 }; //0 = 가짜 동전
	
	fc fakeCoin = {.first = 1, .second = 1}; // 1으로 초기화
	findFakeCoin(S, n, fakeCoin);
	
	printf("first fake coin index : %d\n", fakeCoin.first);
	printf("second fake coin index : %d", fakeCoin.second);
	return 0;
}

void findFakeCoin(int* S, int n, fc fakeCoin) {

	while (1) {

		//divide
		n = n / 2;
		int* left = (int*)malloc(sizeof(int) * n);
		int* right = (int*)malloc(sizeof(int) * n);
		if (left == NULL || right == NULL){
			printf("not allcated");
			exit(1); 
		}

		int wLeft = 0;
		int wRight = 0;

		for (int i = 0; i < n; i++) {
			left[i] = S[i];
			right[i] = S[i + n];

			wLeft += left[i];
			wRight += right[i];
		}

		if (wLeft < wRight) {
			S = left;
		}

		if (n == 1) {
			break;
		}
	}
}