// C Function to reverse digits in number

#include "stdio.h"

int Reverse_Number_Digits(int num);

void main()
{
	int n;
	printf("Enter a number: ");
	fflush(stdout);
	scanf("%d", &n);
	fflush(stdin);

	printf("%d", Reverse_Num_Digits(n));
}


int Reverse_Num_Digits(int num)
{
	int m, rev = 0;

	while(num != 0)
	{
		m = num % 10;
		rev = (rev * 10) + m;
		num = num / 10;

	}

	return rev;
}
