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
			break;  //0���� ������ �۾� ����
		}

		if (num > 100) {  //100���� ū �� �Է� �� continue
			continue;
		}

		if (num % 2 == 0) {  //¦�� �Է� �� continue
			continue;
		}

		sum += num; //������ �����ϴ� ������ ��
		count += 1;    //������ �����ϴ� ������ ����
		avg = sum / (double) count;
	}
	
	printf("****************************");
	printf("The number of odd data between 1 and 100 : %d\n", count);
	printf("Sum : %d and Average : %.2lf\n", sum, avg);

	return 0;
}