// 实验3.cpp.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <cstdio>
#include <graphics.h>
#include<math.h>
#include"dos.h"
#define PI 3.1412956
void sleep(int x) {
	int i = 0;
	for(i=0;i<x;i++){}
}
int X(int x) {
	return 600 + x;
}
int Y(int y) {
	return 500-y;
}
void init() {
	
	initgraph(1200, 1000);
	setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 3.5);
	BeginBatchDraw();
	setbkcolor(0x555555);
	setlinecolor(0x55FF55);
	circle(X(0), Y(100), 150);              //圆心(0,100), 半径150
	setlinecolor(0);
	circle(X(0), Y(100), 1);
	setlinecolor(0x55FF55);
	setlinecolor(0);
	circle(X(350), Y(100), 1);
}
void drawline() {
	double p = 0;
	double dp = 0;
	double p1 = PI / 180;
	double distence = 0;
	while(true) {
		int x = 150 * cos(p);//大圆x坐标
		//int x1 = 4*150*cos(p);//小圆x坐标
		double d = sqrt(pow(450, 2) - pow(x, 2));
		int x1 = x + d;
		int y = 150 * sin(p);
		cleardevice();
		circle(X(0), Y(100), 150);
		circle(X(x1), Y(100), 50);
		setlinecolor(0x55FF55);
		line(X(x), Y(y + 100), X(0), Y(100));
		line(X(-600), Y(50), X(600), Y(50));
		line(X(x1), Y(100), X(x), Y(y + 100));

		int x10 = 2* 150 * cos(p+p1);
		double dx = (x10- x1);
		distence += dx;

		int dp = ( distence /(PI * 100)) * 360;

		int x11 = 50 * cos(dp);
		int y11 = 50 * sin(dp);
		int x12 = 50 * cos(dp+90);
		int y12 = 50 * sin(dp+90);

		line(X(x1), Y(100), X(x1+x11), Y(100 + y11));
        line(X(x1), Y(100), X(x1 - x11), Y(100 - y11));
		line(X(x1), Y(100), X(x1+ x12), Y(100 + y12));
		line(X(x1), Y(100), X(x1 - x12), Y(100 - y12));

		FlushBatchDraw();
		Sleep(15.0);
		p += p1;


	}
}
int main()
{
	init();
	drawline();
	getchar();
	EndBatchDraw();
	closegraph();
	return 0;
    
}


