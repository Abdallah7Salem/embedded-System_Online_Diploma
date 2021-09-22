/*
 * main.c
 *
 *  Created on: Sep 19, 2021
 *      Author: Abdallah
 */

#include "Queue.h"


int main (void)
{
	SFIFO_BUFFER student;
	int temp;
	SStudentInformation test;

	if (FIFO_init(&student, Student_Buffer, 15) == FIFO_no_error)
	{
		DPRINTF("==========================\n");
		DPRINTF("FIFO has been Initialized ------> DONE");
		DPRINTF("\n====================================");
	}

	DPRINTF("\nWelcome to the Student Management System \n");
	while (1)
	{
		DPRINTF("=======================================\n");
		DPRINTF("Choose the task that you want to perform\n");
		DPRINTF("\n1. Add a Student details manually: ");
		DPRINTF("\n2. Add a student details from file: ");
		DPRINTF("\n3. View students information: ");
		DPRINTF("\n4. Dequeue a student: ");
		DPRINTF("\n5. to Count the students: ");
		DPRINTF("\n6. Find a student by ID: ");
		DPRINTF("\n7. Find a student by First Name: ");
		DPRINTF("\n8. Find the students registered in a course: ");
		DPRINTF("\n9. Delete a student by ID: ");
		DPRINTF("\n10. Update a student information: ");
		DPRINTF("\n11. End the program: ");

		scanf("%d", &temp);

		switch (temp)
		{
		case 1:
		{
			if (FIFO_enqueue(&student, &test) == FIFO_no_error)
			{
				DPRINTF("==================================\n");
				DPRINTF("\t FIFO ENQUEUE ------> DONE ");
				DPRINTF("\n==================================\n");
			}

			else if (FIFO_enqueue(&student, Student_Buffer) == FIFO_full)
			{
				DPRINTF("\n=================================\n");
				DPRINTF("FIFO IS FULL\n");
				DPRINTF("===================================\n");
			}

			else
			{
				DPRINTF("\t FIFO ENQUEUE -------> FAILED :(\n");
			}

			break;
		}
		case 2:
		{
			Add_Student_File(&student, Student_Buffer);
			break;
		}
		case 3:
		{
			FIFO_print(&student);
			break;
		}
		case 4:
		{
			if (FIFO_dequeue(&student, &test) == FIFO_no_error);
			break;
		}
		case 5:
		{
			DPRINTF("\n======================================\n");
			DPRINTF("Number of students is %d \n", Count_Of_Students(&student));
			DPRINTF("========================================\n");
			break;
		}
		case 6:
		{
			Find_Student_by_ID(&student, Student_Buffer);
			break;
		}
		case 7:
		{
			Find_Student_by_First_Name(&student, Student_Buffer);
			break;
		}
		case 8:
		{
			Find_Student_Registered_in_Course(&student, Student_Buffer);
			break;
		}
		case 9:
		{
			Delete_Student_by_ID(&student, Student_Buffer);
			break;
		}
		case 10:
		{
			Update_Student(&student, Student_Buffer);
			break;
		}
		case 11:
		{
			return 0;
		}

		} // switch

	} // while

	return 0;
}
