
# include "iGraphics.h"

#include<iostream>
#include<string>
#include<sstream>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<mmsystem.h>
#include<windows.h>
#define N 1000
#pragma comment(lib,"winmm.lib")

using namespace std;

int indexnumber=0;
char str[1000], str1[1000];
int mposx,mposy;
int play=0;
int life= 5;
int totalEnemy = 5;
int score= 0;
char scoreArray[50];
char lifeArray[50];
char ch[10];
int bgm = 1;

//Ship Selection
char ship[4][25]={ "images//ship2.bmp", "images//ship3.bmp" , "images//ship4.bmp" , "images//ship1.bmp" };
int ship_index=0;

//Bulet Change Array
//char bulletcolor[2][25] = { "images//bullet1.bmp", "images//bullet2.bmp"};
int bulletcolorIndex = 0;
int selection = 0;

//Starting Page
//char bg[3][25]={ "images//pg1.bmp" , "images//pg2.bmp", "images//pg3.bmp"};
int bgIndex=0,gameover=0;
int x=950,y=50;
int shipX=150,shipY=1000;

double cornerx=400;
double cornery=40;
double widthrec=20;
double lengthrec=20;
int  r = 10,shooty1[1000]={0};
//int x1=cornerx+(lengthrec/2);
//int b=cornery+(lengthrec/2);
int y2=cornery+12,y3=cornery+11;
int red=255,blue=255,green=255,i1=0,i2=0,i3=0,j=0;
int bally,ballx,m=0,k=0,i=0;
int highscore,enx1[1000],enx2[1000],eny1[1000],eny2[1000],
enx3[1000],eny3[1000],enx4[1000],eny4[1000],enx5[1000],
eny5[1000];
int craftindex=0;
bool shooting[1000],bulletx[1000],bullety[1000],enemyindex1[1000],enemyindex2[1000],enemyindex3[1000],
enemyindex4[1000],enemyindex5[1000];
int cnt=0,cnt1=0;
//int lives=0;
int shootx1[1000]={0};
char scorecount[100];
int axisx[1000],axisy[1000];

