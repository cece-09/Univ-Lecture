#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a;
	int b;

	printf("Enter two int num : \n");
	scanf("%d %d", &a, &b);  //�� ���� �Է¹ޱ�

	printf("**************************************\n");
	printf("Original value : a = %d, b = %d\n", a, b);

	int temp;
	temp = a;
	a = b;
	b = temp;  //���� �� swap

	int sum = a + b;
	float avg = sum / 2.0; //�հ� ��� ���ϱ�

	printf("Exchanged value : a = %d, b = %d\n", a, b);
	printf("Sum : %d, Average : %.2f\n", sum, avg); //���
	
	return 0;
}
