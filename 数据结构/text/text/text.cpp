// text.cpp: 定义控制台应用程序的入口点。
//
#include"stdafx.h"
#include <graphics.h>      
#include <conio.h>
#include<math.h>
#include<stdio.h>
#define s 0.01
double f(double x) { (exp((-x)*x)); }
int main()
{
	int xscreen, yscreen, i;
	float x1 = 320, y1, x2, y2, dx;
	xscreen = 640;
	yscreen = 480;
	initgraph(xscreen, yscreen);
	line(0, 240, 640, 240);
	line(320, 0, 320, 480);
	dx = (x1 - 320)*s;
	y1 = 240 - f(dx);
	for (i = 1; i <= 320; i++)
	{

		x2 = x1 + 1;
		dx = (x2 - 320)*s;
		y2 = 240 - f(dx) / s;
		line((int)x1, (int)y1, (int)x2, (int)y2);
		x1 = x2;
		y1 = y2;
	}
	x1 = 320;
	dx = (x1 - 320)*s;
	y1 = 240 - f(dx);
	for (i = 1; i <= 320; i++)
	{

		x2 = x1 - 1;
		dx = (x2 - 320)*s;
		y2 = 240 - f(dx) / s;
		line((int)x1, (int)y1, (int)x2, (int)y2);
		x1 = x2;
		y1 = y2;
	}
	_getch();
	closegraph();
	return 0;
}

