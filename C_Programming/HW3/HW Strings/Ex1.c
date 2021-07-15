// C program to Find the Frequency of Characters in a String

#include "stdio.h"
#include "string.h"

void main()
{
	char a[30];
	printf("Enter a string: ");
	gets(a);

	char ch;
	printf("Enter a character to find frequency: ");
	scanf("%c", &ch);

	int i, count = 0;
	for(i = 0; i < strlen(a); i++)
	{
		if(ch == a[i])
		{
			count++;
		}
	}

	printf("Frequency of e = %d", count);
}
