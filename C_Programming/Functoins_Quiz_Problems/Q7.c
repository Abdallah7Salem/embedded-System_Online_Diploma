// C Program to Check If A Given Number Is A Power of 3 

#include "stdio.h"
#include "math.h"

int CheckPowerOf3(unsigned n);

void main()
{
	unsigned n;
	printf("Enter a number : \n");
	scanf("%d", &n);
	
	CkeckPowerOf3(n) ? printf("%d ==> 0", n) : printf("%d ==> 1", n);
}

int CheckPowerOf3(unsigned n)
{
	// find log3(n)
	double i = log(n) / log(3);
	
	// return true if log3(n) is an integer
	return i == trunc(i);
}