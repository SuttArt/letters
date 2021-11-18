#include "os.h"

void manageThreads(char x)
{
	PCB* cur = NULL; //address of current item
	if(gFirstItem == NULL) //empty list
	{
		gFirstItem = InitThread(x);
		gFirstItem = gLastItem;
	}
	else //search list
	{
		cur = gFirstItem;
	};
	//printf("\nSymbol %c", x);
};

PCB* InitThread (char e)
{
	PCB* p = (PCB*) malloc(gPCBsize); //Speicher reservierung
	//...
};