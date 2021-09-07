/*
 * main.c
 *
 *  Created on: Sep 7, 2021
 *      Author: Abdallah
 */



// ===================== MAIN.C ======================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stddef.h>

#define DPRINTF(...)   {fflush(stdout); \
						fflush(stdin); \
						printf(__VA_ARGS__); \
						fflush(stdout); \
						fflush(stdin);}


//effective data
struct Sdata
{
	int ID ;
	char name [40] ;
	float height ;

};

//linked list node
struct SStudent
{
	struct Sdata student ;
	struct SStudent* PNextStudent ;
};

struct SStudent* gpFirstStudent = NULL ;

void AddStudent ()
{
	struct SStudent* pNewStudent ;
	struct SStudent* pLastStudent ;
	char temp_text[40] ;
	// ========== check list is empty == yes ===============
	if (gpFirstStudent == NULL )
	{
		//create new record
		pNewStudent = (struct SStudent*) malloc (sizeof (struct SStudent));

		//assign it to gpfirst
		gpFirstStudent = pNewStudent ;
	}
	else // ========= no : list contains records =================
	{
		// NAVIGATE UNTIL REACH THE LAST RECORD
		pLastStudent = gpFirstStudent ;
		while (pLastStudent->PNextStudent)
			pLastStudent = pLastStudent->PNextStudent ;
		//create new record
		pNewStudent = (struct SStudent*) malloc(sizeof (struct SStudent));

		pLastStudent->PNextStudent = pNewStudent ;
	}

	// fill new record
	DPRINTF("\n Enter the ID : ");
	gets (temp_text);
	pNewStudent->student.ID = atoi(temp_text);

	DPRINTF("\n Enter student full name : ");
	gets (pNewStudent->student.name);

	DPRINTF("\n Enter the height : ");
	gets (temp_text);
	pNewStudent->student.height = atof(temp_text);

	// set next pointer (new_student) null
	pNewStudent->PNextStudent = NULL ;
}

int delete_student ()
{
	char temp_text[40] ;
	int selected_id ;


	// get the selected id
	DPRINTF("\nEnter the student id to be deleted : ");
	gets(temp_text);
	selected_id = atoi 	(temp_text);

	// list is not empty
	if (gpFirstStudent)
	{
		struct SStudent* pSelectedStudent = gpFirstStudent ;
		struct SStudent* pPreviousStudent = NULL ;

		// loop on all records
		while (pSelectedStudent)
		{
			// compare each node with the selected id
			if (pSelectedStudent->student.ID == selected_id)
			{
				if (pPreviousStudent) // the first student is not the selected one
				{
					pPreviousStudent->PNextStudent = pSelectedStudent->PNextStudent ;

				}
				else // 1st student == ID
				{
					gpFirstStudent = pSelectedStudent->PNextStudent ;
				}

				free(pSelectedStudent) ;
				return 1 ;

			}
			pPreviousStudent = pSelectedStudent ;
			pSelectedStudent = pSelectedStudent->PNextStudent ;

		}

	}
	DPRINTF("\n cannot find student ID.");
	return 0 ;

}

void view_students()
{
	struct SStudent* pCurrentStudent = gpFirstStudent ;
	int count = 0 ;
	if (gpFirstStudent == NULL)
	{
		DPRINTF("\n Empty list");
	}
	else
	{
		while (pCurrentStudent)
		{
			DPRINTF("\n record number %d", count+1);
			DPRINTF("\n \t ID : %d", pCurrentStudent->student.ID);
			DPRINTF("\n \t Name : %s", pCurrentStudent->student.name);
			DPRINTF("\n \t Height : %f", pCurrentStudent->student.height);

			pCurrentStudent = pCurrentStudent->PNextStudent ;
			count++ ;
		}
	}

}

void DeleteAll ()
{
	struct SStudent* pCurrentStudent = gpFirstStudent ;
	if (gpFirstStudent == NULL)
	{
		DPRINTF("\n Empty list");
	}
	else
	{
		while (pCurrentStudent)
		{
			struct SStudent* pTempStudent = pCurrentStudent ;
			pCurrentStudent = pCurrentStudent->PNextStudent ;
			free(pTempStudent) ;
		}
		gpFirstStudent = NULL ;
	}

}

int main (void)
{
	char temp_text[40];

	while(1)
	{
		DPRINTF("\n ====================");
		DPRINTF("\n\t Choose one of the following options \n");
		DPRINTF("\n 1: AddStudent  ");
		DPRINTF("\n 2: Delete_Student  ");
		DPRINTF("\n 3: view_students  ");
		DPRINTF("\n 4: DeleteAll  ");
		DPRINTF("\n Enter Option Number: ");

		gets(temp_text);
		DPRINTF("\n ===================");
		switch (atoi (temp_text))
		{
			case 1:
				AddStudent();
				break;
			case 2:
				delete_student();
				break;
			case 3:
				view_students();
				break;
			case 4:
				DeleteAll();
				break;
			default:
				DPRINTF("\n wrong option ");
				break;
		}

	}


	return 0 ;
}
