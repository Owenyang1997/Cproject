
#pragma once
#include<iostream>
using namespace std;
typedef struct node {
	int data;
	struct node *left, *right;
}Tree;

Tree * Creat(int n);//1����n���ڵ����

void FirOrder(Tree *t);//2ǰ�����

void MiOrder(Tree *t);//3�������

void PosOrder(Tree *t,int n);//4�������

void LevOrder(Tree *t,int n);//5�������

int GetTreeHigh(Tree * t, int n);//6�����߶�

int GetTreeBroad(Tree * t, int n);//7�������

int GetFirOrderK(Tree *t,int k);//8���������k���ڵ��ֵ

void DeleTreeX(Tree *t, int x,int n);//9ֵΪx�Ľڵ㣬ɾ������Ϊ��������

void FreeTree(Tree *&t);//10������
