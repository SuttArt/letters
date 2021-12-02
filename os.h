//Diese Datei wird überall inkluediert
#include <stdio.h>
#include <windows.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

//Precompiler-Variablen
#define K_ESC 27
#define K_SPACE 32
#define K_ENTER 13
#define X_LENGTH 60
#define Y_LENGTH 18

//Datatypes
typedef struct PunktSTRU
{
	int X;
	int Y;
}
Punkt;

typedef struct PCB//Process Control Block
{
	pthread_t tID; // ID of thread
	char Face; //Letter of thread
	char Prog; //H,V,R = ProgH, ProgV, ProgR
    int Continue; //0 or 1 thread is correct to finish
    char Activity; //0 or 1 letter does not run temporary
	struct PCB* next;
}
PCB;

//Protorypen
void gotoXY (int x, int y);
void Cursor (int x);
void init(void);
void finish(void);
int getch(void);
void show(Punkt p, char symbol);
void hide(Punkt p);
void manageThreads(char x);
PCB* InitThread (char e);
void RunThread(PCB* p);
void* ProgH(void* arg);
void* ProgV(void* arg);
void* ProgR(void* arg);
void TaskMan(void);

//global Variables
PCB* gFirstItem; // Adresse des 1. Knoten in der Liste
PCB* gLastItem;	 // Adresse des letzte Knoten in der Liste
int gPCBsize; 	 //Größe von PCB
pthread_mutex_t gScreen;