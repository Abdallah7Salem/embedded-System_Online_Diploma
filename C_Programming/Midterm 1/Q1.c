// C Function to take a number and sum all digits

int Digits_Summer(int num);

#include "stdio.h"

void main()
{
	int n;
	printf("Please enter a number: ");
	scanf("%d", &n);

	printf("Output: %d", Digits_Summer(n));
}

int Digits_Summer(int num)
{
	int sum = 0;
	while(num != 0)
	{
		sum += num % 10;
		num = num / 10;
	}

	return sum;
}
