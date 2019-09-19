#include "stdafx.h"
#include <cstdio>
#include <graphics.h>
int X(int x);
int Y(int y);
void draw(int x, int y);
void print();
int main()
{
	print();
	setlinecolor(0x55FFFF);
	myline(-400, 20, 400, 20);
	myline(20, -300, 20, 300);

}
void myline(int x1, int y1, int x2, int y2) {
	float increx, increy, x, y, length;
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
	setlinecolor(0x55FF55);
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
	line(0, 300, 800, 300);
	line(400, 0, 400, 600);
	setlinecolor(0xFF5555);
	
}
