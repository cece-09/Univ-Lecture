#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isSame(int, int);                    //isSame() 함수 선언

int main()
{
	int randnum;
	int usernum;
	int result;

	srand((unsigned)time(NULL));
	randnum = rand() % 51;              //난수 생성

	printf("The random number is %d\n", randnum);
	printf("****************************************************\n");
	printf("Enter the sum of the divisions : ");
	scanf("%d", &usernum);              //정수 입력받아 usernum에 저장

	result = isSame(randnum, usernum);  //isSame() 함수 호출

	if (result == 1)
		printf("The sum of the divisions of %d is equal to %d\n", randnum, usernum);
	else
		printf("Not equal\n");          //결과 출력

	return 0;
}

int isSame(int randnum, int usernum)   //isSame() 함수 정의
{
	int sum = 0;
	int i;

	for (i = 1; i <= randnum; i++)
		if ((randnum % i) == 0)
			sum += i;                  //randnum의 약수 합 구하기

	if (sum == usernum)
		return 1;
	else
		return 0;                      //약수 합과 일치하면 1, 불일치하면 0 반환
}