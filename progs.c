#include "os.h"


void* ProgH(void* arg)
{
    Punkt p;
    int j;
    PCB* current = (PCB*) arg;

    p.X = 5;
    p.Y = 5;
    for(j=1;j<=10; j++)
    {
        show(p, current -> Face);
        sleep(2);
        hide(p);
        p.X++;
    }
    return 0;
}