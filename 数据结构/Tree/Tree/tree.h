
#pragma once
#include<iostream>
using namespace std;
typedef struct node {
	int data;
	struct node *left, *right;
}Tree;

Tree * Creat(int n);//1建立n个节点的树

void FirOrder(Tree *t);//2前序遍历

void MiOrder(Tree *t);//3中序遍历

void PosOrder(Tree *t,int n);//4后序遍历

void LevOrder(Tree *t,int n);//5层序遍历

int GetTreeHigh(Tree * t, int n);//6求树高度

int GetTreeBroad(Tree * t, int n);//7求树宽度

int GetFirOrderK(Tree *t,int k);//8先序遍历第k个节点的值

void DeleTreeX(Tree *t, int x,int n);//9值为x的节点，删除以它为根的子树

void FreeTree(Tree *&t);//10销毁树
