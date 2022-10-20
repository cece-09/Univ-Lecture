#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING 9999999
#define MAX_PATTERN 2999

/* definition area */
char S[MAX_STRING]  = { '\n' };
char P[MAX_PATTERN] = { '\n' };

void failure(char P[], int T[]);
void pattern_matching_kmp(char* S, char* P, int* T);

/* main function */
int main() {

	FILE* fp_string = fopen("string.txt", "r");
	FILE* fp_pattern = fopen("pattern.txt", "r");

	fgets(S, MAX_STRING, fp_string);
	fgets(P, MAX_PATTERN, fp_pattern);

	//create failure func array
	int pat_size = strlen(P);
	int* T = (int*)malloc(sizeof(int) * pat_size);
	if (T == NULL) exit(1);

	//execute failure and pattern matching function
	failure(P, T);
	pattern_matching_kmp(S, P, T);

	//free and fclose
	free(T);
	fclose(fp_string);
	fclose(fp_pattern);
	return 0;
}

/* failure function declaration */
void failure(char P[], int T[])
{
	int n = strlen(P);

	T[0] = -1;
	int i = T[0];

	for (int j = 1; j < n; j++)
	{
		i = T[j - 1];
		while (P[j] != P[i + 1] && i >= 0)
		{
			i = T[i];
		}

		if (P[j] == P[i + 1])
		{
			T[j] = i + 1;
		}
		else
		{
			T[j] = -1;
		}
	}
}

/* pattern matching function declaration */
void pattern_matching_kmp(char* S, char* P, int* T)
{
	FILE* fp_result = fopen("result_kmp.txt", "w");

	int i = 0;
	int j = 0;
	int cnt = 0;

	int m = strlen(S);
	int n = strlen(P);

	//initailize result array
	int size = 1260;
	int* R = (int*)calloc(sizeof(int), size);
	if (R == NULL){
		printf("not allocated\n"); exit(1);
	}

	while (i < m)
	{
		if (S[i] == P[j])
		{
			//첫글자 일치 시 다음 매칭으로
			i++; j++;
		}
		else if (j == 0)
		{
			//첫글자 불일치 다음 문자 비교 
			i++;
		}
		else
		{
			//첫글자 이후 불일치 발견!
			j = T[j - 1] + 1;
		}

		if (j == n)
		{
			if (cnt >= size)
			{
				size++;
				R = (int*)realloc(R, sizeof(int) * size);
				if (R == NULL) {
					printf("not allocated\n"); exit(1);
				}
			}

			R[cnt] = i - n;
			cnt++;
		}
	}

	fprintf(fp_result, "%d\n", cnt);
	for (int i = 0; i < cnt; i++)
	{
		fprintf(fp_result, "%d ", R[i]);
	}

	free(R);
	fclose(fp_result);
	printf("Program complete. Result saved to result_kmp.txt\n");
}