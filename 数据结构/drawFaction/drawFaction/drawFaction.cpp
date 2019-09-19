#include "stdafx.h"
#include <cstdio>
#include <graphics.h>
int X(int x);
int Y(int y);
void draw(int x, int y);
void print();
void myline(int x1, int y1, int x2, int y2);
int main()
{
	print();
	setlinecolor(0x55FFFF);
	myline(-400, 50, 400, 50);
	myline(50, -300, 50, 300);
	myline(-20, 300, 400, -20);
	getchar();
	closegraph();
	return 0;
}
void myline(int x1, int y1, int x2, int y2) {
	float increx, increy, x=x1, y=y1, length;
	int i;
	if (abs(x2 - x1) > abs(y2 - y1)) {
		length = abs(x2 - x1);
	}
	else {
		length = abs(y2 - y1);
	}
	increx = (x2 - x1) / length;
	increy = (y2 - y1) / length;
	for (i = 1; i <= length; i++) {
		draw(x + 0.5, y + 0.5);
		x = x + increx;
		y = y + increy;
	}
}
void draw(int x, int y) {
	int x1 = X(x);
	int y1 = Y(y);
	line(x1, y1, x1, y1);
}
int X(int x) {
	int x0 = 400;
	return x + x0;
}
int Y(int y) {
	int y0 = 300;
	return y0 - y;
}
void print() {
	initgraph(800, 600);
	setbkcolor(0x555555);
	cleardevice();
	setlinecolor(0xFF5555);
	line(X(-400), Y(0), X(400), Y(0));
	line(X(0), Y(-300), X(0), Y(300));
	line(X(-40), Y(300), X(400), Y(-40));
	outtextxy(X(390), Y(-10), 'X');
	outtextxy(X(-10), Y(300), 'Y');


}
