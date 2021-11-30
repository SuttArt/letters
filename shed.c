#include "os.h"

void manageThreads(char fc)
{
	PCB* cur = NULL; //address of current item
    int found;

	if(gFirstItem == NULL) //empty list
	{
		gFirstItem = InitThread(fc);
        gLastItem = gFirstItem;
	}
	else //search list
	{
		cur = gFirstItem;
        do
        {
            if(cur -> Face == fc)
            {
                found = 1; //Face is in the list
                cur -> Activity = !(cur -> Activity);
            }
            cur = cur -> next;
        } while ((!found) && (cur != NULL));

        if(!found) //append a new Node
        {
            cur = InitThread(fc);
            gLastItem -> next =  cur; //append to the List
            gLastItem = cur;
        }
	};
};

PCB* InitThread (char fc)
{
	PCB* p = (PCB*) malloc(gPCBsize); //Speicher reservierung
	// initialize nodes
    p -> Face = fc;
    p -> Prog = 'H';
    p -> Continue = 1;
    p -> Activity = 1;
    p -> next = NULL;
    RunThread(p);
    return p;
};

void RunThread(PCB* p)
{
    pthread_t ID;
    pthread_create(&ID, NULL, &ProgH, p);
    p -> tID = ID;

}