#include "os.h"

void gotoXY (int x, int y)
{
  COORD k;
  k.X = x;
  k.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), k);
}

void Cursor(int x)  //  cursor 1/0 = ON/OFF
{
    if ( x == 0 || x == 1 )
    {
        HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO info;
        info.dwSize = 10;  //  size of cursor
        info.bVisible = x;
        SetConsoleCursorInfo(consoleHandle, &info);
    }
}

/*
char inkey (void)
{
    char x = '\0';
    if (kbhit()) x = getch();
    return x;
}

*/

void show(Punkt p, char symbol)
{
    pthread_mutex_lock(&gScreen);//Nicht in PA verwenden! Selber suchen! Oder doch nicht...
	gotoXY(p.X, p.Y);
	putchar(symbol);
    pthread_mutex_unlock(&gScreen);
};

void hide(Punkt p)
{
	show(p,' ');
};