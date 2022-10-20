#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int num;
	int i = 1;
	int sum = 0;
	int count = 0;

	printf("Enter positive int num : ");
	scanf("%d", &num);

	while (i <= num) {

		if (num % i == 0) {
			printf(" %2d", i);
			count++;
		}
		
		i++;
	}

	printf("\n**There are %d divisions of %d**\n", count, num);
	return 0;
}