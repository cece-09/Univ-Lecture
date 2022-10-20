#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define arrSIZE 10

int main() {

	int i,j;
	int k = 0;
	int count = 0;
	int chkPrime = 1;
	int userArray[arrSIZE];   //입력 받아 저장하는 배열
	int primeArray[arrSIZE] = { 0 };  //입력 받은 수 중 소수만 저장

	for (i = 0; i < arrSIZE; i++) {
		rewind(stdin);
		printf("Enter %d positive int data ( > 1) : ", i + 1);
		scanf("%d", &userArray[i]);
	}  //입력 받아 배열에 저장

	for (i = 0; i < arrSIZE; i++) {

		chkPrime = 1; //배열 값이 소수라고 가정

		if (userArray[i] <= 1) {
			continue;
		} //1, 0 또는 음수인 경우 다음 element로 넘어가기

		for (j = 2; j < userArray[i]; j++) {
			if (userArray[i] % j == 0) {
				chkPrime = 0;
				break;  
			}
		}  //어떤 수 j로 나누어지면 소수가 아님


		if (chkPrime == 1) {
			primeArray[k] = userArray[i];
			k++;
			count++;
		} //소수인 경우 소수 배열에 저장
	}

	printf("************* %d prime numbers **************\n", count);
	for (i = 0; i < arrSIZE; i++) {
		if (primeArray[i] != 0) {
			printf(" %2d", primeArray[i]);
		}
	}
	printf("\n");    //소수 개수와 소수 출력

	return 0;
}
