#include "stdafx.h"
#include <cstdio>
#include <graphics.h>
int f(double x) { return  x * x; }
int work(int x);
void print();
int X(int x);
int Y(int y);
void draw(int x, int y);
int main()
{
	int i;
	print();

	for (i = -400; i < 400; i++) {
		draw(i, work(i));
		printf("%d,%d\n", i, work(i));
	}
	getchar();
	closegraph();
	return 0;
}

void print() {
	initgraph(800, 600);
	setbkcolor(0xAAAAAA);
	cleardevice();
	setlinecolor(0xAA0000);
	line(0, 300, 800, 300);
	line(400, 0, 400, 600);
	setlinecolor(0x0000AA);
	line(390, 10, 400, 0);
	line(410, 10, 400, 0);
	int x = X(390);
	int y = Y(10);
	int y1 = Y(-10);
	line(x, y, 800, 300);
	line(x, y1, 800, 300);
}
int work(int x) {
	return f((x / 3.0)) * 3.0;
}
int X(int x) {
	int x0 = 400;
	return x + x0;
}
int Y(int y) {
	int y0 = 300;
	return y0 - y;
}
void draw(int x, int y) {
	setlinecolor(0x55FF55);
	int x1 = X(x);
	int y1 = Y(y);
	line(x1, y1, x1, y1);
}