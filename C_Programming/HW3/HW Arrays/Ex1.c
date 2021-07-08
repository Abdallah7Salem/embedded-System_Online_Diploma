// C Program To Find Sum Of Two Matrices Of Order 2*2 Where Elements Of Matrix Are Entered By User.

#include "stdio.h"

void main()
{
	float a[2][2], b[2][2], Sum[2][2];
	int i, j;

	printf("Enter the elements of 1st matrix");

	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < 2; j++)
		{
			printf("\nEnter a%d%d: ", i+1, j+1);
			scanf("%f", &a[i][j]);
		}
	}

	printf("Enter the elements of 2nd matrix");

	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < 2; j++)
		{
			printf("\nEnter b%d%d: ", i+1, j+1);
			scanf("%f", &b[i][j]);
		}
	}

	printf("Sum Of Matrix: \n");
	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < 2; j++)
		{
			printf("%0.1f\t", a[i][j] + b[i][j]);
		}
		printf("\n");
	}

}