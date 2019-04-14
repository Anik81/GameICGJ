#include "iGraphics.h"
#include "myheader.h"

int bullet;
int timer;
int x[100];
int y[100];
int total;
int dragMX=0,dragMY=0;


void drawBullet(int p, int q)
{   iRotate(p,q,90);
	iShowImage(p, q,80, 100, bullet);
	iUnRotate();	
}



void iDraw()
{

	iClear();
	iShowImage(cursorMX, cursorMY,80, 100,bullet);

	iSetColor(255, 100, 10);
	iFilledCircle(ex, ey, 20,100);
	
	int i;
	for(i = 0; i < total; i++)
	  {
		drawBullet(x[i], y[i]);
      }

	iText(400, 10, "Left click to draw, Right click to delete.");
}



void iMouseMove(int mx, int my)
{
	dragMX = mx;
	dragMY = my;
}


void iPassiveMouse(int mx, int my)
{
    cursorMX = mx;
    cursorMY = my;

}


void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(total < 100)
		{
			x[total] = mx;
			y[total] = my;
			total++;
		}
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		if(total>0)
		{
			total--;
		}
	}
}


void iSpecialKeyboard(unsigned char key)
{

}
void iKeyboard(unsigned char key)
{	
	
}




int main()
{
	
	timer= iSetTimer(10, enemyChange);
	total = 0;

	lx=5;
	ly=1;

	iInitialize(1280, 720, "task1mouse");

	bullet = iLoadImage("images//bike.png");

	iStart();

	return 0;
}
