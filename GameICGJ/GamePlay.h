#ifndef GAMEPLAY_H_INCLUDED
#define GAMEPLAY_H_INCLUDED
#include "iGraphics.h"
int fl=0;


int bulletX[6],bulletY[6];                   //Array for Bullets
int moveY=300,moveX=30;                      //Movement of the shooter
int r=2;                                     //Controlling Bullet Array
int g=0;
int i=0,k=0,bX=197,bY=103;                   //Controlling loops and position of Bullet

void hero(unsigned char key)                      //Controlling movement of the shooter
{
    if(key == GLUT_KEY_UP && moveY<700)
        moveY += 3;
    else
        moveY-=30;

    if(key == GLUT_KEY_DOWN && moveY>0)
        moveY -= 3;
    else
        moveY+=30;
}

void fire( int key)                           //Bullet Fire
{

    if(key == 'r')
    {
        r = 2;
        i=0;
    }
    if(key == 'f' && r==2)
    {
        fl=1;
        i++;
        bulletX[i]=bX;
        bulletY[i]=moveY+bY;
		//PlaySound("music\\gunshot.wav", NULL, SND_ASYNC);
    }
    if(i==5)
    {
        r=1;
        i=0;
    }
}



void bulletshow()                           //Controlling Bullet speed
{
    bulletX[0]=bulletX[0]+8;
    bulletX[1]=bulletX[1]+8;
    bulletX[2]=bulletX[2]+8;
    bulletX[3]=bulletX[3]+8;
    bulletX[4]=bulletX[4]+8;
    bulletX[5]=bulletX[5]+8;
}



#endif // PLAYER_H_INCLUDED

