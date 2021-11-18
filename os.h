//Diese Datei wird überall inkluediert
#include <stdio.h>
#include <windows.h>
#include <pthread.h>
#include <unistd.h>
//#include <times.h>

//Precompiler-Variablen
#define K_ESC 27

//Datatypes
typedef struct PunktSTRU
{
	int X;
	int Y;
}
Punkt;

//Protorypen
void gotoXY (int x, int y);
void Cursor (int x);
void init(void);
void finish(void);
int getch(void);
void show(Punkt p, char symbol);
void hide(Punkt p);
void manageThreads(char x);