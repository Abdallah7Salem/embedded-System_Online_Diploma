// C Function to count number of ones in binary number

#include "stdio.h"

int Number_Of_Ones(int num);

void main()
{
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);

	printf("%d", Number_Of_Ones(n));

}

int Number_Of_Ones(int num)
{
	int sum = 0;

	while(num > 0)
	{
		sum += num & 1;
		num = num >> 1;
	}

	return sum;
}
