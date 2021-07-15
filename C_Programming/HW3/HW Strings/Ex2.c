// C Program to Find the Length of a String

#include "stdio.h"
#include "string.h"

void main()
{
	char ch[10];
	printf("Enter a string: ");
	fflush(stdout);
	scanf("%s", ch);

	int count = 0, i;
	for(i = 0; ch[i] != '\0'; i++)
	{
		count++;
	}

	printf("Length of string: %d", count);
}
