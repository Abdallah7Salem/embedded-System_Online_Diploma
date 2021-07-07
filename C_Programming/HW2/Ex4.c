// C Program To Check Whether a Number is Positive or Negative

#include "stdio.h"

void main()
{
	float num;
	printf("Enter a number: ");
	scanf("%f", &num);
	
	if(num > 0)
		printf("%0.2f is positive", num);
	else if(num < 0)
		printf("%0.2f is negative", num);
	else if(num == 0)
		printf("You entered zero");
	else 
		printf("Invalid Number");
}