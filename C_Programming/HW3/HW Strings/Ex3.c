// C Program to Reverse String Without Using Library Function

#include "stdio.h"
#include "string.h"

void main()
{
	char str[10];
	printf("Enter the string : ");
	scanf("%s", str);

	printf("Reverse string is : ");
	int i;
	for(i = strlen(str); i >= 0; i--)
	{
		printf("%c", str[i]);
	}
}
