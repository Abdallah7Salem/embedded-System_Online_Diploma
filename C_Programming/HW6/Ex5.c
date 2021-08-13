// C Program to show a pointer to an array which contents are pointer to structure

#include "stdio.h"


struct employee
{
	char* name;
	int Id;
};

int main(void)
{

	struct employee emp1 = {"Abdallah", 1000}, emp2 = {"Salem", 1001}, emp3 = {"Alex", 1002};
	// array of pointers to structures
	struct employee (*arr[]) = (&emp1, &emp2, &emp3);
	// pointer to array of pointers to structures
	struct employee (*(*pt)[3]) = &arr;


	return 0;
}

