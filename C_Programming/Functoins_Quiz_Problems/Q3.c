// C Function that Reverse an Input Array

#include "stdio.h"

void Reverse_Array(int size, int a[], int b[]);

void main()
{
	int a[100], b[100], i, size;

	printf("Enter the size of the array: ");
	scanf("%d", &size);

	for(i = 0; i < size; i++)
	{
		printf("Enter element %d : ", i+1);
		scanf("%d", &a[i]);
	}

	Reverse_Array(size, a, b);
}

void Reverse_Array(int size, int a[], int b[])
{
	int i, j;
	for(i = size-1, j = 0; i >= 0; i--, j++)
		b[j] = a[i];
	printf("The reverse of the array is : ");

	for(i = 0; i < size; i++)
	{
		printf("%d ", b[i]);
	}
}
