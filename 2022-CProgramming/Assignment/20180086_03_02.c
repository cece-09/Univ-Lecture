#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int num;

	printf("Enter a two-digit integer :");
	scanf("%d", &num);                              //두자리 정수 입력받기

	int a = num / 10;
	int b = num % 10;                               //각 자리수 구하기

	int result = 1 << (a * b);                      //2의 거듭제곱 구하기
	printf("2 to %d times : %d\n", a * b, result);  //출력
}
	