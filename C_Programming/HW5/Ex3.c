// C Program to Add Two Complex Numbers by Passing Strucuture to a Function

#include "stdio.h"

struct Complex_Num
{
	float real;
	float img;
}Num1, Num2, Sum;

void Add(struct Complex_Num N1, struct Complex_Num N2);

int main(void)
{

printf("For 1st complex number");
printf("\nEnter real and imaginary respectively: ");
scanf("%f%f", &Num1.real, &Num1.img);

printf("For 2nd complex number");
printf("\nEnter real and imaginary respectively: ");
scanf("%f%f", &Num2.real, &Num2.img);

Add(Num1, Num2);

printf("\nSum = %0.1f + %0.1fi", Sum.real, Sum.img);

return 0;
}

void Add(struct Complex_Num N1, struct Complex_Num N2)
{
	Sum.real = Num1.real + Num2.real;
	Sum.img = Num1.img + Num2.img;
}
