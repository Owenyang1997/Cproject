#include<stdio.h>
#include<stdlib.h>
#include"Heep.h"
#include<ctime>
int main() {
	Heep p = Heep(20);
	srand(time(NULL));
	for (int i = 1; i<20; i++)
	{
		int b = rand() % 30;
		p.insert(b);
		p.print();
	}
	getchar();
	return 0;
}
