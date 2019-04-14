
#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

int lvl;
struct greenstudent            //Structure For Green Student
{
    int xpos;
    int ypos;
    int image;

    greenstudent()             //Empty Constructor
    {
    }

    greenstudent(int xpos, int ypos,int image)   //Parameterized Constructor
    {
        this->xpos=xpos;
        this->ypos=ypos;
        this->image=image;

    }
    int collision(int bulletx, int bullety)      //Collision For Greeen Student vs Bullet
    {
        if((bulletx+80>xpos && bulletx+80<xpos+110)&&(bullety+45>ypos && bullety+45<ypos+140))
        {
            bulletx=1300;
            printf("score");
            xpos=1200;
            ypos=100+rand()%450;
            return 1;

        }
        else
            return 0;
    }
    void GreenStu()             //Controling Green Student Speed in different levels
    {
        if (lvl==1)
            xpos--;
        else if (lvl==2)
            xpos-=2;
        else if (lvl==3)
            xpos-=3;

        if(xpos==0 )
        {
            xpos= 1200;

        }

    }


};

struct redstudent                                     //Structure For Red Student
{
    int xpos;
    int ypos;
    int image;

    redstudent()
    {
    }

    redstudent(int xpos, int ypos,int image)
    {
        this->xpos=xpos;
        this->ypos=ypos;
        this->image=image;

    }
    int collision(int bulletx, int bullety)             //Collision For Red Student vs Bullet
    {
        if((bulletx+80>xpos && bulletx+80<xpos+110)&&(bullety+45>ypos && bullety+45<ypos+140))
        {
            bulletx=1300;

            printf("score");
            xpos=1200;
            ypos=100+rand()%450;
            return 1;

        }
        else
            return 0;
    }
    void RedStu()                                   //Controling Red Student Speed in different levels
    {
        if (lvl==1)
            xpos--;
        else if (lvl==2)
            xpos-=2;
        else if (lvl==3)
            xpos-=3;

        if(xpos==0 )
        {
            xpos= 1200;

        }
    }
};

struct teachers                                     //Structure For Teacher
{
    int xpos;
    int ypos;
    int image;

    teachers()
    {
    }

    teachers(int xpos, int ypos,int image)
    {
        this->xpos=xpos;
        this->ypos=ypos;
        this->image=image;

    }
    int collision(int bulletx, int bullety)                         //Collision For Teacher vs Bullet
    {
        if((bulletx+80>xpos && bulletx+80<xpos+110)&&(bullety+45>ypos && bullety+45<ypos+140))
        {
            bulletx=1300;

            printf("score");
            xpos=1200;
            ypos=100+rand()%450;
            return 1;

        }
        else
            return 0;
    }
    void Teacher()                                              //Controling Teacher Speed in different levels
    {
        if (lvl==1)
            xpos--;
        else if (lvl==2)
            xpos-=2;
        else if (lvl==3)
            xpos-=3;

        if(xpos==0 )
        {
            xpos= 1200;

        }
    }

};



#endif // ENEMY_H_INCLUDED
