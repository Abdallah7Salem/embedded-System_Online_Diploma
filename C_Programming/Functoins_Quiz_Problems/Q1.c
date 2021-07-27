// C Program Takes String from the User and check if it is the same USERNAME or not

#include "stdio.h"

void main()
{
	char arr1[100], arr2[100];
	int result;

	printf("Enter a string : ");
	gets(arr1);

	printf("Enter your name : ");
	gets(arr2);

	result = stricmp(arr1, arr2);
	if(result == 0)
		printf("Identical");
	else
		printf("Different");
}
