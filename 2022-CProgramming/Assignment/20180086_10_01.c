#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int searchWord(char* str1, char* str2);

int main() {

	char** data;                                 //전체 문자열
	int size = 5;                                //문자열 개수
	char search[21];                             //검색할 문자열, 최대길이 20 + 1 (\0)

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

		data[i] = (char*)malloc(strlen(tmp) + 1); //입력된 길이 + \0만큼 메모리 할당
		if (data[i] == NULL) {
			printf("not allocated\n");
			exit(1);
		}
		strcpy(data[i], tmp);

	}

	printf("\n*****************************\n");    //입력한 문장 출력
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


	//메모리 할당 해제
	i = 0;
	while (i < size) {
		free(data[i]);
		i++;
	}
	free(data);

	return 0;
}


//한 문장에서 keyword와 일치하는 단어 수를 반환하는 함수
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

