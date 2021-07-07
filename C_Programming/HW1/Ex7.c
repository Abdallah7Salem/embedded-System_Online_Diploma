// Source code to swap two numbers  

#include "stdio.h"

void main()
{
	float a, b, temp;
	printf("Enter value of a: ");
	scanf("%f", &a);
	printf("Enter value of b: ");
	scanf("%f", &b);
	
	a = a + b;
	b = a - b;
	a = a - b;
	
	printf("\nAfter swapping, value of a = %0.2f", a);
	printf("\nAfter swapping, value of b = %0.2f", b);
}