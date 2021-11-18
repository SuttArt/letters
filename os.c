// Main Programm

#include "os.h"

int main(void)
{
	char x = ',';
	Punkt p;
	
	init();
	
	gotoXY(0,22);
	printf("Type: ESC to exit");
	gotoXY(0,23);
	printf("Message");
	do
	{
		x = getch();
		if('a' <= x && x <= 'z')
		{
			manageThreads(x);
		}
	}
	while(x != K_ESC);

	/*
	gotoXY(11,11);
	putchar(x);
	//printf("%c",x);
	*/
	
	finish();
	return 0;
}