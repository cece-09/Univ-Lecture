#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define Max 5 //�� ��

void main() {
	int** data;
	int i;
	data = (int**)malloc(Max * sizeof(int*)); //������ �迭�� ���� �Ҵ� : 5��
	i = 0;

	if (data == NULL) {
		printf("not allocated\n");
		exit(1);
	}

	while (1)
	{
		if (data[i] == NULL) {
			printf("not allocated\n");
			exit(1);
		}

		data[i] = (int*)malloc(3 * sizeof(int));  //5�� 3��
		printf("Enter %d row 3 numbers : ", i + 1);
		scanf("%d %d %d", data[i], data[i] + 1, data[i] + 2);
		i++;
		if (i == Max) {
			break;
		}
	}

	printf("******* Data List *********\n");
	for (i = 0; i < Max; i++) {
		printf("%d row : %d %d %d\n", i, *(data[i]), *(data[i] + 1), *(data[i] + 2));
		//printf("%d row : %d %d %d\n", i, *(*(data + i)), *(*(data + i) + 1), *(*(data + i) + 2));
	}

	i = 0;
	while (i < Max) {
		free(data[i]);
		i++;
	}
	free(data);
}
