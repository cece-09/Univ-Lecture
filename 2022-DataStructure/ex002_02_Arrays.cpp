#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

// Program 2.1

float sum(float[], int); // function
float input[MAX_SIZE], answer;
int i;

int main() {
	for (i = 0; i < MAX_SIZE; i++) {  // 0~99���� ����
		input[i] = i;
	}
	answer = sum(input, MAX_SIZE);
	printf("The sum is: %f\n", answer);

	return 0;
}

float sum(float list[], int n) { // list[]�� length n�� �޾Ƽ�
	int i;                       // �迭�� ��� ������ �� ����
	float tempsum = 0;
	for (i = 0; i < n; i++) {
		tempsum += list[i];
	}
	return tempsum;
}