// C Function to take an array and reverse its elements

#include "stdio.h"

int size;
void Reverse_Array_E(int arr[]);

void main()
{
	printf("Enter array size: ");
	scanf("%d", &size);

	int arr[size];

	printf("Enter the array elements: ");
	int i;
	for(i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}

	Reverse_Array_E(arr);

	int j;
	for(j = 0; j < size; j++)
	{
		printf("%d ", arr[j]);
	}
}


void Reverse_Array_E(int arr[])
{
	int i = 0;
	int j;
	int temp;

	j = size - 1;
	for(i = 0; i < size / 2; i++)
	{
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		j = j - 1;

	}
}
