#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char var;      //변수 할당식 변수
	int value;     //변수 할당값
	char oper;     //수식 연산자
	int num;       //수식 연산값
	char tmp;      //연산식 변수 == 할당식 변수 체크

	printf("*************************************************************\n");
	printf("Enter variable assignment(ex: a = 314) : ");
	scanf("%c = %d", &var, &value);                                                                    //변수 할당식 입력 받기

	rewind(stdin);                                                                                     //초기화
	
	printf("**************************************************************\n");
	printf("Enter a math expression using variable(ex: a + 10) : ");
	scanf("%c %c %d", &tmp, &oper, &num);                                                              //연산식 입력 받기

	if (tmp != var) {
		printf("Only use defined variable!\n");
		return 1;                                                                                      //할당식에서 입력한 변수가 아닐 경우 예외처리
	}

	switch (oper) {                                                                                    //각 연산자 계산 & 결과 출력
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
			printf("Can't be divided int zero\n");                                                  //0으로 나누면 오류
			break;
		}

		printf("\n>>>>>>> Result : %c / %d = %.2lf\n", var, num, value / (double) num);            //소수점 이하 두 자리까지 출력
		break;
	default:
		printf("%c is unacceptable operator\n", oper);                                            //허용하지 않는 연산자의 경우 예외처리
	}

	return 0;
}