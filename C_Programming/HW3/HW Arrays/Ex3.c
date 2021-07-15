// C Program To Find Transpose Of A Matrix

#include "stdio.h"

void main()
{
	int r, c;

	printf("Enter rows and column of matrix: ");
	scanf("%d\n%d", &r, &c);

	int a[r][c];
	printf("Enter elements of matrix:\n");

	int i, j;
	for(i = 0; i < r; i++)
	{
		for(j = 0; j < c; j++)
		{
			printf("Enter elements a%d%d: ", i+1, j+1);
			scanf("%d", &a[i][j]);
		}
	}

	printf("\nEntered Matrix:\n");
	for(i = 0; i < r; i++)
	{
		for(j = 0; j < c; j++)
		{
			printf("%d  ", a[i][j]);
		}
		printf("\n");
	}

	int temp = 0;
	printf("\nTranspose of Matrix:\n");

	for(i = 0; i < c; i++)
	{
		for(j = 0; j < r; j++)
		{
			temp = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = temp;
			printf("%d  ", a[i][j]);
		}
		printf("\n");
	}

}
