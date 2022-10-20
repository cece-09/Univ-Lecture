#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Unions are ...
// fields that share memory space;
// only one field of unoin is active at any given time
// ���� �޸� ������ share �ϹǷ�, �ѹ��� �� ����� ����Ѵ�.

typedef struct {
	enum tagField {pitcher, hitter} role; // pitcher�ΰ� hitter�ΰ�
	union {
		int SO;
		int HR;
	}u;
}playerType; // playerType�� u���� �� �� �ϳ����� ���� ����

typedef struct {
	char name[10];
	int age;
	float salary;
	//date dob; date �ڷ���?
	playerType playerInfo;
} baseballPlayer;

