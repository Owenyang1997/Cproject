#include "stdafx.h"
#include "Dog.h"
#include<iostream>

using namespace std;

Dog::Dog()
{
	cout << "Dog构造函数运行" << endl;
}


Dog::~Dog()
{
	cout << "Dog构造函数xiaoshi" << endl;
}

void main() {
	Dog b;
	b.setName("武郎");
	b.SetAge(6);
	b.print();
}