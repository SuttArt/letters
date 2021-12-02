#include "os.h"

void init(void)
{
	gFirstItem = NULL;
	gLastItem = NULL;
	gPCBsize = sizeof(PCB);
    pthread_mutex_init(&gScreen, NULL);
	Cursor(0); //Cursor OFF
    srand(time(0));
};

void finish(void)
{
    PCB* cur = gFirstItem;
    PCB* tmp = NULL;

    while (cur != NULL)
    {
        cur -> Continue = 0;
        cur = cur -> next;
    }

    cur = gFirstItem;
    while (cur != NULL)
    {
        pthread_join(cur ->tID, NULL);
        cur = cur -> next;
    }

    cur = gFirstItem;
    while (cur != NULL)
    {
        tmp = cur -> next;
        free(cur);
        cur = tmp;
    }
	Cursor(1); //Cursor ON
};