// C Program for Swapping 2 Arrays with Different Lengths

#include "stdio.h"

void main()
{
	int a[10], b[10], c[10];
	int i;

	printf("Enter first array: ");
	for(i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}

	printf("Enter second array: ");
	for(i = 0; i < 7; i++)
	{
		scanf("%d", &b[i]);
	}

	printf("Array 1 before swapping: ");
	for(i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}

	printf("\nArray 2 before swapping: ");
	for(i = 0; i < 7; i++)
	{
		printf("%d ", b[i]);
	}

	for(i = 0; i < 10; i++)
	{
		c[i] = a[i];
		a[i] = b[i];
		b[i] = c[i];
	}

	printf("\n***********************");

	printf("\nArray 1 after swapping: ");
	for(i = 0; i<7; i++)
	{
		printf("%d ", a[i]);
	}

	printf("\nArray 2 after swapping: ");
	for(i = 0; i < 10; i++)
	{
		printf("%d ", b[i]);
	}

}
