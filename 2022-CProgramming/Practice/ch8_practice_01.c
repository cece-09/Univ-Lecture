#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



int main(void) {
	int a = 100;
	int* ptr = &a;
	printf("a: %d\n", a);
	printf("*ptr: %d\n", *ptr);
	printf("&a: %p\n", &a);
	printf("prt: %p\n", ptr);
	(*ptr)++;
	printf("%d\n", a);
	printf("%d\n", *ptr);

}

