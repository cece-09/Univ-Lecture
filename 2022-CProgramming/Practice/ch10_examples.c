#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//27-28page ¿¹Á¦

void str_prn(int, char**);

int main() {
	char tmp[80];
	char** str;
	int max, i;

	printf("Number of string : ");
	scanf("%d", &max);

	str = (char**)malloc(max * sizeof(char*));
	if (str == NULL) {
		printf("not allocated\n");
		exit(1);
	}
	i = 0;
	while (i)
	{
		printf("Enter string : ");
		scanf("%s", tmp);
		str[i] = (char*)malloc(strlen(tmp) + 1);
		if (str[i] == NULL) {
			printf("not allocated\n");
			exit(1);
		}
		strcpy(str[i], tmp);
		i++;

		if (i == max)
		{
			break;
		}		
	}

	str_prn(max, str);

	i = 0;
	while (i < max)
	{
		free(str[i]);
		i++;
	}
	free(str);

	return 0;
}

void str_prn(int n, char** p_str)
{
	int i;
	printf("********** String List ************\n");
	for (i = 0; i < n; i++) {
		printf("%d : %s\n", i, *(p_str + i));
	}
}