#include "exListe.h"

int main(void)
{
    int inpt = 0;
    Node* first = NULL; //first Node of the List
/*
 * Node* first = NULL; //first Node of the List
 * Node * first = NULL; //first Node of the List
 * Node *first = NULL; //first Node of the List
 * Node*first = NULL; //first Node of the List
*/
    Node* last = NULL; //last Node of the List
    Node* current = NULL; //current/working Node of the List
    Node* x = NULL; //temporary Node of the List
    int NodeSize = sizeof (Node);

    printf("It works!");

    do
    {
        printf("\nPositive Zahl eingeben --> ");
        //scanf("%d",&inpt);
        IN(inpt);
        if WEITER //(inpt > 0) //generate the list
        {
            current = (Node*) malloc(NodeSize);//Speicher rezervierung
            //current - eine adresse, deswegen:
            current -> Z = inpt;
            //währe current - eine Structur, dann:
            //current.Z = inpt;
            current -> next = NULL;
            //list is empty
            if (first == NULL)  first = current;
            else                last -> next = current;

            last = current;

        }
    }
    while WEITER; //(inpt > 0 ); //list is ready

    //show the list, walking through the List
    current = first;
    while (current != NULL)
    {
        printf("\n== my address: %p == my number: %d == address: %p",current ,current->Z, current->next);
        current = current->next;
    }

    //delete the List
    current = first;
    while (current != NULL)
    {
        printf("\nFreigabe: %d", current->Z);
        x = current->next;
        free(current);
        current = x;
    }

    return 0;
}