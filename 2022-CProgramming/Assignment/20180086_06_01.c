#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sumBetween(int, int);

int main() {
	
	int num1, num2;
	int sum = 0;

	printf("Enter two integer : ");
	scanf("%d %d", &num1, &num2);

	sum = sumBetween(num1, num2);
	printf("The sum between two integer is %d\n", sum);
	return 0;
}

int sumBetween(int a, int b) {

	int smaller = a, larger = b;
	int result = 0;  
	int i;

	if (a > b) {
		smaller = b;
		larger = a;          // a < b �� ��� �ݴ�� ���� ����
	}
	else if (a == b) {
		return 0;            //a == b �� ��� ������ ���� 0
	}
	
	for (i = smaller; i <= larger; i++) {   //smaller �̻� larger �̸��� ���
		result += i; //�� ���ϱ�
	}

	return result;
}