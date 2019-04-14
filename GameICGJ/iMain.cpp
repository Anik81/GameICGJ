
#include "iGraphics.h"
#include "mymenu.h"
#include "player.h"
#include "GamePlay.h"
#include "Enemy.h"

void Fire();
//PLAYER MOVEMENT

int tim1,tim2, tim3, tim4,tim5;      //Initialization of Timers                        
int score=0,life=5;                  //Score & Life 
greenstudent gstu[3];                //Structure Array for Elements
redstudent rstu[3];
teachers t[3];
char sc1[20],sc2[20];



//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

void iDraw()
{
    iClear();
    iShowImage(0,0,1200,800,imgSecondbg);      //OPENS FIRST PAGE
    iShowImage(520,200,280,400,imgEnter);        //PRINTS THE INSTRUCTION TO PRESS ENTER IN FIRST PAGE

    if (enterCHK==2)
    {
        Menu();                                           //OPENS MENU SCREEN         ::LOCATED - MY MENU HEADER
        MenuHover();                                   //CHNAGES COLOR OF MENU ITEMS WHEN MOUSE IS MOVED OVER THEM       ::LOCATED - MY MENU HEADER
    }

    if(storyCHK==2)
    {
        iShowImage(0,0,1200,800,imgStoryMain);                    //OPENS STORY SCREEN UPON CLICK ON STORY
        iShowImage(30,680,250,100,bButton);
    }

    if(scoreCHK==2)
    {

        iSetColor(202,255,42);
        iFilledRectangle(0,0,1200,800);
        iSetColor(0,0,0);
        FILE *scoreMain2 = fopen("playerScore.txt","r");                                 //SAVES THE NAME IN A FILE FOR FUTURE USE
        fscanf(scoreMain2,"%s",sc1);
        FILE *playerID2 = fopen("playerData.txt","r");                                 //SAVES THE NAME IN A FILE FOR FUTURE USE
        fscanf(playerID2,"%s    =",playerCopy);

        iText(500,550,"High Score",GLUT_BITMAP_TIMES_ROMAN_24);                        //Show Score

        iText(600,450,sc1,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(400,450,playerCopy,GLUT_BITMAP_TIMES_ROMAN_24);

        fclose(scoreMain2);
        fclose(playerID2);

        iShowImage(30,680,250,100,bButton);
    }                                                            //OPENS SCORE SCREEN UPON CLICK ON HIGHSCORE

    if(controlCHK==2)
    {
        iShowImage(0,0,1200,800,imgControlMain);                    //OPENS INSTRUCTION SCREEN UPON CLICK ON CONTROLS
        iShowImage(30,680,250,100,bButton);
    }

    if(usCHK==2)
    {
        iShowImage(0,0,1200,800,imgUs);                          //OPENS CREDIT PAGE UPON CLICK ON ABOUT US
        iShowImage(30,680,250,100,bButton);
    }

    if(Gameover==2)
    {
        iShowImage(0,0,1200,800,gover);                          //OPENS CREDIT PAGE UPON CLICK ON ABOUT US

        iText(600,720,"SCORE : ",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(700,720,sc1,GLUT_BITMAP_TIMES_ROMAN_24);

        iShowImage(30,680,250,100,bButton);
    }

    // DRAWS TEXT BOX IN PLAY GAME FOR NAME INPUT


	//Enterning The Gameplay
    if(CHK==2)
    {
        iShowImage(0,0,1200,800,imgGameplayBG);
        iShowImage(moveX,moveY,250,250,imgGunman);
        iSetColor(202,241,42);
        iFilledRectangle(270,0,10,800);

        iShowImage(gstu[0].xpos,gstu[0].ypos,55,110,imgGreenStu);
        iShowImage(gstu[1].xpos,gstu[1].ypos,55,110,imgGreenStu);              //Green Student Show
        iShowImage(gstu[2].xpos,gstu[2].ypos,55,110,imgGreenStu);

        iShowImage(rstu[0].xpos,rstu[0].ypos,55,110,imgRedStu);
        iShowImage(rstu[1].xpos,rstu[1].ypos,55,110,imgRedStu);               //Red Student Show
        iShowImage(rstu[2].xpos,rstu[2].ypos,55,110,imgRedStu);

        iShowImage(t[0].xpos,t[0].ypos,55,110,imgTeacher);
        iShowImage(t[1].xpos,t[1].ypos,55,110,imgTeacher);                   //Teacher Show
        iShowImage(t[2].xpos,t[2].ypos,55,110,imgTeacher);

        iShowImage (bulletX[0],bulletY[0],80,45,imgBullet);
        iShowImage (bulletX[1],bulletY[1],80,45,imgBullet);
        iShowImage (bulletX[2],bulletY[2],80,45,imgBullet);
        iShowImage (bulletX[3],bulletY[3],80,45,imgBullet);                //Bullet Show
        iShowImage (bulletX[4],bulletY[4],80,45,imgBullet);
        iShowImage (bulletX[5],bulletY[5],80,45,imgBullet);

        Fire();                                                     
        fl=0;

		// Loop For Levels,Speed & Total Collisions for every Characters vs Bullet
        for (int j=0; j<7; j++)
        {
            if (score<=100)
            {
                lvl=1;
            }
            else if (score>100&&score<=200)
            {
                lvl=2;
            }
            else if (score>200)
            {
                lvl=3;
            }
            iSetColor(202,241,42);
            iText(100,720,"LIFE : ",GLUT_BITMAP_TIMES_ROMAN_24);

            if(life>4)
                iText(160,720,"5",GLUT_BITMAP_TIMES_ROMAN_24);
            else
                iText(160,720,sc2,GLUT_BITMAP_TIMES_ROMAN_24);


            iText(980,720,"SCORE : ",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(1140,720,sc1,GLUT_BITMAP_TIMES_ROMAN_24);


            for (int e=0; e<3; e++)
            {
                if(gstu[e].collision(bulletX[j],bulletY[j]))                    //Collision of Green Student
                {
                    score-=10;
                    bulletX[j] = 1300;
                    gstu[e].xpos = 1200;
                    gstu[e].ypos = 100+rand()%450;

                    sprintf(sc1,"%d",score);

                }
				if(rstu[e].xpos<=270)
                    {
				     rstu[e].xpos = 1300;
                     life--;
				    sprintf(sc2,"%d",life);
				 if(life==0){
                    Gameover=2;
                    CHK=1;
                      }
                    }
                if(rstu[e].collision(bulletX[j],bulletY[j]))                   //Collision of Red Student
                {
                    
                    score+=10;
                    bulletX[j] = 1300;
                    rstu[e].xpos = 1200+rand()%40;
                    rstu[e].ypos = 100+rand()%450;
                    sprintf(sc1,"%d",score);

                }
                if(t[e].collision(bulletX[j],bulletY[j]))                    //Collision of Teacher
                {

                    bulletX[j] = 1300;
                    t[e].xpos = 1200;
                    t[e].ypos = 100+rand()%450;
					 life--;
                    sprintf(sc2,"%d",life);
                   
                    if(life==0)
                    {
                        Gameover=2;
                        CHK=1;
                    }
                }
            }

        }
        FILE *scoreMain = fopen("playerScore.txt","w");                                 //SAVES THE NAME IN A FILE FOR FUTURE USE
        fprintf(scoreMain,"%s",sc1);
        fclose(scoreMain);



        if(r==1)
        {
            iSetColor(255, 255, 255);
            iText(550, 430, "Press 'R' to RELOAD",GLUT_BITMAP_TIMES_ROMAN_24);             //Reloading The Gun with 5 Bullets
        }


    }

    //SHOWS GAMEplay AFTER ENTERING NAme

    if(playerCHK == 2)
    {
        iShowImage(0,0,1200,800,index);                   //OPENS BACKGROUND SCREEN IN NAME INPUT
        drawTextBox();                                     //DRAWS TEXT BOX IN PLAY GAME FOR NAME INPUT                :: LOCATED - PLAYER HEADER
        iSetColor(255, 255, 255);
        iText(580, 430, player);                          //PRINTS INSTRUCTION LINE IN NAME_INPUT SCREEN
    }



}






/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{
    dragMX = mx;
    dragMY = my;
}
//*******************************************************************ipassiveMouse***********************************************************************//


/*function iPassiveMouse() is called when the user moves the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iPassiveMouse(int mx, int my)
{
    cursorMX = mx;
    cursorMY = my;
}

void iMouse(int button, int state, int mx, int my)
{

    if(enterCHK==2)
    {

        MenuClick(button,state);              //FUCTIONS IN MENU INTERFACE                          ::LOCATED - MY MENU HEADER
        FindText(button,state,mx,my);                   //FUNCTIONS IN FINDING TEXT BOX IN NAME_INPUT SCREEN                :: LOCATED - PLAYER HEADER
    }



}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{


    if (key == '\r')
    {
        enterCHK=2;                    //TAKES USER TO MENU FROM OPENNING SCREEN
    }

    inputPlayer(key);
    //FUNCTION THAT SENDS INPUT FOR TAKING PLAYER NAME IN NAME_INPUT SCREEN    :: LOCATED - PLAYER HEADER

    fire(key);
	// Game Pause
    if (key == 'p')        
    {
        iPauseTimer(0);
        iPauseTimer(1);
        iPauseTimer(2);
        iPauseTimer(3);
        iPauseTimer(4);

    }
	//Resume Game
    if (key == 'r')
    {
        iResumeTimer(0);
        iResumeTimer(1);
        iResumeTimer(2);
        iResumeTimer(3);
        iResumeTimer(4);
    }

}


/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

    hero(key);
    if(key==GLUT_KEY_END)     
    {
        CHK=1;                                  //Exit to Main Menu
    }

}
void greenstudentdec()
{
    gstu[0].GreenStu();
    gstu[1].GreenStu();                         
    gstu[2].GreenStu();

}
void redstudentdec()
{
    rstu[0].RedStu();
    rstu[1].RedStu();
    rstu[2].RedStu();

}
void teacherdec()
{
    t[0].Teacher();
    t[1].Teacher();
    t[2].Teacher();

}


void Fire()
{
    if(fl==1)
    {
        iShowImage(bX+30,moveY+bY+10,40,30,imgFire);


    }
}
int main()
{
	//All Timers 
    tim2=iSetTimer(.5,redstudentdec);
    tim1=iSetTimer(30,greenstudentdec);
    tim3=iSetTimer(60,teacherdec);
    tim4=iSetTimer(30,bulletshow);
    tim5=iSetTimer(.7,Fire);
    


    player[0]= 0;
    //NAME OF THE PLAYER IS KEPT CLEAR

    iInitialize(1200,800, "FireWall of AUST");

    loadImage();    //CALLS THE FUNCTION TO LOAD ALL THE NECESSARY IMAGES        ::LOCATED - MY MENU HEADER

	//Showing Enemy Randomly
    for (int l=0; l<3; l++)
    {
        t[l]=teachers(1200,100+rand()%450,imgTeacher);
        gstu[l]=greenstudent(1200,450,imgGreenStu);
        rstu[l]=redstudent(1200,550,imgRedStu);
    }


    iStart();


    return 0;
}
