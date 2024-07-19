/*
 * main.c
 *
 *  Created on: Jan 1, 2024
 *      Author: Abdelrahman Maher
 */

#include "fifo.h"

void main()
{
	uint8_t temp[10];
	uint32_t Value=0,count=0;

	while(1)
	{
		DPrint("\n1-  Add Student\n");
		DPrint("2-  Remove Student\n");
		DPrint("3-  View All Student\n");
		DPrint("4-  Delete All Students\n");
		DPrint("5-  View the Nth Student \n");
		DPrint("6-  View the Nth Student From the End \n");
		DPrint("7-  Length\n");
		DPrint("8-  Middle Student\n");
		DPrint("9-  check if their is a circular loop\n");
		DPrint("10- Reverse the order\n");

		gets(temp);
		Value = atoi(temp);

		switch (Value)
		{
		case 1:
			add();
			break;
		case 2 :
			Delete();
			break;
		case 3:
			Display();
			break;
		case 4:
			Delete_All();
			break;
		case 5 :
			Nth_Node();
			break;
		case 6:
			Nth_Node_From_End();
			break;
		case 7 :
			count = Length();
			if (count == False)
			{
				DPrint("\nthe length is %d as the queue is empty!\n",count);
			}
			else
			{
				DPrint("\nNumber of available Nodes is %d\n", count);
			}
			break;
		case 8:
			Middle();
			break;
		case 9 :
			Check_circular();
			break;
		case 10:
			Reverse();
			break;
		default :
			DPrint("\n Error in the entered number choose between 1 to 10 please\n\n");
			break;

		}
	}



}
