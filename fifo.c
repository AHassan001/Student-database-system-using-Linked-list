/*
 * fifo.c
 *
 *  Created on: Jan 1, 2024
 *      Author: Abdelrahman Maher
 */

#include "fifo.h"

Node_t* gptoFirstStudents = NULL;

void add ()
{
	// create a temp variable
	uint8_t Temp[40];

	//Create a Pointer
	Node_t* pNewStudent;
	Node_t* pAddedStudent;

	//create a new allocated memory in heap
	pNewStudent = (Node_t*) malloc(sizeof(Node_t));

	//Check if it is the first element or not
	if(! gptoFirstStudents)
	{
		//First Node
		gptoFirstStudents = pNewStudent;
		//gptoFirstStudents->pNext = NULL;
	}
	else
	{
		pAddedStudent = gptoFirstStudents;

		//not the first node need to loop until we reach the NULL
		while( (pAddedStudent->pNext) )
		{
			pAddedStudent = pAddedStudent->pNext;
		}

		// we reached the end of the queue
		// add a new Node
		pAddedStudent->pNext = pNewStudent;
	}

	// store the new data
	DPrint("Please enter the student id: ");
	gets(Temp);
	pNewStudent->Student.ID = atoi(Temp);

	DPrint("Please enter the student name: ");
	gets(pNewStudent->Student.Name);

	DPrint("Please enter the student height: ");
	gets(Temp);
	pNewStudent->Student.Height = atof(Temp);


	// change the next to NULL
	pNewStudent->pNext = NULL;

}

uint8_t Delete()
{
	uint8_t Temp[40];
	uint32_t ID_Value=0;

	Node_t * pcurrentStudent  = gptoFirstStudents;
	Node_t * ppreviousStudent = NULL;


	//check if there is queue or not
	if(!gptoFirstStudents)
	{
		DPrint("\nthe Queue is empty nothing available to be deleted\n");
		DPrint("-----------------------------");
		DPrint("\n");

		return 0;
	}
	else
	{
		DPrint("Please enter the student id to be deleted\n");
		gets(Temp);
		ID_Value = atoi(Temp);

		//Loop on the queue to check the ID
		while(pcurrentStudent)
		{
			if( pcurrentStudent->Student.ID == ID_Value)
			{
				//Is it the first Node
				if(!ppreviousStudent)
				{
					gptoFirstStudents = gptoFirstStudents->pNext;
				}
				else
				{ //Not first Node

					ppreviousStudent->pNext = pcurrentStudent->pNext;
				}

				free(pcurrentStudent);
				return True;
			}
			ppreviousStudent = pcurrentStudent;
			pcurrentStudent  = pcurrentStudent->pNext;
		}
		DPrint("their is no student with this ID --> %d\n",ID_Value);
		return False;
	}
}

void Display()
{
	uint16_t counter=0;
	Node_t* pStudent_tb_disp = gptoFirstStudents;

	if(!gptoFirstStudents)
	{
		DPrint("\nthe Queue is empty\n");
		DPrint("-----------------------------");
		DPrint("\n");
	}
	else
	{
		while(pStudent_tb_disp)
		{
			DPrint("\nStudent number %d:\n",counter+1);

			DPrint("\tStudent ID: %d\n",pStudent_tb_disp->Student.ID);
			DPrint("\tStudent Name: %s\n",pStudent_tb_disp->Student.Name);
			DPrint("\tStudent Height: %f\n",pStudent_tb_disp->Student.Height);

			DPrint("=============");
			DPrint("\n");

			++counter;
			pStudent_tb_disp= pStudent_tb_disp->pNext;
		}
		DPrint("===========================");

	}
}

void Delete_All()
{
	Node_t* pcurrentStudent = gptoFirstStudents;
	Node_t* pTemp;

	if(!gptoFirstStudents)
	{
		DPrint("Nothing available in the queue to be deleted\n");
	}
	else
	{
		while(pcurrentStudent)
		{
			pTemp = pcurrentStudent;
			pcurrentStudent = pcurrentStudent->pNext;
			free(pTemp);
		}
		gptoFirstStudents = NULL;
	}
}

void Nth_Node()
{
	uint8_t temp[40];
	uint32_t number = 0, count = 1, length_Nodes = 0;

	Node_t * pStudents = gptoFirstStudents;


	DPrint("\nPlease enter the number of node to be viewed: \n");
	gets(temp);
	number = atoi(temp);

	length_Nodes = Length();

	if(! gptoFirstStudents )
	{
		DPrint("\nNo queue to search in it\n");
	}
	else
	{
		if(number > length_Nodes )
		{
			DPrint("\nThe Node number you entered exceeded the available Nodes\n");
		}

		while(pStudents)
		{
			if(number == count)
			{
				// print the data
				// navigate till half_no
				DPrint("The Node is at location %d contains these details:\n",count);

				DPrint("\tStudent ID: %d\n",pStudents->Student.ID);
				DPrint("\tStudent Name: %s\n",pStudents->Student.Name);
				DPrint("\tStudent Height: %f\n",pStudents->Student.Height);

				DPrint("=============");
				DPrint("\n");
				break;
			}
			++count;
			pStudents = pStudents->pNext;
		}
	}
}

