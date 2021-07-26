// C Function to sum numbers from 1 to 100 (without loop)

#include "stdio.h"

void Sum_Numbers(void);

int main()
{
	Sum_Numbers();

	return 0;
}

void Sum_Numbers(void)
{
	static int i = 1;
	if(i <= 100)
	{
		printf("%d ", i++);
		Sum_Numbers();
	}
}
