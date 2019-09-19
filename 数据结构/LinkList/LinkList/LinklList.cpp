#include<iostream>
#include"LinkList.h"
using namespace std;
int main() {
	//1头插法演示
	cout << "头插法演示:" << endl;
	LinkList *L = Init();
	CreatListByHead(n,L);
	ShowList(L);

	//2尾插法演示
	cout << "尾插法演示:" << endl;
	LinkList *L1 = Init();
	CreatListByTrail(n, L1);
	ShowList(L1);

	//3不带头节点的链表
	cout << "不带头节点的链表:" << endl;
	LinkList *L2 = CreatListByHead(n);
	ShowList(L2);

	//4删除所有值为x的节点
	cout << "删除所有值为3的节点:" << endl;
	DeleLinkListX(3, L2);
	ShowList(L2);

	//5删除最小节点
	cout << "删除最小节点:" << endl;
	DeleMinLinkList(L1);
	ShowList(L1);

	//6单链表就地排序(带头节点从小到大)
	cout << "单链表就地排序:" << endl;
	SortLinkList(L1);
	ShowList(L1);

	//7删除带头节点的链表所有重复数据
	cout << "删除带头节点的链表所有重复数据:" << endl;
	DeleReptLinkList(L1);
	ShowList(L1);


	system("pause");
	return 0;
}

//带头节点的头插法
void CreatListByHead(int n , LinkList *L){
	LinkList *p=NULL;
	for (int i = 0; i <n; i++) {
		p = (LinkList*)malloc(sizeof(LinkList));
		p->date = a[i];
		p->next = L->next;
		L->next = p;
	}
}

//带头节点的尾插法
void CreatListByTrail(int n ,LinkList *L) {
	LinkList *p, *v=L;
	for (int i = 0; i <n; i++) {
		p = (LinkList*)malloc(sizeof(LinkList));
		p->date = a[i];
		p->next = NULL;
		v->next = p;
		v = p;
	}
}

void ShowList(LinkList *L) {
	LinkList *p = L;
	if(L->date==-1)
    	p= L->next;
	while (p) {
		cout << p->date << " ";
		p = p->next;
	}
	cout << endl;
}

LinkList * Init() {
	LinkList *p= (LinkList*)malloc(sizeof(LinkList));
	p->next = NULL;
	p->date = -1;
	return p;
}

//头插法建立不带头节点的链表
LinkList* CreatListByHead(int n) {
	LinkList *l =(LinkList*)malloc(sizeof(LinkList));
	l->date = a[0];
	l->next = NULL;
	for (int i = 1; i < n; i++) {
		LinkList *p = (LinkList*)malloc(sizeof(LinkList));
		p->date = a[i];
		p->next = l->next;
		l->next = p;
	}
	return l;
}

void DeleLinkListX(int x,LinkList  *&L) {
	LinkList *p;
	if (L == NULL) return;
	if (L->date == x) {
		p = L;
		L = L->next;
		free(p);
	    DeleLinkListX(x, L);
	}
	else
		DeleLinkListX(x, L->next);
}

//删除最小节点(带头节点,最小节点唯一)
void DeleMinLinkList(LinkList *L)
{
	LinkList * p = L->next, *pre = L, *minp = L->next, *minpre = L;
	while (p)
	{
		if (minp->date > p->date)
		{
			minp = p;
			minpre = pre;
		}
		pre = p;
		p = p->next;
	}
	minpre->next = minp->next;
	free(minp);
}

//单链表就地排序(带头节点从小到大)
void SortLinkList(LinkList *L)
{
	LinkList * vre = L->next, *v = L->next->next, *p = L->next, *pre = L;
	while (v)
	{
		pre = L;
		p = L->next;
		//找到插入点
		while (p != v && v->date > p->date)
		{
			pre = p;
			p = p->next;
		}
		//不需要改变位置
		if (p == v)
		{
			vre = v;
			v = v->next;
		}
		//改变位置
		else 
		{
			vre->next = v->next;//先将该节点断掉
			v->next = pre->next;//将该节点插入
			pre->next = v;
			v = vre->next;//v接到循环vre的后面继续循环
		}
	}
}

//删除带头节点的链表所有重复数据
void DeleReptLinkList(LinkList *L)
{
	LinkList *vre=L->next,*v=L->next->next;
	while (v)
	{
		while (vre->date == v->date)v = v->next;
		vre->next = v;
		vre = v;
		v = v->next;
	}
}