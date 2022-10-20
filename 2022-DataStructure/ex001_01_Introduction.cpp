#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_NUMBERS 1001


int main() {
	int data[MAX_NUMBERS];
	int sorted_data[MAX_NUMBERS];
	int buf = 0;
	int i = 0;
	int cnt = 0;

	while (1) {
		printf("Enter a number: ");
		scanf("%d", &buf);
		data[cnt] = buf;
		for (i = cnt - 1; i >= 0; i--) { // sorted_data의 마지막 원소부터 0까지 buf보다 큰 원소를 탐색
			if (sorted_data[i] > buf)    // 만약 크면
				sorted_data[i + 1] = sorted_data[i]; // 해당 원소들을 오른쪽으로 한 칸 옮긴다.
			else {
				sorted_data[i + 1] = buf;  // buf가 더 클 경우 그 오른쪽 인덱스에 buf를 저장하고 break
				break;
			}
		}
		if (i < 0) sorted_data[0] = buf; // buf가 가장 작은 경우
		cnt++;

		printf("unsorted: ");
		for (i = 0; i < cnt; i++) {
			printf("%d ", data[i]);
		}
		printf("\n");
		printf("sorted: ");
		for (i = 0; i < cnt; i++) {
			printf("%d ", sorted_data[i]);
		}
		printf("\n");
	}
	return 0;
}