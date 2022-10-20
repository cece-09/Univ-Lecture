#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 100

typedef struct {
	int coef;  // ���� ���
	int expon; // ���� ����
} polynomial;

void padd(int, int, int, int, int*, int*);
int compare(int, int);
void attach(int, int);

polynomial terms[MAX_TERMS]; // �� ���� ���ҷ� �ϴ� ���׽� �迭
int avail = 0; // ������ ���� �˷��ִ� �ε���
int start[100];
int finish[100];

int main() {
	//store terms array via cmd entry
	int cnt = 0;  // ���׽��� ����
	int i   = 0;
	while (1) {
		int termN;
		printf("Store the %d th polynomial.\n", cnt + 1);
		printf("Enter the number of terms: ");
		scanf("%d", &termN);
		if (termN == -1)
			break;

		start[cnt]  = i;          //���� �ε���
		finish[cnt] = i + termN - 1;  //�� �ε���
		avail = finish[cnt] + 1;

		for (int j = start[cnt]; j <= finish[cnt]; j++) {
			printf("Enter the term's info(coef, expon): ");
			scanf("%d %d", &(terms[j].coef), &(terms[j].expon));
			i++;
		}
		cnt++;
	}

	padd(start[0], finish[0], start[1], finish[1], &(start[3]), &(finish[3]));

	return 0;
}

int compare(int a, int b) {
	if (a > b)
		return 1;
	if (a = b)
		return 0;
	if (a < b)
		return -1;
}

void attach(int coefficient, int exponent) {
	/* add a new term to the polynomial */
	if (avail >= MAX_TERMS) {
		printf("too many terms in the polynomial"); exit(1); 
	} // �߰��Ϸ��µ� max ũ�⸦ ���� ��� ���� ����

	terms[avail].coef = coefficient;
	terms[avail++].expon = exponent;
}

void padd(
	int starta,   // poly a �� ���� index
	int finisha,  // poly a �� ���� index
	int startb,   // poly b �� ���� index
	int finishb,  // poly b �� ���� index
	int* startd,  // poly d �� ���� index pointer, d = result
	int* finishd  // poly d �� ���� index pointer, d = result
) {
	float coefficeint;
	*startd = avail; // = avail
	while (starta <= finisha && startb <= finishb) {
		switch (compare(terms[starta].expon, terms[startb].expon))
		{
		case -1: // a.expon < b.expon
			attach(terms[startb].coef, terms[startb].expon);
			startb++;
			break;
		case 0: // equal exponents
			coefficeint = terms[starta].coef + terms[startb].coef;
			if (coefficeint) attach(coefficeint, terms[starta].expon);
			starta++; startb++;
			break;
		case 1: // a.expon > b.expon
			attach(terms[starta].coef, terms[starta].expon);
			starta++;
			break;
		}
	}
	// add remaining terms of A
	for (; starta <= finisha; starta++)
		attach(terms[starta].coef, terms[starta].expon);
	// add remaining terms of B
	for (; startb <= finishb; startb++)
		attach(terms[startb].coef, terms[startb].expon);

	*finishd = avail - 1;
}