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
void CreatListByHead(int n, LinkList *L);//1ͷ�巨
void CreatListByTrail(int n, LinkList *L);//2β�巨
void ShowList(LinkList *L);//3���
LinkList * Init();

//4ͷ�巨��������ͷ�ڵ������
LinkList* CreatListByHead(int n);

//5ɾ������ͷ�ڵ������ֵΪX�Ľڵ�
void DeleLinkListX(int x, LinkList  *&L);

//6ɾ����С�ڵ�(��ͷ�ڵ�,��С�ڵ�Ψһ)
void DeleMinLinkList(LinkList *L);

//7������͵�����(��С����)
void SortLinkList(LinkList *L);

//8ɾ����ͷ�ڵ���������������ظ�����
void DeleReptLinkList(LinkList *L);