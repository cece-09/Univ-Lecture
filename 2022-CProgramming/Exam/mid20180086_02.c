#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int intersection(int[], int, int[], int, int[]);
void print_Set(int[], int);

int main() {
	int A[] = { 1,3,5,7,9,10 };
	int B[] = { 3,5,8,9 };
	int R[3] = { 0 };

	int numA = sizeof(A) / sizeof(A[0]);
	int numB = sizeof(B) / sizeof(B[0]);
	int numR = intersection(A, numA, B, numB, R);

	printf("********** Set A *********\n"); print_Set(A, numA);
	printf("********** Set A *********\n"); print_Set(B, numB);
	printf("********** Set A *********\n"); print_Set(R, numR);
}

int intersection(int A[], int numA, int B[], int numB, int R[]) {
	int i, j;
	int count = 0;

	for (i = 0; i < numA; i++) {
		for (j = 0; j < numB; j++) {
			if (A[i] == B[j]) {
				R[count] = A[i];
				count++;
			}
			else {
				continue;
			}
		}
	}

	int numR = count;
	return numR;
}

void print_Set(int S[], int num) {

	int i;
	printf("{");
	for (i = 0; i < num; i++) {
		if (i == 0) {
			printf("%3d", S[i]);
		}
		else {
			printf(",%3d", S[i]);

		}
	}
	printf("}\n");
}