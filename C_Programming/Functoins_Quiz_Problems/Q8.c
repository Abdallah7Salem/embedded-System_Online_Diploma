// C Function To Print The Last Occurrence Of A Number

#include "stdio.h"

int Last_Occurrence (int arr[], int size);

void main()
{
	int arr[100], size;

	printf("Enter the size of the array : ");
	scanf("%d", &size);

	for(int i = 0; i < size; i++)
	{
		printf("Enter element %d : ", i+1);
		scanf("%d", &arr[i]);
	}

	printf("Last occurrence is %d", Last_Occurrence(arr, size));
}

int Last_Occurrence (int arr[], int size)
{
	int num;
	printf("Enter the number you want to get its last occurrence : ");
	scanf("%d", &num);

	for(int i = size; i > 0; i--)
	{
		if(arr[i] == num)
			return i+1;
	}
	return -1;
}
