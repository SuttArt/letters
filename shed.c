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
    switch (rand()%3)
    {
        case 0:
            p -> Prog = 'H';
            break;
        case 2:
            p -> Prog = 'V';
            break;
        case 1:
            p -> Prog = 'R';
            break;
        default:
            p -> Prog = 'H';
            break;
    }
    p -> Continue = 1;
    p -> Activity = 1;
    p -> next = NULL;
    RunThread(p);
    return p;
};

void RunThread(PCB* p)
{
    pthread_t ID;
    switch (p->Prog) {
        case 'H':
            pthread_create(&ID, NULL, &ProgH, p);
            break;
        case 'V':
            pthread_create(&ID, NULL, &ProgV, p);
            break;
        case 'R':
            pthread_create(&ID, NULL, &ProgR, p);
            break;
        default:
            pthread_create(&ID, NULL, &ProgH, p);
            break;
    }
    p -> tID = ID;
}


void TaskMan(void)
{
    PCB* cur = gFirstItem;

    int x = 2+X_LENGTH;
    int y = 0;
    pthread_mutex_lock(&gScreen);
    gotoXY(x,y);
    printf("Info from Task Manager");

    y++;
    gotoXY(x,y);
    printf("Face Act Prog");
    while (cur != NULL)
    {
        y++;
        gotoXY(x,y);
        printf(" %c    %d    %c",cur -> Face, cur -> Activity, cur -> Prog);
        cur = cur -> next;
    }

    pthread_mutex_unlock(&gScreen);
}