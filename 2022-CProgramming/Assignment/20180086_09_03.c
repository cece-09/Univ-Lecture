#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void data_prn(int, int**);

int main() {
	int classNum;
	int** data;
	printf("Enter number of class : ");
	scanf("%d", &classNum);
	data = (int**)malloc(classNum * sizeof(int*));                          //포인터 배열의 동적 할당
	if (data == NULL) {
		printf("not allocated\n");
		exit(1);
	}                                                                       //malloc 예외처리

	int i = 0;
	while (i < classNum) {

		int studentNum = 0;                                                //size를 0으로 초기화
		data[i] = (int*)malloc(0);                                         //size를 0으로 초기화
		if (data[i] == NULL) {
			printf("not allocated\n");
			exit(1);
		}                                                                  //malloc 예외처리

		printf("**** Inputing %d class scores ****\n", i + 1);

		int j = 0;
		int tmp;
		int* tmpArr;
		while (1) {
			printf("Enter the score %d : ", j + 1);
			scanf("%d", &tmp);

			if (tmp < 0) break;                                           //음수가 입력되면 종료

			studentNum = j + 1;
			tmpArr = (int*)realloc(data[i], studentNum * sizeof(int));   //데이터 입력할 때 마다 size를 1씩 늘려가며 할당
			if (tmpArr == NULL) {
				printf("not allocated\n");
				exit(1);
			}                                                            //realloc 예외처리  
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

	data_prn(classNum, data);                                           //출력 함수로 출력

	i = 0;
	while (i < classNum) {                                              //메모리 해제
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

