// C Program to demonstrate how to handle pointers in the program

#include "stdio.h"


int main(void)
{
	int *ab;
	int m = 29;

	printf("Address of m : %x", &m);
	printf("\nValue of m : %d", m);

	ab = &m;
	printf("\n\nNow ab is assigned with the address of m.");
	printf("\nAddress of pointer ab : %x", ab);
	printf("\nContent of pointer ab : %d", *ab);

	*ab = 7;
	printf("\n\nThe pointer variable ab is assigned with the value 7 now");
	printf("\nAddress of m : %x", &m);
	printf("\nValue of m : %d", m);




return 0;
}

