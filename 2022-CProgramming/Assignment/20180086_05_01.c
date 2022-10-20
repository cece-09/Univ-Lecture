#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char var;      //���� �Ҵ�� ����
	int value;     //���� �Ҵ簪
	char oper;     //���� ������
	int num;       //���� ���갪
	char tmp;      //����� ���� == �Ҵ�� ���� üũ

	printf("*************************************************************\n");
	printf("Enter variable assignment(ex: a = 314) : ");
	scanf("%c = %d", &var, &value);                                                                    //���� �Ҵ�� �Է� �ޱ�

	rewind(stdin);                                                                                     //�ʱ�ȭ
	
	printf("**************************************************************\n");
	printf("Enter a math expression using variable(ex: a + 10) : ");
	scanf("%c %c %d", &tmp, &oper, &num);                                                              //����� �Է� �ޱ�

	if (tmp != var) {
		printf("Only use defined variable!\n");
		return 1;                                                                                      //�Ҵ�Ŀ��� �Է��� ������ �ƴ� ��� ����ó��
	}

	switch (oper) {                                                                                    //�� ������ ��� & ��� ���
	case '+':
		printf("\n>>>>>>> Result : %c + %d = %d\n", var, num, value + num);
		break;
	case '-':
		printf("\n>>>>>>> Result : %c - %d = %d\n", var, num, value - num);
		break;
	case '*':
		printf("\n>>>>>>> Result : %c * %d = %d\n", var, num, value * num);
		break;
	case '/':

		if (num == 0) {
			printf("Can't be divided int zero\n");                                                  //0���� ������ ����
			break;
		}

		printf("\n>>>>>>> Result : %c / %d = %.2lf\n", var, num, value / (double) num);            //�Ҽ��� ���� �� �ڸ����� ���
		break;
	default:
		printf("%c is unacceptable operator\n", oper);                                            //������� �ʴ� �������� ��� ����ó��
	}

	return 0;
}