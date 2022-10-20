#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char lowerTolpper(char);
int main() {
	char ch;

	printf("Enter one character to change to uppercase letter : ");
	scanf("%c", &ch);
	int result = lowerTolpper(ch);
	printf("result : %c\n", result);

	return 0;
}

char lowerTolpper(char ch) {
	if (ch >= 'a' && ch <= 'z') {
		ch -= 32;
		return ch;
	}
	else {
		return ch;
	}
}