void Nth_Node_From_End()
{
	uint8_t temp[40];
	uint32_t number = 0, count = 0, length_Nodes = 0;

	Node_t * pSlowStudents = gptoFirstStudents;
	Node_t * pFastStudents = gptoFirstStudents;


	DPrint("\nPlease enter the number of node to be viewed: \n");
	gets(temp);
	number = atoi(temp);

	length_Nodes = Length();

	if(! gptoFirstStudents )
	{
		DPrint("\nNo queue to search in it\n");
	}
	else
	{
		if(number > length_Nodes )
		{
			DPrint("\nThe Node number you entered exceeded the available Nodes\n");
		}

		while(pFastStudents)
		{
			if(number == count)
			{ // move both pointers together
				pSlowStudents = pSlowStudents->pNext;
				pFastStudents = pFastStudents->pNext;
			}
			else
			{
				++count;
				pFastStudents = pFastStudents->pNext;
			}
		}
		// print the data
		DPrint("The Node is at location %d from the end contains these details:\n",count);

		DPrint("\tStudent ID: %d\n",pSlowStudents->Student.ID);
		DPrint("\tStudent Name: %s\n",pSlowStudents->Student.Name);
		DPrint("\tStudent Height: %f\n",pSlowStudents->Student.Height);

		DPrint("=============");
		DPrint("\n");
	}
}

// iterative Method
uint32_t Length()
{
	Node_t * ptoStudent = gptoFirstStudents;
	uint32_t counter=0;

	if(!gptoFirstStudents)
	{
		return False;
	}
	else
	{
		while(ptoStudent)
		{
			ptoStudent = ptoStudent->pNext;
			++counter;
		}
		return counter;
	}
}



/*
 * Recursive Method
uint32_t Length(gptoFirstStudents)
{
	uint32_t counter=0;

	Node_t*	headd = gptoFirstStudents;

	if(!headd)
	{
		return False;
	}
	else
	{

		return 1 + Length(headd->pNext);
	}
}

*/

/*
// iterative Method
void Middle()
{
	uint32_t counter = 0;

	Node_t* pfastStudent = gptoFirstStudents;
	Node_t* pslowStudent = gptoFirstStudents;

	if(!gptoFirstStudents)
	{
		DPrint("Error no queue");
	}

	while(pfastStudent)
	{
		pslowStudent = pslowStudent->pNext;
		pfastStudent = pfastStudent->pNext->pNext;
		++counter;
	}

	DPrint("The Node in the Middle is at location %d contains these details:\n",counter);
	DPrint("\tStudent ID: %d\n",pslowStudent->Student.ID);
	DPrint("\tStudent Name: %s\n",pslowStudent->Student.Name);
	DPrint("\tStudent Height: %f\n",pslowStudent->Student.Height);

	DPrint("=============");
	DPrint("\n");
}
*/


// another method for iterative
void Middle()
{
	uint32_t no_nodes = 0, half_no=0, count=1;
	Node_t* ptoStudent = gptoFirstStudents;

	no_nodes = Length();

	if (!no_nodes)
	{
		DPrint("No Nodes or queue");
	}


	 // odd (5/2) = 2.5 int made it 2 ceil to make it 3 to be in the middle
	 // even (6/2) = 3 we need the second one which is 4
	 // both have the same equation which is number of (nodes/2) +1



	half_no = (uint32_t)(no_nodes/2) + 1;

	while(ptoStudent)
	{
		if(half_no == count)
		{
			// navigate till half_no
			DPrint("The Node in the Half is at location %d contains these details:\n",count);

			DPrint("\tStudent ID: %d\n",ptoStudent->Student.ID);
			DPrint("\tStudent Name: %s\n",ptoStudent->Student.Name);
			DPrint("\tStudent Height: %f\n",ptoStudent->Student.Height);

			DPrint("=============");
			DPrint("\n");
			break;
		}
		count++;
		ptoStudent = ptoStudent->pNext;
	}
}



void Check_circular()
{
	Node_t* pFast = gptoFirstStudents;
	Node_t* pslow = gptoFirstStudents;

	if(!gptoFirstStudents)
	{
		DPrint("\nNo Queue to check for circular loop possibility\n");
	}
	else
	{
		while( pFast && (pFast->pNext))
		{
			pslow = pslow->pNext;
			pFast = pFast->pNext->pNext;
			if( pFast == pslow)
			{
				DPrint("\nYes, there is infinity circular loop\n");
				break;
			}
		}
		DPrint("\nNo Circular loop found\n");
	}
}

void Reverse()
{
	Node_t* pPrev  = NULL;
	Node_t* Temp   = NULL;

	if(!gptoFirstStudents)
	{
		DPrint("no queue to be reversed");
	}
	else
	{
		while(gptoFirstStudents!=NULL)
		{
			Temp = gptoFirstStudents->pNext;
			gptoFirstStudents->pNext = pPrev;
			pPrev = gptoFirstStudents;
			gptoFirstStudents = Temp;
		}
		gptoFirstStudents = pPrev;
	}
	Display();
}










