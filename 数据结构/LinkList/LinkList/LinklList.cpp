#include<iostream>
#include"LinkList.h"
using namespace std;
int main() {
	//1ͷ�巨��ʾ
	cout << "ͷ�巨��ʾ:" << endl;
	LinkList *L = Init();
	CreatListByHead(n,L);
	ShowList(L);

	//2β�巨��ʾ
	cout << "β�巨��ʾ:" << endl;
	LinkList *L1 = Init();
	CreatListByTrail(n, L1);
	ShowList(L1);

	//3����ͷ�ڵ������
	cout << "����ͷ�ڵ������:" << endl;
	LinkList *L2 = CreatListByHead(n);
	ShowList(L2);

	//4ɾ������ֵΪx�Ľڵ�
	cout << "ɾ������ֵΪ3�Ľڵ�:" << endl;
	DeleLinkListX(3, L2);
	ShowList(L2);

	//5ɾ����С�ڵ�
	cout << "ɾ����С�ڵ�:" << endl;
	DeleMinLinkList(L1);
	ShowList(L1);

	//6������͵�����(��ͷ�ڵ��С����)
	cout << "������͵�����:" << endl;
	SortLinkList(L1);
	ShowList(L1);

	//7ɾ����ͷ�ڵ�����������ظ�����
	cout << "ɾ����ͷ�ڵ�����������ظ�����:" << endl;
	DeleReptLinkList(L1);
	ShowList(L1);


	system("pause");
	return 0;
}

//��ͷ�ڵ��ͷ�巨
void CreatListByHead(int n , LinkList *L){
	LinkList *p=NULL;
	for (int i = 0; i <n; i++) {
		p = (LinkList*)malloc(sizeof(LinkList));
		p->date = a[i];
		p->next = L->next;
		L->next = p;
	}
}

//��ͷ�ڵ��β�巨
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

//ͷ�巨��������ͷ�ڵ������
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

//ɾ����С�ڵ�(��ͷ�ڵ�,��С�ڵ�Ψһ)
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

//������͵�����(��ͷ�ڵ��С����)
void SortLinkList(LinkList *L)
{
	LinkList * vre = L->next, *v = L->next->next, *p = L->next, *pre = L;
	while (v)
	{
		pre = L;
		p = L->next;
		//�ҵ������
		while (p != v && v->date > p->date)
		{
			pre = p;
			p = p->next;
		}
		//����Ҫ�ı�λ��
		if (p == v)
		{
			vre = v;
			v = v->next;
		}
		//�ı�λ��
		else 
		{
			vre->next = v->next;//�Ƚ��ýڵ�ϵ�
			v->next = pre->next;//���ýڵ����
			pre->next = v;
			v = vre->next;//v�ӵ�ѭ��vre�ĺ������ѭ��
		}
	}
}

//ɾ����ͷ�ڵ�����������ظ�����
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