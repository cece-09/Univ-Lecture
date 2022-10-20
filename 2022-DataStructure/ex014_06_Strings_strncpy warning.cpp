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

	if (!strlen(s)) strcpy(s, t); // s가 빈 문자열 이면, s에 t를 복사
	else if (strlen(t)) {         // 그렇지 않으면 ..
		strncpy(temp, s, i);      // temp의 i번째 index까지 s복사      h e l l 0 0 0 0 0 0
		strcat(temp, t);          // temp에 t를 붙이기                h e l l o 0 0 0 0 0
		strcat(temp, (s + i));    // temp에 s의 i번째 문자 붙이기      h e l l o w o r l d
		strcpy(s, temp);          // s에 temp 복사 - need memory realloc!	
	}
}