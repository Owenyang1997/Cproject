#include "stdafx.h"
#include<graphics.h>
#include<conio.h>
#define M 10
#define N 10
int main() {
	int mg[M][N] = {
	{ 1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,0,1,0,0,0,1,0,1 },
	{ 1,0,0,1,0,0,0,1,0,1 },
	{ 1,0,0,0,0,1,1,0,0,1 },
	{ 1,0,1,1,1,0,0,0,0,1 },
	{ 1,0,0,0,1,0,0,0,0,1 },
	{ 1,0,1,0,0,0,1,0,0,1 },
	{ 1,0,1,1,1,0,1,1,0,1 },
	{ 1,1,0,0,0,0,0,0,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1 },
	};
	DrawMap(mg);
	return 0;
}
void DrawMap(int mg[M][N]) {
	int x, y, x1, y1;
	initgraph(500, 600,NULL);
	BGR(YELLOW);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			x = i; y = j; x1 = (i + 1) * 20; y1 = (j + 1) * 20;
			fillrectangle(x, y, x1, y1);
		}
	}
}



