#include<iostream>
#include<string>
using namespace std;
typedef char Data;
typedef struct node {
	Data data;
	struct node * next;
}linkStack;

linkStack * Pop(linkStack * top, Data * data) {
	linkStack * p = NULL;
	if (top != NULL) {
		*data = top->data;
		p = top;
		top = top->next;
		free(p);
	}
	return top;
}
linkStack * Push(linkStack * top, Data data) {//top为头指针
	linkStack * p = (linkStack*)malloc(sizeof(linkStack));
	p->data = data;
	p->next = top;
	top= p;
	return top;
}
int change(int a,int *arr,int size){//用链表实现一个数转化为其它进制的数
	linkStack *p=NULL;
	while (a) {
		p=Push(p, a % size);
		a=a / size;
	}
	int i = 0;
	while (p) {
		Data b;
		p=Pop(p, &b);
		arr[i] = b;
		i++;
	}
	return i;
}

void conversion(int a, int c) {
	int arr[16];
	int j = change(a, arr, c);
	for (int i = 0; i <j; i++)
		cout << arr[i];
}

void PostFix(char *str,char *st){
	linkStack *p=NULL;
	linkStack *num = NULL;
	linkStack *op = NULL;
	int i = 0;
	while (str[i]!='\0'&&!isop(str[i])) {
		num=Push(num, str[i]);
		p = num;
		i++;
	}
	while (str[i] != '\0' && isop(str[i])) {
		op = Push(op, str[i]);
		p = op;
		i++;
	}
	while (p) {
		char a;
		p=Pop(p, &a);
		cout << a;
	}
}
bool isop(char a) {
	if (a == '(' || a == ')' || a == '+' || a == '-' || a == '*' || a == '/')
		return true;
	else return false;
}



