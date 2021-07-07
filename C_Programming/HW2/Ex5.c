// C Program to Check Whether a Character is Alphabet or Not 

#include "stdio.h"

void main()
{
	char c;
	printf("Enter a character: ");
	scanf("%c", &c);
	
	if('A' <= c && c <= 'z')
		printf("%c is an alphabet", c);
	else
		printf("%c is not an alphabet", c);
}