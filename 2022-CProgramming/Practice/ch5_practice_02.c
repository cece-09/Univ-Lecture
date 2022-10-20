#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int num1, num2;
	char oper;

	printf("연산자 피연산자1 피연산자2 순서대로 입력 : ");
	scanf("%c %d %d", &oper, &num1, &num2);

	switch (oper) {
	case '+':
		printf("%d + %d = %d\n", num1, num2, num1 + num2);
		break;
	case '*':
		printf("%d * %d = %d\n", num1, num2, num1 * num2);
		break;
	default:
		printf("허용하지 않는 연산자\n");
	}
	return 0;
	
}