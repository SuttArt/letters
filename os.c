// Main Programm

#include "os.h"

int main(void)
{
	char x = ',';
	Punkt p;
	
	init();

    pthread_mutex_lock(&gScreen);

    gotoXY(0,22);
	printf("Type: ESC to exit");
	gotoXY(0,23);

    pthread_mutex_unlock(&gScreen);

    printf("Message");
	do
	{
		x = getch();
		if('a' <= x && x <= 'z')
		{
			manageThreads(x);
		}
        if(x == K_SPACE || x == K_ENTER)
        {
            TaskMan();
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