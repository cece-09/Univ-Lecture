#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int searchWord(char* str1, char* str2);

int main() {

	char** data;                                 //��ü ���ڿ�
	int size = 5;                                //���ڿ� ����
	char search[21];                             //�˻��� ���ڿ�, �ִ���� 20 + 1 (\0)

	data = (char**)malloc(size * sizeof(char*));
	if (data == NULL) {
		printf("not allocated\n");
		exit(1);
	}

	int i;
	for (i = 0; i < size; i++) {
		char tmp[51];

		printf("Enter %dth sentence : ", i + 1);
		gets_s(tmp, 51);

		data[i] = (char*)malloc(strlen(tmp) + 1); //�Էµ� ���� + \0��ŭ �޸� �Ҵ�
		if (data[i] == NULL) {
			printf("not allocated\n");
			exit(1);
		}
		strcpy(data[i], tmp);

	}

	printf("\n*****************************\n");    //�Է��� ���� ���
	for (i = 0; i < size; i++) {
		printf("%d : %s\n", i + 1, data[i]);
	}

	printf("*****************************\n");
	printf("Enter the word you want to find : ");
	scanf("%s", search);


	int searchResult = 0;
	for (i = 0; i < size; i++) {

		searchResult = searchWord(data[i], search);
		printf("%d sentence : %d times found\n", i + 1, searchResult);
	}


	//�޸� �Ҵ� ����
	i = 0;
	while (i < size) {
		free(data[i]);
		i++;
	}
	free(data);

	return 0;
}


//�� ���忡�� keyword�� ��ġ�ϴ� �ܾ� ���� ��ȯ�ϴ� �Լ�
int searchWord(char* data, char* keyword) {
	int result = 0;
	int compare = 0;
	char* delimiters = " \n";
	char* word = strtok(data, delimiters);

	int i = 0;
	while (word != NULL)
	{
		compare = strcmp(word, keyword);
		if (compare == 0)
		{
			result++;
		}

		word = strtok(NULL, delimiters);
		i++;
	}

	return result;
}

