#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	int x, y;

	printf("Enter variable x : ");
	scanf("%d", &x);
	printf("Enter variable y : ");
	scanf("%d", &y);
	
	double result1 = pow(x, 2) + pow(y, 2);
	double result2 = pow((x + y), 2);
	double result3 = pow(fabs(x + y), 2);
	double result4 = sqrt(pow(x, 2) + pow(y, 2));

	printf("Result of expression 1 is %.2lf\n", result1);
	printf("Result of expression 2 is %.2lf\n", result2);
	printf("Result of expression 3 is %.2lf\n", result3);
	printf("Result of expression 4 is %.2lf\n", result4);

	return 0;
}