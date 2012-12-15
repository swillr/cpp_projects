#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <stdlib.h>

int tampx=0,tampy=0;

void second(int x, int y)
{
	int kk=1;
	int aa=1;

	setcolor(aa);
	setlinestyle(0,1,0);

	for(kk =1;kk<=70;kk++)
	{
		line(x-kk,y,x+kk,y);
		line(x,y-kk,x,y+kk);
		line(x-aa,y-aa,x+aa,y+aa);
		line(x+aa,y-aa,x-aa,y+aa);
		if(kk>10)
		{
			setcolor(0);
			line(x-(kk-10),y,x+(kk-10),y);
			line(x,y-(kk-10),x,y+(kk-10));
			line(x-(aa-10),y-(aa-10),x+(aa-10),y+(aa-10));
			line(x+(aa-10),y-(aa-10),x-(aa-10),y+(aa-10));
			delay(10);
			setcolor(aa);
		}

		aa++;
		if(kk%3==0)
		aa--;
	}

	setcolor(0);
	line(x-kk,y,x+kk,y);
	line(x,y-kk,x,y+kk);
	line(x-aa,y-aa,x+aa,y+aa);
	line(x+aa,y-aa,x-aa,y+aa);
	setcolor(aa);

}


void main(void)
{

int gdriver = VGA, gmode = VGAHI;
initgraph(&gdriver,&gmode,"c:\\tc\\bgi");

cleardevice();

do
{
	randomize();

	tampx=rand()%500+80;
	tampy=rand()%350+80;

	second(tampx,tampy);

}while(!kbhit());

getch();
}