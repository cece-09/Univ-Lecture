#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 101


// This function implementation has a 
// POTENTIAL PROBLEM. Identify and fix it.
void strnins(char*, char*, int);

int main() {
	char s[] = "hellworld";
	char t[] = "o";

	strnins(s, t, 4);
	printf("%s\n", s);
	return 0;
}

void strnins(char* s, char* t, int i) {
	/* insert string t into string s at point i */
	char string[MAX_SIZE] = { 0 };
	char* temp = string;

	if (i < 0 && i > strlen(s)) {
		fprintf(stderr, "position is out of bounds.\n"); exit(1);
	}

	// fix the problem
	s = (char*)realloc(s, sizeof(s) + sizeof(t) + 1);
	printf("%s", s);

	if (!strlen(s)) strcpy(s, t); // s�� �� ���ڿ� �̸�, s�� t�� ����
	else if (strlen(t)) {         // �׷��� ������ ..
		strncpy(temp, s, i);      // temp�� i��° index���� s����      h e l l 0 0 0 0 0 0
		strcat(temp, t);          // temp�� t�� ���̱�                h e l l o 0 0 0 0 0
		strcat(temp, (s + i));    // temp�� s�� i��° ���� ���̱�      h e l l o w o r l d
		strcpy(s, temp);          // s�� temp ���� - need memory realloc!	
	}
}