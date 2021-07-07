// C Program to multiply two floating point numbers

#include "stdio.h"

void main()
{
	float x, y;
	printf("Enter two numbers: ");
	scanf("%f\n%f", &x, &y);
	printf("Product: %0.6f", x * y);
}