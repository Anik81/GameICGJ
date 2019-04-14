#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED



char player[100], playerCopy[100];
int len=0;
int playerCHK=1;

//CALLED IN MAIN FUCTION TO DRAW TEXT BOX IN TAKING INPUT OF PLAYER NAME

void drawTextBox()
{
    iSetColor(0, 0, 0);
    iFilledRectangle(500,400, 250, 50);
    iText(510, 330, "Click to activate the box, enter to finish.");
    iSetColor(255, 0, 0);
    iText(505, 430, "ENTER NAME :");
}

//CALLED IN MAIN FUCTION TO TAKE INPUT OF PLAYER

void inputPlayer(unsigned char key)
{
    int i;
    if(playerCHK == 2)
    {
        if(key == '\r')
        {
            playerCHK = 1;
            strcpy(playerCopy,player);
            FILE *playerID = fopen("playerData.txt","w");                                 //SAVES THE NAME IN A FILE FOR FUTURE USE
            fprintf(playerID,"%s",playerCopy);
            for(i = 0; i < len; i++)
                player[i] = 0;
            len = 0;
            fclose(playerID);
            CHK=2;
        }
        else
        {
            player[len] = key;
            len++;
        }
    }
}

//CALLED IN MAIN FUCTION TO START TAKING NAME INPUT IF CLICKED IN BOX

void FindText(int button, int state, int mx, int my)
{ 
	
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if (enterCHK==2 && CHK==1 && storyCHK==1 && scoreCHK==1 && controlCHK==1 && usCHK==1 && cursorMX>650 && cursorMX<865 &&cursorMY>435 && cursorMY<=500)
        {
            playerCHK = 2;                                                                               //OPENS START GAME
        }
    }


    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        playerCHK=1;                                     // CLOSE START_GAME
                                                  // RETURNS TO MENU
    }

}
#endif // PLAYER_H_INCLUDED
