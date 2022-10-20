#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{

	int i, j;

	for (i = 2; i < 10; i++) {

		for (j = 1; j <= i; j++) {
			printf("%d*%d= %2d  ", i, j, i * j);
		}

		printf("\n");
	}

	return 0;
}