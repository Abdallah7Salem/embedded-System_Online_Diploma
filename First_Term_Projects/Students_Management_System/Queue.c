#include "Queue.h"

EFIFO_BUF_STATUS FIFO_Full (SFIFO_BUFFER* fifo)
{
	/*check if queue is valid ?*/
	if (!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null;

	/*check if queue if full ?*/
	if (fifo->count == fifo->length)
		return FIFO_full;

	return FIFO_no_error;
}

EFIFO_BUF_STATUS FIFO_init (SFIFO_BUFFER* fifo, SStudentInformation* buf, unsigned int length)
{
	/* check if there is no students information */
	if (!buf)
		return FIFO_null;

	fifo->base = buf;
	fifo->head = buf;
	fifo->tail = buf;
	fifo->count = 0;
	fifo->length = length;

	return FIFO_no_error;
}


EFIFO_BUF_STATUS FIFO_enqueue (SFIFO_BUFFER* fifo, SStudentInformation *item)
{
	/* check if queue if valid ?*/
	if (!fifo->head || !fifo->tail || !fifo->base)
		return FIFO_null;

	/* check if queue is full */
	if (FIFO_Full(fifo) == FIFO_full)
		return FIFO_full;

	DPRINTF("\n====================\n");

	DPRINTF("\tEnter The First Name: ");
	scanf("%s", fifo->head->FirstName);

	DPRINTF("\tEnter The Last Name: ");
	scanf("%s", fifo->head->LastName);

	DPRINTF("\tEnter The ID: ");
	scanf("%d", &fifo->head->ID);

	DPRINTF("\tEnter The GPA: ");
	scanf("%f", &fifo->head->GPA);

	DPRINTF("\tEnter The ID Of Courses Registered: ");
	int i;
	for (i = 0; i < 5; i++)
	{
		DPRINTF("\n\tEnter The ID Of Course %d : ", i+1);
		scanf("%d", &fifo->head->CoursesRegistered[i]);
	}

	DPRINTF("\n=======================\n");

	fifo->count++;

	/* circular fifo */
	if (fifo->head == (fifo->base + (fifo->length * sizeof(SStudentInformation))))
		fifo->head = fifo->base;

	else
		fifo->head++;


	return FIFO_no_error;
}

EFIFO_BUF_STATUS FIFO_dequeue (SFIFO_BUFFER* fifo, SStudentInformation* item)
{
	/*check if queue is valid ?*/
	if (!fifo->head || !fifo->tail || !fifo->base)
		return FIFO_null;

	/*check if queue is empty ?*/
	if(fifo->count == 0)
	{
		DPRINTF("\n=========================");
		DPRINTF("The Queue Is Empty");
		DPRINTF("\n=========================");
		return 0;
	}


	/*dequeue data*/
	(item->ID) = (fifo->tail->ID);
	fifo->count--;

	DPRINTF("\n======================================");
	DPRINTF("FIFO dequeue Student With ID: %d   -------->DONE :)\n", item->ID);
	DPRINTF("========================================\n");

	/*circular fifo*/
	if (fifo->tail == (fifo->base + (fifo->length * sizeof(SStudentInformation))))
		fifo->tail = fifo->base;

	else
		fifo->tail++;

	return FIFO_no_error;
}

/*Add studnets information using text file */
int Add_Student_File (SFIFO_BUFFER* fifo, SStudentInformation* student)
{
	/*check if queue is valid ?*/
	if (!fifo->base || !fifo->head || !fifo->tail)
		DPRINTF("FIFO NULL");

	/*check if queue is full ?*/
	if (FIFO_Full(fifo) == FIFO_full)
	{
		DPRINTF("\n===================\n");
		DPRINTF("The Queue Is FULL :(");
		DPRINTF("\n===================\n");
		return 0;
	}


	FILE *fp;
	char text[100];
	char* filename = "C:\\Users\\Abdallah\\Desktop\\studentData.txt";

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		DPRINTF("Couldn't Open File: %s", filename);
		return 1;
	}
	while (fgets(text, 100, fp) != NULL);

	//Extract the first token and put it in the FirstName
	char * token = strtok(text, " ");
	strcpy(student->FirstName, token);

	token = strtok(NULL, " ");

	strcpy(fifo->head->LastName, token);

	token = strtok(NULL, " ");

	fifo->head->ID = *(token) - 48; // 7 in ASCI is 55 , 0 is 48 (55 - 48)

	token = strtok(NULL, " ");


	fifo->head->GPA = atof(token);

	token = strtok(NULL, " ");

	int i = 0;
	while (token != NULL)
	{
		/*printing each token*/
		fifo->head->CoursesRegistered[i] = atoi(token);
		token = strtok(NULL, " ");
		i++;
	}

	DPRINTF("\n========================================\n");
	DPRINTF("Adding Student by File Has Been ------> Done");
	DPRINTF("\n========================================\n");

	fifo->count++;

	/*circular fifo*/
	if (fifo->head == (fifo->base + (fifo->length * sizeof(SStudentInformation))))
		fifo->head = fifo->base;

	else
		fifo->head++;

	return 0;
}


