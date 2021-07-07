// C Program to Calculate Sum of Natural Numbers

#include "stdio.h"

void main()
{
	int n,i;
	printf("Enter an integer: ");
	scanf("%d", &n);
	
	int sum = 0;
	for(i = n; i > 0; i--)
	{
		sum = sum + n;
		n = n - 1;
	}
	printf("Sum = %d", sum);
}