#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void data_prn(int, int**);

int main() {
	int classNum;
	int** data;
	printf("Enter number of class : ");
	scanf("%d", &classNum);
	data = (int**)malloc(classNum * sizeof(int*));                          //������ �迭�� ���� �Ҵ�
	if (data == NULL) {
		printf("not allocated\n");
		exit(1);
	}                                                                       //malloc ����ó��

	int i = 0;
	while (i < classNum) {

		int studentNum = 0;                                                //size�� 0���� �ʱ�ȭ
		data[i] = (int*)malloc(0);                                         //size�� 0���� �ʱ�ȭ
		if (data[i] == NULL) {
			printf("not allocated\n");
			exit(1);
		}                                                                  //malloc ����ó��

		printf("**** Inputing %d class scores ****\n", i + 1);

		int j = 0;
		int tmp;
		int* tmpArr;
		while (1) {
			printf("Enter the score %d : ", j + 1);
			scanf("%d", &tmp);

			if (tmp < 0) break;                                           //������ �ԷµǸ� ����

			studentNum = j + 1;
			tmpArr = (int*)realloc(data[i], studentNum * sizeof(int));   //������ �Է��� �� ���� size�� 1�� �÷����� �Ҵ�
			if (tmpArr == NULL) {
				printf("not allocated\n");
				exit(1);
			}                                                            //realloc ����ó��  
			else {
				tmpArr[j] = tmp;
				data[i] = tmpArr;
				//*(data[i] + j) = tmpArr[j];
				j++;
			}
		}
		printf("\n");
		i++;
	}

	data_prn(classNum, data);                                           //��� �Լ��� ���

	i = 0;
	while (i < classNum) {                                              //�޸� ����
		free(data[i]);
		i++;
	}
	free(data);

	return 0;
}

void data_prn(int classNum, int** data) {
	int i, j;

	for (i = 0; i < classNum; i++) {
		printf("*** %d class scores ***\n", i + 1);

		j = 0;
		while (1) {
			if (*(data[i] + j) >= 0) {
				printf("  %3d", *(data[i] + j));
			}
			else break;
			j++;
		}

		printf("\n");
	}
}

