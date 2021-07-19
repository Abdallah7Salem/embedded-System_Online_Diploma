// C Program to Find Prime Numbers Between two intervals by Making User-defined Function

#include "stdio.h"

void Prime_Num(int start, int end);

void main()
{
	int num1, num2;
	printf("Enter two numbers(intervals): ");
	scanf("%d\n%d", &num1, &num2);

	Prime_Num(num1, num2);

}

void Prime_Num(int start, int end)
{
	int i, j;
	printf("Prime numbers between %d and %d are: ", start, end);
	for(i = start; i < end; i++)
	{
		for(j = 2; j < end; j++)
		{
			if(i % j == 0)
			{
				break;
			}
		}

		if(i == j)
		{
			printf("%d ", i);
		}
	}


}
