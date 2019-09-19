#include<iostream>
#include"tree.h"
using namespace std;
int main()
{
	int n = 10,k = 2,x = 2;//��k���ڵ��ֵ,"ɾ��"x"������,
//	cin >> n >>k>>x;
	Tree *t= Creat(n);
	cout << "�������" << endl;
	PosOrder(t,n);
	cout << endl;
	cout << "�������" << endl;
	LevOrder(t, n);
	cout << endl;
	int high = GetTreeHigh(t, n);
	cout << "����Ϊ:" << high << endl;
	
	int broad = GetTreeBroad(t, n);
	cout << "����Ϊ:" << broad << endl;

	//�������
	cout << "�������:";
	FirOrder(t);
	cout<< endl;
	//���������k���ڵ��ֵ
	int value= GetFirOrderK(t, k);
	cout << "��"<<k<<"���ڵ��ֵΪ:" << value << endl;

	cout << "ɾ��"<<x<<"������:" << endl;;
//	DeleTreeX(t, x, n);
	FirOrder(t);



	FreeTree(t);



	system("pause");
	return 0;
}
typedef struct {
	Tree *t;
}tbuf;

//1����n���ڵ����
Tree * Creat(int n) 
{
	Tree *t= (Tree *)malloc(sizeof(Tree));
	t->data = 1;
	tbuf *tf = new tbuf[n];
	int top = -1; int index = 1;
	tf[++top].t = t;
	while (top > -1)
	{
		Tree *root = tf[top--].t;
		Tree *l = NULL;
		Tree *r = NULL;
		if (root->data * 2 <= n)
		{
			l= (Tree *)malloc(sizeof(Tree));
			l->data = root->data * 2;
			tf[++top].t = l;
		}
		if (root->data * 2 + 1 <= n)
		{
			r= (Tree *)malloc(sizeof(Tree));
			r->data = root->data * 2+1;
			tf[++top].t = r;
		}
		root->left = l; root->right = r;
	}
	return t;
}

//2ǰ�����
void FirOrder(Tree *t)
{
	if (t){
		cout << t->data << " ";
		FirOrder(t->left);
		FirOrder(t->right);
	}

}

//3�������
void MiOrder(Tree *t)
{
	if (t) {
		FirOrder(t->left);
		cout << t->data << "-";
		FirOrder(t->right);
	}
}

//4�������
void PosOrder(Tree *t,int n)
{
	tbuf *tf = new tbuf[n];
	int top = -1;
	Tree *p = t;
	Tree *last = NULL;
	while (p || top > -1)//ջ�ǿ�
	{
		if (p) {//����
			tf[++top].t = p;
			p = p->left;
		}
		else {
			p = tf[top].t;
			if (p->right&&p->right != last) {//�����ҽڵ㲢��δ���ʹ�
				p = p->right;
				tf[++top].t = p;
				p = p->left;
			}
			else {
				p = tf[top--].t;
				cout << p->data << " ";
				last = p;
				p = NULL;
			}
		}
	}
}

//5�������
void LevOrder(Tree *t,int n) {
	tbuf *tf = new tbuf[n];
	int front = 0, rear = 0;
	Tree *p = t;
	int last = 1;
	tf[front++].t = p;
	while (front > rear)
	{
		p = tf[rear++].t;
		cout << p->data << " ";
		if (p->left)//������ջ
			tf[front++].t = p->left;
		if (p->right)//�Һ�����ջ
			tf[front++].t = p->right;
	}
}

//6�����߶�
int GetTreeHigh(Tree * t, int n) {//������
	tbuf *tf = new tbuf[n];
	int front = 0, rear = 0;
	Tree *p = t;
	int last = 1;
	int index = 0, count = 0;
	tf[front++].t = p;
	while (front > rear)
	{
		p = tf[rear++].t;
		if (p->left)
			tf[front++].t = p->left;
		if (p->right)
			tf[front++].t = p->right;
		if (last == rear) {
			last = front;
			count++;
		}
	}
	return count;
}

//7�������
int GetTreeBroad(Tree * t, int n) {
	tbuf *tf = new tbuf[n];
	int front = 0, rear = 0;
	Tree *p = t;
	int last = 1;
	int index = 0, count = 0;
	int max = 0;
	tf[front++].t = p;
	while (front > rear)
	{
		p = tf[rear++].t;
		count++;
		if (p->left)
			tf[front++].t = p->left;
		if (p->right)
			tf[front++].t = p->right;
		if (last == rear) {
			last = front;
			max = count > max ? count : max;
			count = 0;
		}
	}
	return max;
}

//8���������k���ڵ��ֵ
int GetFirOrderK(Tree *t,int k) 
{
	if (t)
	{
		if (k == 1) return t->data;
		k--;
		return GetFirOrderK(t->left, k);
		return GetFirOrderK(t->right, k);
	}
}


//9ֵΪx�Ľڵ㣬ɾ������Ϊ��������
//ɾ���ú��򣬲����ò���
void DeleTreeX(Tree *t, int x, int n)
{
	tbuf *tf = new tbuf[n];
	Tree *p = t;
	int front = 0,rear = 0;
	if (t->data == x) FreeTree(t);
	tf[front++].t = p;
	while (rear < front)
	{
		p = tf[rear++].t;
		//������
		if (p->left)
		{
			if (p->left->data == x)
			{
				FreeTree(p->left);
				p->left = NULL;
			}
			else
			{
				tf[front++].t = p->left;
			}
		}
		//������
		if (p->right)
		{
			if (p->right->data == x)
			{
				FreeTree(p->right);
				p->right = NULL;
			}
			else
				tf[front++].t = p->right;
		}
	}
}

//������
void FreeTree(Tree *&t)
{
	if (t)
	{
		FreeTree(t->left);
		FreeTree(t->right);
		free(t);
		t = nullptr;
	}
}

