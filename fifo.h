/*
 * fifo.h
 *
 *  Created on: Jan 1, 2024
 *      Author: Abdelrahman Maher
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "platform_type.h"

#define  DPrint(...)	{  fflush(stdin);\
						   fflush(stdout);\
						   printf(__VA_ARGS__);\
						   fflush(stdin);\
						   fflush(stdout);\
						}

typedef struct
{
	uint32_t  ID;
	uint8_t   Name[40];
	float32_t Height;
}Student_t;

typedef struct Node
{
	Student_t Student;
	struct Node* pNext;
}Node_t;

void add ();
uint8_t Delete();
void Display();
void Delete_All();
void Nth_Node();
void Nth_Node_From_End();
uint32_t Length();
void Middle();
void Check_circular();
void Reverse ();


#endif /* FIFO_H_ */