void FIFO_print (SFIFO_BUFFER* fifo)
{
	SStudentInformation *temp;
	int i, j;

	/*check if fifo is empty ?*/
	if (fifo->count == 0)
	{
		DPRINTF("\n==========================\n");
		DPRINTF("FIFO Is Empty");
		DPRINTF("\n==========================\n");
	}

	else
	{
		temp = fifo->tail;
		DPRINTF("\n========= Print Data Of All Students In The Database =========\n");
		for (i = 0; i < fifo->count; i++)
		{
			DPRINTF("\tThe First Name is: %s \n", temp->FirstName);
			DPRINTF("\tThe Last Name is: %s \n", temp->LastName);
			DPRINTF("\tThe ID is: %d \n", temp->ID);
			DPRINTF("\tThe GPA is: %0.1f \n", temp->GPA);
			for (j = 0; j < 5; j++)
			{
				DPRINTF("\t The ID Of The %d Course is : %d \n", j+1, (temp->CoursesRegistered[j]));
			}
			DPRINTF("==========================\n");
			temp++;
		}
	}
}

int Count_Of_Students (SFIFO_BUFFER* fifo)
{
	return fifo->count;
}

int Find_Student_by_First_Name (SFIFO_BUFFER* fifo, SStudentInformation *p_student)
{
	char firstName[10];
	int i = 0, j = 0;
	p_student = fifo->tail;
	DPRINTF("\nEnter The First Name of The Student You Want : ");
	scanf("%s", firstName);

	for (i = 0; i < fifo->count; i++)
	{
		if (strcmp(p_student->FirstName, firstName) == 0)
		{
			DPRINTF("===========================\n");
			DPRINTF("\tThe First Name is: %s \n", p_student->FirstName);
			DPRINTF("\tThe Last Name is: %s \n", p_student->LastName);
			DPRINTF("\tThe ID is: %d \n", p_student->ID);
			DPRINTF("\tThe GPA is: %f ", p_student->GPA);
			for (j = 0; j < 5; j++)
			{
				DPRINTF("\t The ID Of The %d Course is : %d \n", j+1, (p_student->CoursesRegistered[j]));
			}
			DPRINTF("=================================\n");
			return 0;
		}
		p_student++;
	}
	DPRINTF("\n=============================\n");
	DPRINTF("The First Name is Not Found in The Data base :(\n");
	DPRINTF("===============================\n");

	return 0;

}


int Find_Student_by_ID (SFIFO_BUFFER* fifo, SStudentInformation *p_student)
{
	int ID_Number;
	int i = 0, j = 0;
	p_student = fifo->tail;
	DPRINTF("\nEnter The ID Of The Student You Want: ");
	scanf("%d", &ID_Number);

	for (i = 0; fifo->count; i++)
	{
		if (p_student->ID == ID_Number)
		{
			DPRINTF("=================================\n");
			DPRINTF("\tThe First Name is: %s \n", p_student->FirstName);
			DPRINTF("\tThe Last Name is: %s \n", p_student->LastName);
			DPRINTF("\tThe ID is: %d \n", p_student->ID);
			DPRINTF("\tThe GPA is: %f \n", p_student->GPA);
			for (j = 0; j < 5; j++)
			{
				DPRINTF("\t The ID Of The %d Course is: %d \n", j+1, (p_student->CoursesRegistered[j]));
			}
			DPRINTF("================================\n");
			return 0;

		}
		p_student++;
	}
	DPRINTF("\n==============================\n");
	DPRINTF("This ID is Not Found In Database :(\n");
	DPRINTF("================================\n");
	return 0;

}

