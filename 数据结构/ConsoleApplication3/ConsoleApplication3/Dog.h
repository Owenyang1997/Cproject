#pragma once
#include "Animal1.h"
#include<string.h>

#include"iostream"
using namespace std;

class Dog :public Animal1
{
	
public:
	int age;
   char name[10];
	void SetAge(int n);
	void setName(char n[]);
	void print() {
		cout << this->age;
		cout << this->name;
	}
	Dog();
	~Dog();

};
void Dog::SetAge(int n) {
	  age = n;

}
void Dog::setName(char n[]) {
	strcpy(this->name, n);
} 


