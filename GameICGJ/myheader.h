#ifndef MYHEADER_H_INCLUDED
#define MYHEADER_H_INCLUDED

int ex=0,ey=10;
int lx ;
int ly ;

void enemyChange(){
	ex += lx;
	ey += ly;

	if(ex > 1280 || ex < 0)
		lx = -lx;
	if(ey > 720 || ey < 0)
		ly = -ly;
	if(ex == cursorMX ||ex+10 == cursorMX || ex-10 == cursorMX || ex+10 == cursorMX+10 ||ex-10 == cursorMX+10 || ex+10 == cursorMX+15 || ex-10 == cursorMX+15 )
		lx = -lx;
	if(ey+10 == cursorMY || ey+10 == cursorMY || ey-10 == cursorMY || ey+10 == cursorMY+10 ||ey-10 == cursorMY+10 || ey+10 == cursorMY+15 || ey-10 == cursorMY+15)
		ly = -ly;
}


#endif // !MYHEADER_H_INCLUDED
