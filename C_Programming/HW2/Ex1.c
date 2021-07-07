// C program to check if the number is even or odd

#include "stdio.h"

void main()
{
	int num;
	printf("Enter an integer you want to check: ");
	scanf("%d", &num);

	if (num % 2 == 1)
		printf("%d is odd", num);
	else if (num == 0)
		printf("%d neither even neither odd", num);
	else if (num % 2 == 0)
		printf("%d is even", num);
}
