// Main Programm

#include "os.h"

int main(void)
{
	char x = ',';
	Punkt p;
	
	init();
	
	printf("\nEin Symbol eintippen: \n");
	x = getch();
	printf("\nIhr Symbol %c ist drin ", x);
	
	p.X = 11;
	p.Y = 11;
	show(p,x);
	sleep(3);
	hide(p);
	
	p.X = 5;
	p.Y = 5;
	show(p,x);

	/*
	gotoXY(11,11);
	putchar(x);
	//printf("%c",x);
	*/
	
	finish();
	return 0;
}