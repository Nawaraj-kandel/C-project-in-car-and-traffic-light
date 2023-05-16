#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
void go();
void stop();
void start();
int car(int s)
{
	int p=55;
	circle(150+s,360,9);
	circle(80+s,360,9);
	line(69+s,360,55+s,360);
	line(55+s,360,55+s,345);
	line(55+s,345,65+s,345);
	line(65+s,345,185+s,345);
	line(65+s,345,85+s,330);
	line(85+s,330,130+s,330);
	line(110+s,330,110+s,345);
	line(130+s,330,150+s,345);
	line(185+s,345,185+s,355);
	line(185+s,358,163+s,358);
	line(140+s,360,90+s,360);
	p+=s;
	return p;
}
void back()
{
circle(450,100,10);
circle(450,130,10);
circle(450,160,10);
rectangle(447,180,451,300);
rectangle(433,80,465,180);
settextstyle(3,0,2);
line(0,300,640,300);
line(0,370,640,370);
line(390,300,390,370);
}
int main()
{
int s=0,i,page=0,light,p;
int gdriver = DETECT,gmode;
initwindow(640,480,"Traffic",0,0);
s=0;
for(i=0;i<1000;i++)
{
	setactivepage(page);
	setvisualpage(1-page);
	cleardevice();


p=car(s);
delay(100);
back();
if(light==2 || p>390 || p<250)
{
	s+=3;
}
else
{
	s+=0;
}
if(i<=50)
{
	go();
}
else if(i>50&&i<=100)
{
	stop();
}
else if(i>100&&i<=150)
{
	start();
}
else if(i>150)
{
	go();
}
light=getpixel(450,160);
page=(1-page);

}
setactivepage(1);
getch();
closegraph();
}

void go()

{
	back();
	setfillstyle(1,GREEN);

floodfill(450,160,WHITE);

}
void stop()

{
	back();
setfillstyle(1,RED);
floodfill(450,100,WHITE);
}

void start()
{
	back();
setfillstyle(1,YELLOW);
floodfill(450,132,WHITE);
}