void game_end()
{
	if(life<=0)
	{
		bgIndex=8;
	}
}
void iDraw(){
	iClear();
	if(bgIndex==0) iShowBMP(0, 0, "images//pg1.bmp" );
	if(bgIndex==1)
	   //Buttons of the Menu Screen
	{
		iShowBMP(0, 0, "images//pg2.bmp" );
		iShowBMP2(200, 750, "images//start.bmp", 0);
		iShowBMP2(200, 600, "images//instructions.bmp", 0);
		iShowBMP2(200, 450, "images//exit.bmp", 0);
		//iShowBMP2(200, 300, "images//exit.bmp", 0);
	}
	
	//Ship Selection
	/*if(bgIndex == 3)
	{
		iSetColor(0,0,0);
		iFilledRectangle(0,0,1920,1080);
	}*/

	if(bgIndex == 3)
	{
		iShowBMP(0,0,"images//bg2.bmp");
		iSetColor(124,100, 200);
        iText(750,950,"PLEASE SELECT THE SPACECRAFT YOU WANNA PLAY WITH",GLUT_BITMAP_TIMES_ROMAN_24);
		iShowBMP2(1000,800,ship[0],0);
        iShowBMP2(1000,600,ship[1],0);
	    iShowBMP2(1000,400,ship[2],0);
	    iShowBMP2(1000,200,ship[3],0);
	}

	if(bgIndex==4)
	{
		iShowBMP2(0,0,"images//instruction.bmp",0);
	}

	if(bgIndex==5) exit(0);

	//Adding Difficulty
	if(bgIndex==6)
	{
		iShowBMP(0,0,"images//bg3.bmp");
		iSetColor(255,255,255);
		iText(750,850,"PLEASE SELECT YOUR GAME LEVEL",GLUT_BITMAP_TIMES_ROMAN_24);
		iShowBMP(800,750,"images//easy.bmp");
		iShowBMP(800,600,"images//hard.bmp");
		iSetColor(255,255,255);
		iText(758,370,"PLEASE ENTER YOUR NAME",GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255,255,255);
		iFilledRectangle(700,310,500,30);
		iSetColor(0,0,0);
		iText(710,314,str,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	//playing the game

	//Easy Mode

	if(bgIndex==2||bgIndex==7)
	{
		iShowBMP2(0,0,"images\\bg1.bmp",0);
	/*}
	  //Bringing the ship and creating the score storage button
	if(play == 1 || play==2)
	{*/
		iShowBMP2(x,y,ship[craftindex],0);
		iSetColor(13, 15, 255);
		_itoa(score, scoreArray, 10);
		iText(50, 1000, "SC0RE:", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(125, 1000, scoreArray, GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(21, 222, 210);
	    _itoa(life, lifeArray, 10);
		iText(50, 800, "LIFE:", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(125, 800, lifeArray, GLUT_BITMAP_TIMES_ROMAN_24);
    for(int i=0;i<N;i++)
	{
        if(shooting[i])
		{
        	iSetColor(255,0,0);
        	iFilledCircle(x+65-shootx1[i],y+70+shooty1[i],r);
        }
    }
    for(int i=0;i<N;i++)
	{
    	if(enemyindex1[i])
		{
    		iShowBMP2(enx1[i],eny1[i],"images//ship2.bmp",0);
    	}
    }
    for(int i=0;i<N;i++)
	{
        if(enemyindex5[i])
		{
   			 iShowBMP2(enx5[i],eny5[i],"images//ship1.bmp",0);
        }
    }
	for(int i=0;i<N;i++)
	{
        if(enemyindex2[i])
		{
    		iShowBMP2(enx2[i],eny2[i],"images//ship3.bmp",0);
    	}
    }
    for(int i=0;i<N;i++)
	{
        if(enemyindex3[i])
		{
    		iShowBMP2(enx3[i],eny3[i],"images//ship4.bmp",0);
   		}
    }
    for(int i=0;i<N;i++)
	{
        if(enemyindex4[i])
		{
    		iShowBMP2(enx4[i],eny4[i],"images//ship3.bmp",0);
    	}
    }
	}

	game_end();

	if(bgIndex==8)
	{
		iSetColor(0,255,0);
		iText(600,600,"GAME OVER !! BEST OF LUCK NEXT TIME",GLUT_BITMAP_TIMES_ROMAN_24);
		iShowBMP2(0,0,"images//pg2.bmp",0);
		iSetColor(0,0,0);
		iFilledRectangle(330,350,350,200);
		iSetColor(0,255,0);
		iText(350,500,"Name:",GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(str1,"%s",str);
		iText(420,500,str1,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(350,450,"Score=",GLUT_BITMAP_TIMES_ROMAN_24);
		char scoreboard[10];
		sprintf(scoreboard,"%d",score);
		iText(450,450,scoreboard,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	//Difficulty Mode

	/*if(bgIndex==7)
	{
		iShowBMP2(0,0,"images\\bg2.bmp",0);
	}
	//Bringing the ship and creating the score storage button
	if(play == 2)
	{
		iShowBMP2(x,y,ship[craftindex],0);
		iSetColor(13, 15, 255);
		_itoa(score, scoreArray, 10);
		iText(50, 1000, "SC0RE:", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(125, 1000, scoreArray, GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(21, 222, 210);
	    _itoa(life, lifeArray, 10);
		iText(50, 800, "LIFE:", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(125, 800, lifeArray, GLUT_BITMAP_TIMES_ROMAN_24);
		if(life==0) exit(0);
		
    for(int i=0;i<1000;i++)
	{
        if(shooting[i])
		{
        	iSetColor(255,0,0);
        	iFilledCircle(x+65-shootx1[i],y+70+shooty1[i],r);
        }
    }
    for(int i=0;i<1000;i++)
	{
    	if(enemyindex1[i])
		{
    		iShowBMP2(enx1[i],eny1[i],"images//ship2.bmp",0);
    	}
    }
    for(int i=0;i<1000;i++)
	{
        if(enemyindex5[i])
		{
   			 iShowBMP2(enx5[i],eny5[i],"images//ship1.bmp",0);
        }
    }
	for(int i=0;i<1000;i++)
	{
        if(enemyindex2[i])
		{
    		iShowBMP2(enx2[i],eny2[i],"images//ship3.bmp",0);
    	}
    }
    for(int i=0;i<1000;i++)
	{
        if(enemyindex3[i])
		{
    		iShowBMP2(enx3[i],eny3[i],"images//ship4.bmp",0);
   		}
    }
    for(int i=0;i<1000;i++)
	{
        if(enemyindex4[i])
		{
    		iShowBMP2(enx4[i],eny4[i],"images//ship3.bmp",0);
    	}
    }
	}*/

}
void iMouseMove(int mx, int my) 
{
      	printf("x = %d, y= %d\n",mx,my);
}

void iMouse(int button, int state, int mx, int my) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
    if(bgIndex == 1 && mx>=200 && mx<=450 && my>=750 &&my<=820)
	{
		bgIndex=3;
	}
	if(bgIndex == 1 && mx>=200 && mx<=450 && my>=600 &&my<=670)
	{
		bgIndex=4;
	}
	if(bgIndex == 1 && mx>=200 && mx<=450 && my>=450 &&my<=520)
	{
		bgIndex=5;
	}
	if(bgIndex == 3 && mx>=1000 && mx<=1120 && my>=800 &&my<=890)
	{
		craftindex=0;
		bgIndex=6;
	}
	if(bgIndex == 3 && mx>=1000 && mx<=1120 && my>=600 &&my<=690)
	{
		craftindex=1;
		bgIndex=6;
	}
	if(bgIndex == 3 && mx>=1000 && mx<=1120 && my>=400 &&my<=490)
	{
		craftindex=2;
		bgIndex=6;
	}
	if(bgIndex == 3 && mx>=1000 && mx<=1120 && my>=200 &&my<=290)
	{
		craftindex=3;
		bgIndex=6;
	}
	if(bgIndex==6 && mx>=800 && mx<=1050 && my>=750 && my<=805)
	{
		bgIndex=2;
	}
	if(bgIndex==6 && mx>=800 && mx<=1050 && my>=600 && my<=666)
	{
		bgIndex=7;
	}
	/*if(bgIndex==2)
	{
		play=1;
		//ship_index=0;
		life=5;
        //shooting[i]=true;
        i++;
	}
	if(bgIndex==7)
	{
		play=2;
		//ship_index=0;
		life=5;
        //shooting[i]=true;
        i++;
	}*/
 }
}

void iKeyboard(unsigned char key) {
	if(key=='\r') bgIndex=1;
	if(key==27) exit(0);
	if(key=='q'||key=='x')
	{
		bgIndex=1;
	}
	else if(key=='a')
	{
		if(x<=50) x=0;
		else x-=40;
        for(int i=0;i<N;i++)
		{
            if(shooting[i])  shootx1[i]-=40;
        }
	}
	else if(key=='d')
	{
		if(x>=1795) x=1795;
		else x+=40;
        for(int i=0;i<N;i++)
		{
            if(shooting[i])  shootx1[i]+=40;
        }
	}
	else if(key=='w')
	{
		if(y>=986) y=986;
		else y+=30;
		for(int i=0;i<N;i++)
		{
            if(shooting[i])  shooty1[i]-=30;
        }
	}
	else if(key=='s')
	{
		if(y<=40) y=50;
		else y-=30;
		for(int i=0;i<N;i++)
		{
            if(shooting[i])  shooty1[i]+=30;
        }
	}
	else if(key=='l')
	{
       if(shooting[i]==false)
	   {
       shooting[i]=true;
       i++;
	   PlaySound(TEXT("shoot.wav"),NULL,SND_ASYNC);
	   }
	}
	if(key!='\b')
	{
		if(bgIndex==6){
        str[indexnumber]=key;
        str[indexnumber+1]='\0';
        indexnumber++;
		}
	}
	else
	{
		if(bgIndex==6){
		if(indexnumber<=0) indexnumber=0;
		else
		{
			indexnumber--;
			str[indexnumber]='\0';
		}
	}
	}
}  


void shooting1()
{
	for(int i=0;i<1000;i++)
	{
		if(shooting[i])
		{
			shooty1[i]+=30;
			//if(shooty[i]>=1000) shooting[i]=false;
		}
	}
}

void enemy(){

	//Easy Mode

	if(bgIndex==2){
    for(int i=0;i<1000;i++)
	{
        if(enemyindex1[i])
		{
			if(enx1[i]<x)
			{
           		 enx1[i]+=5;
            }
            else if(enx1[i]>x)
			{
             	enx1[i]-=5;
            }
            eny1[i]-=15;
        	if(enx1[i]>x-125 && enx1[i]<x+125 && eny1[i]<y+94)
			{
                enemyindex1[i]=false;
                life--;
				enx1[i]=4000;
				eny1[y]=2100;
                //sprintf(scorecount,": %d ",score1);
        	}
			if(eny1[i]<=0)enx1[i]=4000;
    	}
    }
    for(int i=0;i<1000;i++)
	{
        if(enemyindex2[i])
		{
		    if(enx2[i]<x)
			{
           		 enx2[i]+=5;
            }
            else if(enx2[i]>x)
			{
             	enx2[i]-=5;
            }
            eny2[i]-=15;
            if(enx2[i]>x-125 && enx2[i]<x+125 && eny2[i]<y+94)
			{
                enemyindex2[i]=false;
                life--;
				enx2[i]=4100;
				eny2[y]=2200;
                //sprintf(scorecount,": %d ",score1);
        	}
			if(eny2[i]<=0)enx2[i]=2200;
        }
    }
    for(int i=0;i<1000;i++)
	{
        if(enemyindex3[i])
		{
            if(enx3[i]<x)
			{
           		 enx3[i]+=5;
            }
            else if(enx3[i]>x)
			{
             	enx3[i]-=5;
            }
			eny3[i]-=15;
			if(enx3[i]>x-125 && enx3[i]<x+125 && eny3[i]<y+94)
			{
                enemyindex3[i]=false;
                life--;
				enx3[i]=4200;
				eny3[y]=2300;
                //sprintf(scorecount,": %d ",score1);
				//if(eny3[i]<=0)enx3[i]=2200;
        	}
			if(eny3[i]<=0)enx3[i]=2300;
        }
    }
    for(int i=0;i<1000;i++)
	{
        if(enemyindex4[i])
		{
			if(enx4[i]<x)
			{
           		 enx4[i]+=5;
            }
            else if(enx4[i]>x)
			{
             	enx4[i]-=5;
            }
            eny4[i]-=15;
        	if(enx4[i]>x-125 && enx4[i]<x+125 && eny4[i]<y+94)
			{
                enemyindex4[i]=false;
                life--;
				enx4[i]=4300;
				eny4[y]=2400;
                //sprintf(scorecount,": %d ",score1);
        	}
    	}
		if(eny4[i]<=0)enx4[i]=2400;
	}
    for(int i=0;i<1000;i++)
	{
        if(enemyindex5[i])
		{
             if(enx5[i]<x)
			 {
            	enx5[i]+=5;
             }
            else if(enx5[i]>x)
			{
             	enx5[i]-=5;
            }
            eny5[i]-=15;
            if(enx5[i]>x-125 && enx5[i]<x+125 && eny5[i]<y+94)
			{
                enemyindex5[i]=false;
                life--;
				enx1[i]=4400;
				eny1[y]=2500;
                //sprintf(scorecount,": %d ",score1);
        	}
			if(eny5[i]<=0)enx5[i]=2500;
        }
    }
	}

	//Difficult Mode

	if(bgIndex==7)
	{
		for(int i=0;i<1000;i++)
		{
        	if(enemyindex1[i])
			{
				if(enx1[i]<x)
				{
           		 	enx1[i]+=8;
            	}
            	else if(enx1[i]>x)
				{
             		enx1[i]-=8;
            	}
            	eny1[i]-=25;
        		if(enx1[i]>x-125 && enx1[i]<x+125 && eny1[i]<y+94)
				{
                	enemyindex1[i]=false;
                	life--;
					enx1[i]=2200;
					eny1[i]=1200;
                	//sprintf(scorecount,": %d ",score1);
        		}
				if(eny1[i]<=0)enx1[i]=2000;
    		}
    	}
   	 	for(int i=0;i<1000;i++)
		{
        	if(enemyindex2[i])
			{
		    	if(enx2[i]<x)
				{
           			 enx2[i]+=8;
            	}
            	else if(enx2[i]>x)
				{
             		enx2[i]-=8;
            	}
            	eny2[i]-=25;
            	if(enx2[i]>x-125 && enx2[i]<x+125 && eny2[i]<y+94)
				{
                	enemyindex2[i]=false;
                	life--;
                	//sprintf(scorecount,": %d ",score1);
        		}
				if(eny2[i]<=0)enx2[i]=2100;
        	}
    	}
    	for(int i=0;i<1000;i++)
		{
        	if(enemyindex3[i])
			{
            	if(enx3[i]<x)
				{
           		 	enx3[i]+=8;
            	}
            	else if(enx3[i]>x)
				{
             		enx3[i]-=8;
            	}
				eny3[i]-=25;
				if(enx3[i]>x-125 && enx3[i]<x+125 && eny3[i]<y+94)
				{
                	enemyindex3[i]=false;
                	life--;
                	//sprintf(scorecount,": %d ",score1);
        		}
				if(eny3[i]<=0)enx3[i]=2200;
        	}
    	}
    	for(int i=0;i<1000;i++)
		{
        	if(enemyindex4[i])
			{
				if(enx4[i]<x)
				{
           		 	enx4[i]+=8;
           	 	}
            	else if(enx4[i]>x)
				{
             		enx4[i]-=8;
            	}
            	eny4[i]-=25;
        		if(enx4[i]>x-125 && enx4[i]<x+125 && eny4[i]<y+94)
				{
                	enemyindex4[i]=false;
                	life--;
                	//sprintf(scorecount,": %d ",score1);
        		}
				if(eny4[i]<=0)enx4[i]=2300;
			}
		}
    	for(int i=0;i<1000;i++)
		{
        	if(enemyindex5[i])
			{
             	if(enx5[i]<x)
			 	{
            		enx5[i]+=8;
             	}
            	else if(enx5[i]>x)
				{
             		enx5[i]-=8;
            	}
            	eny5[i]-=25;
           		if(enx5[i]>x-125 && enx5[i]<x+125 && eny5[i]<y+94)
				{
                	enemyindex5[i]=false;
                	life--;
                	//sprintf(scorecount,": %d ",score1);
        		}
				if(eny5[i]<=0)enx5[i]=2500;
        	}
    	}
	}
 }

void enemyrender()
{
	if(life>0)
	{
	 enemyindex1[k]=true;
     enx1[k]=300;eny1[k]=1000;
     enemyindex2[k]=true;
     enx2[k]=600;eny2[k]=1000;
     enemyindex3[k]=true;
     enx3[k]=1200;eny3[k]=1000;
     enemyindex4[k]=true;
     enx4[k]=1400;eny4[k]=1000;
     enemyindex5[k]=true;
     enx5[k]=1750;eny5[k]=1000;
     k++;
	}
}

void collisioncheck1()
{
   for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            if(shooting[i] && enemyindex1[j]){
                if(x+65-shootx1[i]>=enx1[j] && x+65-shootx1[i]<=enx1[j]+125 && y+70+shooty1[i]>=eny1[j])
				{
                   	score++;
                   	//sprintf(scorecount,": %d ",score);
                    shooting[i]=false;
                    enemyindex1[j]=false;
					shootx1[i]=2000;
                    shooty1[i]=1500;
                    eny1[j]=1500;
                }
            }
        }
    }
}

void collisioncheck2()
{
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            if(shooting[i] && enemyindex2[j])
			{
                if(x+65-shootx1[i]>=enx2[j] && x+65-shootx1[i]<=enx2[j]+125 && y+70+shooty1[i]>=eny2[j])
				{
                	score++;
                   	//sprintf(scorecount,": %d ",score);
                    shooting[i]=false;
                    enemyindex2[j]=false;
					shootx1[i]=2000;
                    shooty1[i]=1500;
                    eny2[j]=1500;
                }
            }
        }
    }
}


void collisioncheck3()
{
    for(int i=0;i<1000;i++)
	{
        for(int j=0;j<1000;j++)
		{
            if(shooting[i] && enemyindex3[j])
			{
                if(x+65-shootx1[i]>=enx3[j] && x+65-shootx1[i]<=enx3[j]+125 && y+70+shooty1[i]>=eny3[j])
				{
                  	score++;
                   	//sprintf(scorecount,": %d ",score);
                    shooting[i]=false;
                    enemyindex3[j]=false;
					shootx1[i]=2000;
                    shooty1[i]=1500;
                    eny3[j]=1500;
                }
            }
        }
    }

}
void collisioncheck4()
{
    for(int i=0;i<1000;i++)
	{
        for(int j=0;j<1000;j++)
		{
            if(shooting[i] && enemyindex4[j])
			{
                if(x+65-shootx1[i]>=enx4[j] && x+65-shootx1[i]<=enx4[j]+125 && y+70+shooty1[i]>=eny4[j])
				{
                    score++;
                    //sprintf(scorecount,": %d ",score);
                    shooting[i]=false;
                    enemyindex4[j]=false;
					shootx1[i]=2000;
                    shooty1[i]=1500;
                    eny4[j]=1500;
                }
            }
        }
    }

}

void collisioncheck5(){
    for(int i=0;i<1000;i++)
	{
        for(int j=0;j<1000;j++)
		{
            if(shooting[i] && enemyindex5[j])
			{
                if(x+65-shootx1[i]>=enx5[j] && x+65-shootx1[i]<=enx5[j]+125 && y+70+shooty1[i]>=eny5[j])
				{
                    score++;
                   	//sprintf(scorecount,": %d ",score);
                    shooting[i]=false;
                    enemyindex5[j]=false;
					shootx1[i]=2000;
                    shooty1[i]=1500;
                    eny5[j]=1500;
                }
            }
        }
    }

}

void iSpecialKeyboard(unsigned char key) {
		if (key == GLUT_KEY_END) {
		exit(0);
	}
}

int main() {
	//place your own initialization codes here.


    srand(time(NULL)); // Seed the random number generator

	int t1=iSetTimer(20,shooting1);
	int t2=iSetTimer(25,enemy);
	int t3=iSetTimer(5000,enemyrender);
	int t4=iSetTimer(20,collisioncheck1);
	int t5=iSetTimer(20,collisioncheck2);
	int t6=iSetTimer(20,collisioncheck3);
	int t8=iSetTimer(20,collisioncheck4);
	int t9=iSetTimer(20,collisioncheck5);
	//int t4=iSetTimer(50,ship_movement);
	if(bgm){
		PlaySound(TEXT("BGM.wav"),NULL,SND_LOOP|SND_ASYNC);
	}
	iInitialize(1920, 1080, "GAME PROJECT");
	return 0;
}