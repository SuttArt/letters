#include "os.h"

void init(void)
{
	gFirstItem = NULL;
	gLastItem = NULL;
	gPCBsize = sizeof(PCB);
	Cursor(0); //Cursor OFF
};

void finish(void)
{
	Cursor(1); //Cursor ON
};