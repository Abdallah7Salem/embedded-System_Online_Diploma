// C Program to Find Area of a Circle , Passing Arguments to Macros

#include "stdio.h"
#define PI 3.14

int main(void)
{

float radius, area;
printf("Enter the radius: ");
scanf("%f", &radius);

area = PI * radius * radius;

printf("Area = %0.2f", area);

return 0;
}

