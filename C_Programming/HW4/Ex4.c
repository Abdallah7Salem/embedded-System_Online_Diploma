// C Program to Calculate the Power of a Number Using Recursion

#include "stdio.h"

int Power_Function(int a, int b);

int main()
{
	int x, y;
	printf("Enter base number: ");
	scanf("%d", &x);
	printf("Enter power number(positive integer) : ");
	scanf("%d", &y);
	Power_Function(x, y);
	printf("%d^%d = %d", x, y, Power_Function(x, y));

	return 0;
}

int Power_Function(int a, int b)
{
	if(b != 0)
		return (a * Power_Function(a, b - 1));
	else
		return 1;
}
