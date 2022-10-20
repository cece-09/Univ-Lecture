#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_DEGREE 101 // 최고차항의 차수

// dense representation
typedef struct {
	int degree;
	int coef[MAX_DEGREE];
}polynomial;

int main() {
	int d;
	polynomial poly;

	printf("Enter the max degree: ");
	scanf("%d", &d);
	poly.degree = d;

	for (int i = 0; i <= d; i++) {
		printf("Enter the coefficient of %d degree term: ", i);
		scanf("%d", &(poly.coef[i]));
	}
	for (int i = d; i >= 0; i--) {
		printf("%+dx^%d ", poly.coef[i], i);
	}

	return 0;
}