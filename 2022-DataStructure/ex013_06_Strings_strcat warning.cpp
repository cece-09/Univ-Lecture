#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// what is the problem with this code?
int main() {
	char s[] = "dog";
	char t[] = "house";
	char u[] = "rainbow";
	printf("%s\n", s);
	printf("%s\n", t);
	printf("%s\n\n", u);
	
	strcat(s, u);  // s�� ���� ���� ���� �������� �߻��Ѵ�.
	printf("%s\n", s);
	printf("%s\n", t);

	return 0;
}