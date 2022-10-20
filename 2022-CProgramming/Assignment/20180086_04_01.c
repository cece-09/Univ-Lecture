#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isSame(int, int);                    //isSame() �Լ� ����

int main()
{
	int randnum;
	int usernum;
	int result;

	srand((unsigned)time(NULL));
	randnum = rand() % 51;              //���� ����

	printf("The random number is %d\n", randnum);
	printf("****************************************************\n");
	printf("Enter the sum of the divisions : ");
	scanf("%d", &usernum);              //���� �Է¹޾� usernum�� ����

	result = isSame(randnum, usernum);  //isSame() �Լ� ȣ��

	if (result == 1)
		printf("The sum of the divisions of %d is equal to %d\n", randnum, usernum);
	else
		printf("Not equal\n");          //��� ���

	return 0;
}

int isSame(int randnum, int usernum)   //isSame() �Լ� ����
{
	int sum = 0;
	int i;

	for (i = 1; i <= randnum; i++)
		if ((randnum % i) == 0)
			sum += i;                  //randnum�� ��� �� ���ϱ�

	if (sum == usernum)
		return 1;
	else
		return 0;                      //��� �հ� ��ġ�ϸ� 1, ����ġ�ϸ� 0 ��ȯ
}