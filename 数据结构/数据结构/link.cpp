#include<iostream>
#include <Windows.h>
#include <cstdio>
//#include"Link.h"
using namespace std;
int main() {
	/*
	char ar[] = "abc";
	linkStack *p = NULL;
	PostFix(ar, ar);
	getchar();
	*/
	int i = 25;
	while (i != 0)
	{
		printf("%c", "0123456789ABCDEF"[i % 16]);
		i /= 16;
	}
	
	system("pause");
	return 0;
}