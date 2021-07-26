// C Function to print all prime numbers between two numbers

#include "stdio.h"

void Print_Prime_Numbers(int n1, int n2);

int main()
{
	int num1, num2;
	printf("Enter two numbers: ");
	scanf("%d\n%d", &num1, &num2);

       Print_Prime_Numbers(num1, num2);

	return 0;
}

void Print_Prime_Numbers(int n1, int n2)
{
	int i, j;
	for(i = n1; i <= n2; i++)
	{
		for(j = 2; j <= i; j++)
		{
			if(i % j == 0)
				break;
		}
		if(i == j)
			printf("%d", i);
	}
}
