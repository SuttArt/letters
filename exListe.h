#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int Z;
    struct Node* next; //address of the next node
}
Node; //this is ONE node in the List

#define WEITER (inpt > 0 )
#define IN(x) scanf("%d", &x)

