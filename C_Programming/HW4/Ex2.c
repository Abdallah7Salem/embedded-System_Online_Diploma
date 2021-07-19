// C program to Calculate Factorial of a Number Using recursion

#include "stdio.h"

int Factorial(int num);

void main()
{
	int n;
	printf("Enter a positive integer: ");
	scanf("%d", &n);
	
	printf("Factorial of %d = %d", n, Factorial(n));
}

int Factorial(int num)
{
    if (num >= 1)
    {
    	return num * Factorial(num - 1);
    }
    else
    	return 1;
}

