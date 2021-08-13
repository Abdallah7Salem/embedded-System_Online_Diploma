// C Program to print string in reverse using a pointer

#include "stdio.h"


int main(void)
{
	char arr[100];
	char rev_arr[100];

	char* p_arr = arr;
	char* p_rev_arr = rev_arr;

	printf("Input a string : ");
	scanf("%s", arr);

	int i = 0;

	// assigning the value of i to the array size
	while(*p_arr)
	{
		p_arr++;
		i++;
	}


	while(i >= 0)
	{
		p_arr--;
		*p_rev_arr = *p_arr;
		p_rev_arr++;
		--i;
	}

	*p_rev_arr = '\0';

	printf("\nReverse of the string is : %s ", rev_arr);


	return 0;
}

