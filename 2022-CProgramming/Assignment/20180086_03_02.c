#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int num;

	printf("Enter a two-digit integer :");
	scanf("%d", &num);                              //���ڸ� ���� �Է¹ޱ�

	int a = num / 10;
	int b = num % 10;                               //�� �ڸ��� ���ϱ�

	int result = 1 << (a * b);                      //2�� �ŵ����� ���ϱ�
	printf("2 to %d times : %d\n", a * b, result);  //���
}
	