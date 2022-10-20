#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 20

int input_Set(int*, char);
int intersection(int*, int, int*, int, int*);
int difference(int*, int, int*, int, int*);
void print_Set(int*, int);

int main() {
	int A[SIZE] = { 0 };
	int B[SIZE] = { 0 };
	int inter[SIZE] = { 0 };
	int differ[SIZE] = { 0 };

	printf("************** Inputing Set A ***************\n");
	int sizeA = input_Set(A, 'A');
	printf("************** Inputing Set B ***************\n");
	int sizeB = input_Set(B, 'B');
	printf("************** Set A ***************\n");
	print_Set(A, sizeA);
	printf("************** Set B ***************\n");
	print_Set(B, sizeB);

	printf("************** Intersection(A, B) ***************\n");
	int sizeInter = intersection(A, sizeA, B, sizeB, inter);
	print_Set(inter, sizeInter);

	printf("************** Difference(A, B) ***************\n");
	int sizeDiffer = difference(A, sizeA, B, sizeB, differ);
	print_Set(differ, sizeDiffer);

	return 0;
}

//�Է� �޴� �Լ�
int input_Set(int* S, char sName) {
	int i, tmp;
	int count = 0;

	for (i = 0; i < SIZE; i++) {
		printf("Enter element of %c Set [%d] : ", sName, i);
		scanf("%d", &tmp);

		if (tmp <= 0) {
			break;
		}

		*(S + i) = tmp;
		count++;
	}

	return count;
}

//������ ���ϱ�
int intersection(int* A, int sizeA, int* B, int sizeB, int* R) {
	int i, j;
	int count = 0;

	for (i = 0; i < sizeA; i++) {
		for (j = 0; j < sizeB; j++) {
			if (*(A + i) == *(B + j)) {
				*(R + count) = *(A + i);
				count++;
			}
		}
	}
	
	return count;
}

//������ ���ϱ�
int difference(int* A, int sizeA, int* B, int sizeB, int* R) {
	int i, j;
	int count = 0;
	
	for (i = 0; i < sizeA; i++) {
		int chkMatch = 0; //��ġ�ϸ� 1, ��ġ���� ������ 0
		for (j = 0; j < sizeB; j++) {
			if (*(A + i) == *(B + j)) { //��ġ�ϸ� chkMatch�� 1�� ����� break
				chkMatch = 1;
				break;
			}			
		}
		if (chkMatch == 0) {  //��ġ���� ���� ��쿡 ���� R�迭�� ����
			*(R + count) = *(A + i);
			count++;
		}		
	}

	return count;
}

//����ϴ� �Լ�
void print_Set(int* S, int sSize) {
	int i;
	printf("{"); 
	for (i = 0; i < sSize; i++) {
		if (i == 0) {
			printf("%3d", *S); //ù ��° ���� ���
		}
		else {
			printf(",%3d", *(S + i));
		}
	}
	printf("}\n");
}