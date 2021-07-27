// C Function that Clears Bit in a Given Number

#include "stdio.h"

int Clear_Specified_Bit(int n, int bit);

void main()
{
	int n, bit;

	printf("Enter a number : ");
	scanf("%d", &n);

	printf("Enter position of the bit that you want to clear : ");
	scanf("%d", &bit);

	printf("Result = %d", Clear_Specified_Bit(n, bit));
}

int Clear_Specified_Bit(int n, int bit)
{
	return n &= ~ (1 << bit);
}
