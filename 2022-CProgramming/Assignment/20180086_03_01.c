#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a;
	int b;

	printf("Enter two int num : \n");
	scanf("%d %d", &a, &b);  //두 정수 입력받기

	printf("**************************************\n");
	printf("Original value : a = %d, b = %d\n", a, b);

	int temp;
	temp = a;
	a = b;
	b = temp;  //변수 값 swap

	int sum = a + b;
	float avg = sum / 2.0; //합과 평균 구하기

	printf("Exchanged value : a = %d, b = %d\n", a, b);
	printf("Sum : %d, Average : %.2f\n", sum, avg); //출력
	
	return 0;
}
