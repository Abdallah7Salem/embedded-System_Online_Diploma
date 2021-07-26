// C Function to take an integer number and calculate its square root

#include "stdio.h"

float square_root_for_nums(float num);

void main()
{
	float n;
	printf("Please write an integer number: ");
	scanf("%f", &n);

	printf("Output: %f", square_root_for_nums(n));
}

float square_root_for_nums(float num)
{
	float i;
	for(i = 0.01; i * i < num; i++);

	return i;
}
