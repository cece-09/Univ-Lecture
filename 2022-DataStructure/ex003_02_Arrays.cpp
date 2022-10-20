#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Program 2.2
// print1 is a function that prints out
// both the address of the i th element
// and the value found at this address

void print1(int*, int);

int main() {
	int one[] = { 0, 1, 2, 3, 4 };
	print1(one, 5);
	return 0;
}

void print1(int* ptr, int rows) {
	/* print our a one-dimensional array using a pointer */
	int i;
	printf("address contents\n");
	for (i = 0; i < rows; i++) {
		printf("%8p%5d\n", ptr + i, *(ptr + i)); // print the address and value
	}
	printf("\n");
}