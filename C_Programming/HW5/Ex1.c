// C Program to Store Information (name, roll and marks) of a Student Using Structure

#include "stdio.h"

struct student
{
	char name[20];
	unsigned int roll;
	float marks;
}s;

void main()
{
	printf("Enter information of students: \n\n");
	printf("Enter name: ");
	scanf("%s", s.name);
	printf("\nEnter roll number: ");
	scanf("%d", &s.roll);
	printf("\nEnter marks: ");
	scanf("%f", &s.marks);

	printf("\nDisplaying Information");

	printf("\nname: %s", s.name);
	printf("\nRoll: %d", s.roll);
	printf("\nMarks: %0.1f", s.marks);
}
