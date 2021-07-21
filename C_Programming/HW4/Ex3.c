// C Program to Reverse a Sentence Using Recursion

#include "stdio.h"

void Reverse_Func();

void main()
{
	printf("Enter a sentence: ");
	Reverse_Func();
}


void Reverse_Func()
{
	char ch;
	scanf("%c", &ch);
	if (ch != '\n')
	{
		Reverse_Func();
		printf("%c", ch);
	}
}
