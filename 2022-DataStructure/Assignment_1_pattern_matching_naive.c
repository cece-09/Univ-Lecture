#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING 9999999
#define MAX_PATTERN 2999

void pattern_matching_naive(char*, char*);

char S[MAX_STRING];
char P[MAX_PATTERN];

int main() {	

	FILE* fp_string = fopen("string.txt", "r");
	if (fp_string == NULL) {
		//there is no string file
		printf("there is no string file\n");
		return 0;
	}
	else {
		fgets(S, MAX_STRING, fp_string);
	}

	FILE* fp_pattern = fopen("pattern.txt", "r");
	if (fp_pattern == NULL) {
		//there is no pattern file
		printf("there is no pattern file\n");
		return 0;
	}
	else {
		fgets(P, MAX_PATTERN, fp_pattern);
	}

	pattern_matching_naive(S, P);
	
	fclose(fp_string);
	fclose(fp_pattern);

	return 0;
}

void pattern_matching_naive(char* T, char* P) {

	FILE* fp_result = fopen("result_naive.txt", "w");

	//initialize the Result array
	int size = 1260;
	int* R = (int*)calloc(sizeof(int), size);
	if (R == NULL) {
		printf("not allocated\n");
		exit(1);
	}

	int M = strlen(P);
	int N = strlen(T);
	int cnt = 0;  //number of pattern matching case
	
	for (int i = 0; i <= N - M; i++) {
		int j;

		for (j = 0; j < M; j++) {
			if (T[i + j] != P[j]) {
				break;
			}
		}

		if (j == M) {
			if (cnt >= size) {
				size++;
				R = (int*)realloc(R, sizeof(int) * size);
				if (R == NULL) {
					printf("not allocated\n");
					exit(1);
				}
			}
			R[cnt] = i;
			cnt++;
		}
	}

	fprintf(fp_result, "%d\n", cnt);
	for (int i = 0; i < cnt; i++) {
		fprintf(fp_result, "%d ", R[i]);
	}
	printf("Program complete. Result saved to result_naive.txt\n");

	//free the R array and close file
	free(R);
	fclose(fp_result);
	return;
}