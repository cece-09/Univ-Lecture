#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Unions are ...
// fields that share memory space;
// only one field of unoin is active at any given time
// 같은 메모리 공간을 share 하므로, 한번에 한 멤버만 사용한다.

typedef struct {
	enum tagField {pitcher, hitter} role; // pitcher인가 hitter인가
	union {
		int SO;
		int HR;
	}u;
}playerType; // playerType의 u에는 둘 중 하나에만 저장 가능

typedef struct {
	char name[10];
	int age;
	float salary;
	//date dob; date 자료형?
	playerType playerInfo;
} baseballPlayer;

