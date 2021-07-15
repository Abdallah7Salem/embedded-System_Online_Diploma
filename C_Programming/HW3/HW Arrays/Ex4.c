// C Program to Insert an element in an Array

#include "stdio.h"

void main()
{
	int num = 0;
	printf("Enter no of elements : ");
	scanf("%d", &num);

	int arr[7], i;
	for(i = 0; i < num; i++)
	{
		scanf("%d", &arr[i]);
	}

	int element;
	printf("Enter the element to be inserted : ");
	scanf("%d", &element);

	int loc;
	printf("Enter the location : ");
	scanf("%d", &loc);

	// This is the most important loop to make the insertion process work
	for(i = num; i >= loc; i--)
	{
		arr[i] = arr[i - 1];
	}

	arr[loc - 1] = element;

	for(i = 0; i <= num; i++)
	{
		printf("%d ", arr[i]);
	}
}
