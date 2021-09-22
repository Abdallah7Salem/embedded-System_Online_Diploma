#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#define DPRINTF(...) printf(__VA_ARGS__);fflush(stdout);fflush(stdin);

typedef struct
{
	char FirstName[10];
	char LastName[10];
	int ID;
	float GPA;
	int CoursesRegistered[5];
}SStudentInformation;

SStudentInformation Student_Buffer[15];

typedef struct
{
	unsigned int length;
	unsigned int count;
	SStudentInformation* base; // pointer to a SStudentInformation struct
	SStudentInformation* head; // ...
	SStudentInformation* tail; // ...
}SFIFO_BUFFER;


typedef enum
{
	FIFO_no_error , /* 0 */
	FIFO_full ,     /* 1 */
	FIFO_empty ,    /* 2 */
	FIFO_null ,     /* 3 */
}EFIFO_BUF_STATUS;


/*Prototype of function used in the code */
EFIFO_BUF_STATUS FIFO_Full       (SFIFO_BUFFER* fifo);
EFIFO_BUF_STATUS FIFO_init       (SFIFO_BUFFER* fifo, SStudentInformation* buf, unsigned int length);
EFIFO_BUF_STATUS FIFO_enqueue    (SFIFO_BUFFER* fifo, SStudentInformation *item);
EFIFO_BUF_STATUS FIFO_dequeue    (SFIFO_BUFFER* fifo, SStudentInformation* item);

int Add_Student_File                    (SFIFO_BUFFER* fifo, SStudentInformation* student);
int Count_Of_Students                   (SFIFO_BUFFER* fifo);
int Find_Student_by_First_Name          (SFIFO_BUFFER* fifo, SStudentInformation *p_student);
int Find_Student_by_ID                  (SFIFO_BUFFER* fifo, SStudentInformation *p_student);
int Find_Students_Registered_in_Course  (SFIFO_BUFFER* fifo, SStudentInformation *p_student);
int Delete_Student_by_ID                (SFIFO_BUFFER* fifo, SStudentInformation *p_student);
int Update_Student                      (SFIFO_BUFFER* fifo, SStudentInformation *p_studnet);
void FIFO_print                         (SFIFO_BUFFER* fifo);
