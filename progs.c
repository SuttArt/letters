#include "os.h"


void* ProgH(void* arg)
{
    //Zufallsgenerator
    srand(time(0));

    Punkt p;
    int j;
    PCB* current = (PCB*) arg;

    int Direction = rand()%2; //0 to left, 1 to right
    int Delay = 1+rand()%3; // 1..3

    p.X = 1+rand()%X_LENGTH; //1..60
    p.Y = 1+rand()%Y_LENGTH; //1..18
    while (current -> Continue == 1) //one step
    {
        if(current -> Activity)
        {
            hide(p);

            if((p.X == 0) && (Direction == 0) ||
               (p.X == X_LENGTH) && (Direction ==1))
            {
                Direction = !Direction;
            }

            if(Direction)
            {
                p.X++;
            }
            else
            {
                p.X--;
            }
            show(p, current -> Face);
            sleep(Delay);

        }

    }
    return 0;

}

void* ProgV(void* arg)
{
    //Zufallsgenerator
    srand(time(0));

    Punkt p;
    int j;
    PCB* current = (PCB*) arg;

    int Direction = rand()%2; //0 to left, 1 to right
    int Delay = 1+rand()%3; // 1..3

    p.X = 1+rand()%X_LENGTH; //1..60
    p.Y = 1+rand()%Y_LENGTH; //1..18
    while (current -> Continue == 1) //one step
    {
        if(current -> Activity)
        {
            hide(p);

            if((p.Y == 0) && (Direction == 0) ||
               (p.Y == Y_LENGTH) && (Direction ==1))
            {
                Direction = !Direction;
            }

            if(Direction)
            {
                p.Y++;
            }
            else
            {
                p.Y--;
            }
            show(p, current -> Face);
            sleep(Delay);

        }

    }
    return 0;

}

void* ProgR(void* arg) //dummy
{


}
