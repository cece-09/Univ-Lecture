#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define arrSIZE 10

int main() {

	int i,j;
	int k = 0;
	int count = 0;
	int chkPrime = 1;
	int userArray[arrSIZE];   //�Է� �޾� �����ϴ� �迭
	int primeArray[arrSIZE] = { 0 };  //�Է� ���� �� �� �Ҽ��� ����

	for (i = 0; i < arrSIZE; i++) {
		rewind(stdin);
		printf("Enter %d positive int data ( > 1) : ", i + 1);
		scanf("%d", &userArray[i]);
	}  //�Է� �޾� �迭�� ����

	for (i = 0; i < arrSIZE; i++) {

		chkPrime = 1; //�迭 ���� �Ҽ���� ����

		if (userArray[i] <= 1) {
			continue;
		} //1, 0 �Ǵ� ������ ��� ���� element�� �Ѿ��

		for (j = 2; j < userArray[i]; j++) {
			if (userArray[i] % j == 0) {
				chkPrime = 0;
				break;  
			}
		}  //� �� j�� ���������� �Ҽ��� �ƴ�


		if (chkPrime == 1) {
			primeArray[k] = userArray[i];
			k++;
			count++;
		} //�Ҽ��� ��� �Ҽ� �迭�� ����
	}

	printf("************* %d prime numbers **************\n", count);
	for (i = 0; i < arrSIZE; i++) {
		if (primeArray[i] != 0) {
			printf(" %2d", primeArray[i]);
		}
	}
	printf("\n");    //�Ҽ� ������ �Ҽ� ���

	return 0;
}
