// C Program to Store Information of Students Using Structure

#include "stdio.h"

struct Student
{
	char name[20];
	int marks;
};

int main(void)
{

int num, i;
printf("Enter number of students: ");
scanf("%d", &num);

struct Student arr[num];

printf("Enter information of students: ");

for(i = 0; i < num; i++)
{
	printf("\nFor roll number %d ", i + 1);
	printf("\nEnter name: ");
	scanf("%s", &arr[i].name);
	printf("Enter marks: ");
	scanf("%d", &arr[i].marks);
}

printf("Displaying information of students: ");

for(i = 0; i < num; i++)
{
	printf("\nInformation for roll number %d: ", i + 1);
	printf("\nName: %s", arr[i].name);
	printf("\nMarks: %d", arr[i].marks);
}


return 0;
}

