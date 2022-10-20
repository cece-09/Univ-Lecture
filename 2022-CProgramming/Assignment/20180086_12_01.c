#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct pointer
{
	double x;
	double y;
};
typedef struct pointer POINTER;

double pointer_dist(POINTER*, POINTER*); //거리 구하는 함수

int main()
{
	int num, i;
	double dist;
	printf("Number of input data? ");
	scanf("%d", &num);

	POINTER* strP = (POINTER *)malloc(sizeof(POINTER) * num); //구조체 동적할당
	if (strP == NULL)
	{
		printf("not allocated\n");
		return 1;
	}

	//입력
	for (i = 0; i < num; i++)
	{
		printf("%d - Enter x, y coordinate values : ", i + 1);
		scanf("%lf %lf", &(strP[i].x), &(strP[i].y));
	}

	//출력
	POINTER* tmp1;
	POINTER* tmp2;
	int a, b;
	printf("*********************************************************************\n");
	for (i = 0; i < (num / 2); i++)
	{
		a = i * 2;
		b = (i * 2) + 1;
		tmp1 = strP + a;
		tmp2 = strP + b;
		dist = pointer_dist(tmp1, tmp2);
		printf("The distance between (%.2lf, %.2lf) and (%.2lf, %.2lf) pointers : %.2lf\n", strP[i * 2].x, strP[i * 2].y, strP[i * 2 + 1].x, strP[i * 2 + 1].y, dist);
	}

	free(strP);
	return 0;
}

//거리 구하기
double pointer_dist(POINTER* p1, POINTER* p2)
{
	double a = p1->x;
	double b = p1->y;
	double c = p2->x;
	double d = p2->y;

	double dist = sqrt(pow((a - c), 2) + pow((b - d), 2));
	return dist;
}