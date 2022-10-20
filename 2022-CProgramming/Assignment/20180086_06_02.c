#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {

	int num;
	int sum = 0;
	int count = 0;
	double avg = 0;

	while (1) {

		rewind(stdin);

		printf("Enter int num between 1 and 100 : ");
		scanf("%d", &num);

		if (num <= 0) {
			break;  //0보다 작으면 작업 종료
		}

		if (num > 100) {  //100보다 큰 수 입력 시 continue
			continue;
		}

		if (num % 2 == 0) {  //짝수 입력 시 continue
			continue;
		}

		sum += num; //조건을 만족하는 정수의 합
		count += 1;    //조건을 만족하는 정수의 개수
		avg = sum / (double) count;
	}
	
	printf("****************************");
	printf("The number of odd data between 1 and 100 : %d\n", count);
	printf("Sum : %d and Average : %.2lf\n", sum, avg);

	return 0;
}