int Find_Student_Registered_in_Course (SFIFO_BUFFER* fifo, SStudentInformation *p_student)
{
	int flag = 0;
	int Course_ID;
	int i = 0, j = 0, k = 0;
	p_student = fifo->tail;

	if(fifo->count == 0)
	{
		DPRINTF("\n=============================\n");
		DPRINTF("FIFO is Empty\n");
		DPRINTF("===============================\n");
		return 0;

	}
	DPRINTF("Enter The Course ID: ");
	scanf("%d", &Course_ID);

	for (i = 0; i < fifo->count; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (p_student->CoursesRegistered[j] == Course_ID)
			{
				DPRINTF("\n===============================\n");
				DPRINTF("\tThe First Name is: %s \n", p_student->FirstName);
				DPRINTF("\tThe Last Name is: %s \n", p_student->LastName);
				DPRINTF("\tThe ID is: %d \n", p_student->ID);
				DPRINTF("\tThe GPA is: %f \n", p_student->GPA);
				for (k = 0; k < 5; k++)
				{
					DPRINTF("\tThe ID of The %d Course is : %d \n", k+1, (p_student->CoursesRegistered[k]));
				}
				DPRINTF("=================================\n");
				flag = 1;
			}
			if (i == 16)
				return 0;
		}
		p_student++;

	}
	if (flag == 0)
	{
		DPRINTF("\n============================\n");
		DPRINTF("This Course ID Doesn't exist :(\n");
		DPRINTF("==============================\n");
	}

	return 0;
}

int Delete_Student_by_ID (SFIFO_BUFFER* fifo, SStudentInformation *p_student)
{
	int i, Student_ID;
	int flag = 0;
	p_student = fifo->tail;

	if (fifo->count == 0)
	{
		DPRINTF("\n=================================\n");
		DPRINTF("FIFO is Empty\n");
		DPRINTF("===================================\n");
		return 0;
	}

	SStudentInformation *pNext = (fifo->tail) + 1;

	DPRINTF("Enter ID of student that you want to delete : \n");
	scanf("%d", &Student_ID);

	for (i = 0; i < fifo->count; i++)
	{
		if (p_student->ID == Student_ID)
		{
			flag = 1;
			*p_student = *pNext;
			pNext++;
		}
		p_student++;
	}
	if (flag == 1)
	{
		DPRINTF("\n===========================\n");
		DPRINTF("Deletion has been ------> DONE");
		DPRINTF("\n===========================\n");
		fifo->count--;
		fifo->head--;
		return 0;
	}

	else
	{
		DPRINTF("This ID is Not Found in The Data base :( \n");
		return 0;
	}
}

int Update_Student (SFIFO_BUFFER* fifo, SStudentInformation *p_student)
{
	int Student_ID;
	int i, choice, j, Course_ID;
	if (fifo->count == 0)
	{
		DPRINTF("\n=============================\n");
		DPRINTF("FIFO is Empty\n");
		DPRINTF("===============================\n");
		return 0;
	}
	DPRINTF("\n=============================\n");
	DPRINTF("Enter ID of Student you want to update: ");
	scanf("%d", &Student_ID);

	for (i = 0; i < fifo->count; i++)
	{
		if (p_student->ID == Student_ID)
		{
			DPRINTF("1. First Name \n");
			DPRINTF("2. Last Name \n");
			DPRINTF("3. ID \n");
			DPRINTF("4. GPA \n");
			DPRINTF("5. Courses \n");
			DPRINTF("Enter The Number of what you need to update: ");
			scanf("%d", &choice);

			switch (choice)
			{
			case 1:
			{
				DPRINTF("Enter The New First Name: ");
				scanf("%s", p_student->FirstName);
				break;
			}
			case 2:
			{
				DPRINTF("Enter The New Last Name: ");
				scanf("%s", p_student->LastName);
				break;
			}
			case 3:
			{
				DPRINTF("Enter The New ID: ");
				scanf("%d", &p_student->ID);
				break;
			}
			case 4:
			{
				DPRINTF("Enter The New GPA: ");
				scanf("%f", &p_student->GPA);
				break;
			}
			case 5:
			{
				DPRINTF("Enter the ID of the Course that you want to update: ");
				scanf("%d", &Course_ID);
				for (j = 0; j < 5; j++)
				{
					if (p_student->CoursesRegistered[j] == Course_ID)
					{
						DPRINTF("Enter The ID of New Course: ");
						scanf("%d", &(p_student->CoursesRegistered[j]));
					}
				}
				break;
			}
			default:
			{
				DPRINTF("Wrong choice \n");
			}

			}
			DPRINTF("\n===============================\n");
			return 0;

		}
		p_student++;
		if (p_student->ID != Student_ID)
		{
			DPRINTF("\n==================================\n");
			DPRINTF("This Course ID doesn't exist :(\n");
			DPRINTF("====================================\n");
		}
	}

	return 0;
}


