// C Program to Search an element in Array

#include "stdio.h"

void main()
{
	int num;
	printf("Enter no of elements : ");
	scanf("%d", &num);

	int a[num], i;
	for(i = 0; i < num; i++)
	{
		scanf("%d", &a[i]);
	}

	int element;
	printf("Enter the element to be searched : ");
	scanf("%d", &element);

	for(i = 0; i < num; i++)
	{
		if(element == a[i])
			printf("Number found at the location = %d", i+1);
	}


}
