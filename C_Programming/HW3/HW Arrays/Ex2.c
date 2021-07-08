// C Program To Calculate Average Using Arrays

#include "stdio.h"

void main()
{
	int n;
	printf("Enter the numbers of data: ");
	scanf("%d", &n);

	float arr[n];
	int i;
	for(i = 0; i < n; i++)
	{
		printf("%d. Enter number: ", i+1);
		scanf("%f", &arr[i]);
	}

	int j; float Sum = 0;
	for(j = 0; j < n; j++)
	{
		Sum = Sum + arr[j];
	}

	float Average = Sum / n;
	printf("Average = %0.2f", Average);
}
