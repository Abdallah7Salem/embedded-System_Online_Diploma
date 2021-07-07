// C Program to Calculate Factorial of a number

#include "stdio.h"

void main()
{
	int n,i;
	printf("Enter an integer: ");
	scanf("%d", &n);
	
	if(n < 0)
		printf("Error!!! Factorial of Negative number doesn't exist.");
	else if(n == 0)
		printf("Factorial = 1");
	else if(n > 0)
	{
	int F = 1;
	for(i = n; i > 0; i--)
	{
		F = F * n;
		n = n - 1;
	}
	printf("Factorial = %d", F);
	}
	else
		printf("You entered an invalid number");
}