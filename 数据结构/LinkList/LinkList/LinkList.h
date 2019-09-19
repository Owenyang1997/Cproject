#pragma once
#include<iostream>
using namespace std;
typedef int ElemDate;
int a[] = { 1,2,3,4,5,6,7,3,4,5,6 };
int n = 11;
typedef struct link {
	ElemDate date;
	struct link* next;
}LinkList;
void CreatListByHead(int n, LinkList *L);//1头插法
void CreatListByTrail(int n, LinkList *L);//2尾插法
void ShowList(LinkList *L);//3输出
LinkList * Init();

//4头插法建立不带头节点的链表
LinkList* CreatListByHead(int n);

//5删除不带头节点的所有值为X的节点
void DeleLinkListX(int x, LinkList  *&L);

//6删除最小节点(带头节点,最小节点唯一)
void DeleMinLinkList(LinkList *L);

//7单链表就地排序(从小到大)
void SortLinkList(LinkList *L);

//8删除带头节点有序的链表所有重复数据
void DeleReptLinkList(LinkList *L);