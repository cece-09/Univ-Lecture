#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[10];
	int age;
	float salary;
}humanBeing;
int humans_equal(humanBeing, humanBeing);

int main() {
	humanBeing per1, per2;
	
	printf("Enter the per1 info(name, age, salary: ");
	scanf("%s %d %f", &(per1.name), &(per1.age), &(per1.salary));
	printf("Enter the per2 info(name, age, salary: ");
	scanf("%s %d %f", &(per2.name), &(per2.age), &(per2.salary));

	int checkEqual = humans_equal(per1, per2);
	if (checkEqual == true)
		printf("The two human beings are same.\n");
	else
		printf("The two human beings are not the same.\n");
	
	return 0;
}

int humans_equal(humanBeing per1, humanBeing per2) {
	/* return TRUE is per1 and per2 are the same human being */
	if (strcmp(per1.name, per2.name))
		return false;
	if (per1.age != per2.age)
		return false;
	if (per1.salary != per2.salary)
		return false;
	return true;
}