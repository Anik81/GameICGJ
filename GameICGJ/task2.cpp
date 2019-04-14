# include "iGraphics.h"




int mov=500,movy=400;
int bike,poli;
int timer;
int ex=0,ey=10;
int lx ;
int ly ;



void iDraw()
{	iClear();
   iRotate(mov,movy,-45);
    iShowImage(mov,movy,100,100,bike);
	iUnRotate();


	iShowImage(ex,ey,100,100,poli);
}

void iMouseMove(int mx, int my)
{
}


void iPassiveMouse(int mx, int my)
{
}

void iMouse(int button, int state, int mx, int my)
{
	
}


void iKeyboard(unsigned char key)
{
	
	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
		if(key == 'd' && mov<1200)
		mov += 10;
		else
			 mov-=30;

	if(key == 'a' && mov>0)
		mov -= 10;
	     else
			 mov+=30;
		
	if(key == 'w' && movy<720)
		movy += 10;
	else
			 movy-=30;

	if(key =='s' && movy>0)
		movy -= 10;
	else
			 movy+=30;
		 
}


void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	
	if(key == GLUT_KEY_RIGHT && mov<1200)
		mov += 10;
	else mov-=30;

	if(key == GLUT_KEY_LEFT && mov>0)
		mov -= 10;
	else mov+=30;
		
	if(key == GLUT_KEY_UP && movy<720)
		movy += 10;
	else movy-=30;

	if(key == GLUT_KEY_DOWN && movy>0)
		movy -= 10;
	else movy+=30;

	
}
void police(){
	
	ex += lx;
	ey += ly;

	if(ex > 1280 || ex < 0)
		lx = -lx;
	if(ey > 720 || ey < 0)
		ly = -ly;


}
int main()
{   timer= iSetTimer(10,police);
	lx=5;
	ly=5;
	iInitialize(1280, 720, "Task2kb");

	bike = iLoadImage("images\\bike.png");
	poli = iLoadImage("images\\police.png");
	iStart();
	return 0;
}
