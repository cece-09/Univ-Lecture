#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int i;
	int n;
	int m;
	int* data;
	// malloc
	printf("How may integers do you want to generate? ");
	scanf("%d", &n);
	data = (int*)malloc(n * sizeof(int));
	if (data == NULL) exit(-1);
	for (i = 0; i < n; i++)data[i] = rand();

	// realloc
	printf("How may integers do you want to generate additionally? ");
	scanf("%d", &m);
	data = (int*)realloc(data, (n + m) * sizeof(int));
	if (data == NULL) exit(-1);
	for (i = n; i < (n + m); i++)data[i] = rand(); // n th index 부터 다시 쓰기 시작

	// printf
	for (i = 0; i < (n + m); i++) printf("%3d : %8d\n", i + 1, data[i]);

	free(data);
	return 0;
}