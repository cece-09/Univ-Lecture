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
		for (i = cnt - 1; i >= 0; i--) { // sorted_data�� ������ ���Һ��� 0���� buf���� ū ���Ҹ� Ž��
			if (sorted_data[i] > buf)    // ���� ũ��
				sorted_data[i + 1] = sorted_data[i]; // �ش� ���ҵ��� ���������� �� ĭ �ű��.
			else {
				sorted_data[i + 1] = buf;  // buf�� �� Ŭ ��� �� ������ �ε����� buf�� �����ϰ� break
				break;
			}
		}
		if (i < 0) sorted_data[0] = buf; // buf�� ���� ���� ���
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