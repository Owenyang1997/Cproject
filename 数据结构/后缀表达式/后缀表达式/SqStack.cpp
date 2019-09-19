#include<iostream>
#include<string>
#include"Stack.h" 
using namespace std;
int GetIndex(char op);
int IsPush(char op, SqStack S);
char option[2][2] = { { '+','-' },{ '*','/' } };
void InitStack(SqStack *S) {
	S->top = -1;
}
bool StackEmpty(SqStack *S) {
	return (S->top == -1) ? true : false;
}
void Push(SqStack *S, char x)
{
	if (S->top + 1 == MaxSize) return;
	S->data[++S->top] = x;
}
void Pop(SqStack *S, char *x) {
	if (S->top == -1) return;
	*x = S->data[S->top--];
}
void GetTop(SqStack *S, char *x) {
	if (StackEmpty(S)) return;
	*x = S->data[S->top];
}
void show(char *p) {
	for (int i = 0; i<6; i++) {
		cout << p[i];
	}
}

int main()
{
	SqStack S;
	InitStack(&S);
	int len = 5;
	char *op = new char[len];
	for (int i = 0; i<len; i++)
		cin >> op[i];
	string str;
	for (int i = 0; i<len; i++) {
		if (op[i] >= 'a'&&op[i] <= 'z')
		{
			str += op[i];
		}
		else
		{
			if (op[i] == '(')
			{
				Push(&S, op[i]);
			}
			if (op[i] == ')')
			{
				char p;
				do
				{
					Pop(&S, &p);
					str += p;
				} while (p != '(');
				Pop(&S, &p);
			}
			if (IsPush(op[i], S) == 1)
			{
				Push(&S, op[i]);
			}
			else
			{
				char p;
				Pop(&S, &p);
				str += p;
			}
		}
	}
	while (S.top != -1) {
		char p;
		Pop(&S, &p);
		str += p;
	}
	cout << str;
	return 0;
}
//ÔËËã·ûÅÐ¶ÏÊÇ·ñÑ¹Õ»,È¥³ýÀ¨ºÅÇé¿ö
int IsPush(char op, SqStack S)
{
	if (StackEmpty(&S))
		return 1;
	char p;
	GetTop(&S, &p);
	if ((GetIndex(p) - GetIndex(op)) == 1)
	{//xiaoÑ¹Õ»
		return 0;
	}
	else {
		return 1;
	}
}
int GetIndex(char op) {
	for (int i = 0; i<2; i++) {
		for (int j = 0; j<2; j++) {
			if (op == option[i][j])
				return i;
		}
	}
}
