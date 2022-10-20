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
		larger = a;          // a < b 인 경우 반대로 변수 지정
	}
	else if (a == b) {
		return 0;            //a == b 인 경우 사이의 합은 0
	}
	
	for (i = smaller; i <= larger; i++) {   //smaller 이상 larger 미만의 경우
		result += i; //합 구하기
	}

	return result;
}