#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int num1, num2;
	char oper;

	printf("������ �ǿ�����1 �ǿ�����2 ������� �Է� : ");
	scanf("%c %d %d", &oper, &num1, &num2);

	switch (oper) {
	case '+':
		printf("%d + %d = %d\n", num1, num2, num1 + num2);
		break;
	case '*':
		printf("%d * %d = %d\n", num1, num2, num1 * num2);
		break;
	default:
		printf("������� �ʴ� ������\n");
	}
	return 0;
	
}