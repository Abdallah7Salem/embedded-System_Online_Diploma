// C Program To Find The Largest Number Among Three Numbers 

#include "stdio.h"

void main()
{
	float a, b, c;
	printf("Enter three numbers: ");
	scanf("%f\n%f\n%f", &a, &b, &c);
	
	if(a>b)
	{
		if(a>c)
			printf("Largest number = %0.2f", a);
		else if(a<c)
			printf("Largest number = %0.2f", c);
	}
	else
		printf("Largest number = %0.2f", b);
}