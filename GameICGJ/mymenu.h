#ifndef MYMENU_H_INCLUDED
#define MYMENU_H_INCLUDED



//VARIABLES DECLARED FOR DIFFERENT IMAGES REQUIRED FOR THE GAME

int enterCHK=1,storyCHK=1,scoreCHK=1,usCHK=1,controlCHK=1,CHK=1,Gameover=1;
int imgMenubg, imgSecondbg,imgEnter,imgControlMain,imgScoreMain,imgUs,imgStoryMain,imgUC,imgID,index;
int imgStory, imgStartGame, imgHighScore, imgControls, imgAboutUs, imgExit;
int imggStory, imggStartGame, imggHighScore, imggControls, imggAboutUs, imggExit;
int bButton,imgGameplayBG,imgGunman,imgBullet, imgFire;
int imgGreenStu, imgRedStu, imgTeacher, imgSalam,gover;
// VARIABLES DECLARED FOR MOUSE FUNCTIONS IN MAIN FILE

int dragMX=0,dragMY=0;
int cursorMX,cursorMY;

//CALLED IN MAIN FUCTION TO SHOW MENU AFTER OPENNING SCREEN

void Menu()
{
    iShowImage(0,0,1200,800,imgMenubg);

    iShowImage(360,550,500,250,imgID);
    iShowImage(450,400,300,250,imgStory);
    iShowImage(450,330,300,250,imgStartGame);
    iShowImage(450,260,300,250,imgHighScore);
    iShowImage(450,190,300,250,imgControls);
    iShowImage(450,130,300,250,imgAboutUs);
    iShowImage(450,70,300,250,imgExit);
}

//CALLED IN MAIN FUCTION TO CHANGE COLOR OF MENU ITEMS WHEN MOUSE HOVERS OVER THEM

void MenuHover()
{

    if (cursorMX>650 && cursorMX<885 && cursorMY>520 && cursorMY<555)
    {
        iShowImage(450,400,300,250,imggStory);
    }
    if (cursorMX>650 && cursorMX<865 &&cursorMY>435 && cursorMY<=500)
    {
        iShowImage(450,330,300,250,imggStartGame);
    }
    if (cursorMX>670 && cursorMX<870 && cursorMY>360 && cursorMY<415)
    {
        iShowImage(450,260,300,250,imggHighScore);
    }
    if (cursorMX>620 && cursorMX<930 && cursorMY>300 && cursorMY<=330)
    {
        iShowImage(450,190,300,250,imggControls);
    }
    if (cursorMX>620 && cursorMX<920 && cursorMY>240 && cursorMY<275)
    {
        iShowImage(450,130,300,250,imggAboutUs);
    }
    if (cursorMX>655 && cursorMX<875 && cursorMY>180 && cursorMY<205)
    {
        iShowImage(450,70,300,250,imggExit);
    }

}

//CALLED IN MAIN FUCTION TO GET ACTION FROM MENU ITEMS

void MenuClick(int button, int state)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {

        if (cursorMX>650 && cursorMX<885 && cursorMY>520 && cursorMY<555)                                  //COLLISIONS USED IN THE WHOLE FUNCTION TO GET ACTION FROM MOUSE CLICK
        {
            //FROM EACH OF THE ITEMS OF MENU
            storyCHK=2;

        }
        if (cursorMX>650 && cursorMX<865 &&cursorMY>435 && cursorMY<=500)
        {
            //   CHK=2;
        }
        if (cursorMX>670 && cursorMX<870 && cursorMY>360 && cursorMY<415)
        {
            scoreCHK=2;
        }
        if (cursorMX>620 && cursorMX<930 && cursorMY>300 && cursorMY<=330)
        {
            controlCHK=2;
        }
        if (cursorMX>620 && cursorMX<920 && cursorMY>240 && cursorMY<275)
        {
            usCHK=2;
        }
        if (cursorMX>655 && cursorMX<875 && cursorMY>180 && cursorMY<205)
        {
            exit(0);
        }

        if (cursorMX>20 && cursorMX<300 &&cursorMY>650 && cursorMY<750)
        {
            storyCHK=1;
            scoreCHK=1;
            controlCHK=1;
            usCHK=1;
            CHK=1;
            Gameover=1;
        }

    }

    //RE_CHECKS BACK THE CHANGED VALUE TO GET BACK TO PREVIOUS SCREEN AFTER HITTING EACH MENU ITEM

    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        storyCHK=1;
        scoreCHK=1;
        controlCHK=1;
        usCHK=1;
        Gameover=1;
    }
}

//CALLED IN MAIN FUCTION TO LAOD ALL THE NECESSARY IMAGE

void loadImage()
{
    imgMenubg = iLoadImage("images//imgMenubg.jpg");
    imgStory = iLoadImage("images//imgStory.png");
    imgStartGame = iLoadImage("images//imgStartGame.png");
    imgHighScore = iLoadImage("images//imgHighScore.png");
    imgControls = iLoadImage("images//imgControls.png");
    imgAboutUs = iLoadImage("images//imgAboutUs.png");
    imgExit = iLoadImage("images//imgExit.png");
    imggStory = iLoadImage("images//imggStory.png");
    imggStartGame = iLoadImage("images//imggStartGame.png");
    imggHighScore = iLoadImage("images//imggHighScore.png");
    imggControls = iLoadImage("images//imggControls.png");
    imggAboutUs = iLoadImage("images//imggAboutUs.png");
    imggExit = iLoadImage("images//imggExit.png");
    imgSecondbg = iLoadImage("images//imgSecondbg.jpg");
    imgEnter = iLoadImage("images//imgEnter.png");
    imgControlMain = iLoadImage("images//imgControlMain.jpeg");
    imgScoreMain = iLoadImage("images//imgScoreMain.png");
    imgUs = iLoadImage("images//imgUs.png");
    imgStoryMain = iLoadImage("images//imgStoryMain.jpg");
    imgID = iLoadImage("images//imgID.png");
    index = iLoadImage("images//index.jpg");
    bButton =iLoadImage("images//BackButton.png");
    imgGameplayBG = iLoadImage("images//GameplayBG.jpg");
    imgGunman =  iLoadImage("images//Gunman.png");
    imgBullet = iLoadImage("images//Bullet.png");
    imgFire = iLoadImage("images//imgFire.png");
    imgGreenStu = iLoadImage("images//imgGreenStu.png");
    imgRedStu = iLoadImage("images//imgRedStu.png");
    imgTeacher = iLoadImage("images//imgTeacher.png");    
    gover = iLoadImage("images//gover.jpg");
}

#endif // MYMENU_H_INCLUDED

