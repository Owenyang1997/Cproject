// tu.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<graphics.h>
#define FNX(x)(x0+x*5)
#define FNY(y)(y0-y*5)
#define f(x)(x*x)
int x0, y0, MAXX, MAXY;
float s1;
main() {
	int xs, ys;
	float x, y, x1, y1, x2, y2, dx, i;
	initgraph(600, 400);
	setcolor(14);
	xs = FNX(x1); ys = FNY(0); moveto(xs - 10, ys);
	xs = FNX(x2); lineto(xs + 10, ys);
	xs = FNX(0); ys = FNY(0); moveto(xs, ys);
	xs = FNX(0); lineto(xs, ys);
	x = x1; y = f(x); xs = FNX(x); ys = FNX(y); moveto(xs, ys);
	for (i = x1; i < x2; i + dx) {
		x += dx; y = f(x); xs = FNX(x); ys = FNY(y);
		lineto(xs, ys);
	}
}
