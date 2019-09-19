#pragma once
#include<iostream>
#define MaxSize 50
typedef struct {
	char data[MaxSize];
	int top;
}SqStack;
void InitStack(SqStack *S);
bool StackEmpty(SqStack *S);
void Push(SqStack *S, char x);
void Pop(SqStack *S, char *x);
void GetTop(SqStack *S, char *x);

