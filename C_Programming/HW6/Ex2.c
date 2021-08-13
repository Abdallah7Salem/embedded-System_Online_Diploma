// C Program to print all the alphabets using a pointer

#include "stdio.h"


int main(void)
{
	int* p_alpha;

	printf("The Alphabets are : \n");

	int i;
	p_alpha = &i;

	for(i = 'A'; i <= 'Z'; i++)
	{
		printf("%c ", *p_alpha);
	}







	return 0;
}

