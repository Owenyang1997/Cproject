#include "stdafx.h"
#include "Dog.h"
#include<iostream>

using namespace std;

Dog::Dog()
{
	cout << "Dog���캯������" << endl;
}


Dog::~Dog()
{
	cout << "Dog���캯��xiaoshi" << endl;
}

void main() {
	Dog b;
	b.setName("����");
	b.SetAge(6);
	b.print();
}