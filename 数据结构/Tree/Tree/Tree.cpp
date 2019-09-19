#include<iostream>
#include"tree.h"
using namespace std;
int main()
{
	int n = 10,k = 2,x = 2;//第k个节点的值,"删除"x"的子树,
//	cin >> n >>k>>x;
	Tree *t= Creat(n);
	cout << "后序遍历" << endl;
	PosOrder(t,n);
	cout << endl;
	cout << "层序遍历" << endl;
	LevOrder(t, n);
	cout << endl;
	int high = GetTreeHigh(t, n);
	cout << "树高为:" << high << endl;
	
	int broad = GetTreeBroad(t, n);
	cout << "树宽为:" << broad << endl;

	//先序遍历
	cout << "先序遍历:";
	FirOrder(t);
	cout<< endl;
	//先序遍历第k个节点的值
	int value= GetFirOrderK(t, k);
	cout << "第"<<k<<"个节点的值为:" << value << endl;

	cout << "删除"<<x<<"的子树:" << endl;;
//	DeleTreeX(t, x, n);
	FirOrder(t);



	FreeTree(t);



	system("pause");
	return 0;
}
typedef struct {
	Tree *t;
}tbuf;

//1建立n个节点的树
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

//2前序遍历
void FirOrder(Tree *t)
{
	if (t){
		cout << t->data << " ";
		FirOrder(t->left);
		FirOrder(t->right);
	}

}

//3中序遍历
void MiOrder(Tree *t)
{
	if (t) {
		FirOrder(t->left);
		cout << t->data << "-";
		FirOrder(t->right);
	}
}

//4后序遍历
void PosOrder(Tree *t,int n)
{
	tbuf *tf = new tbuf[n];
	int top = -1;
	Tree *p = t;
	Tree *last = NULL;
	while (p || top > -1)//栈非空
	{
		if (p) {//先左
			tf[++top].t = p;
			p = p->left;
		}
		else {
			p = tf[top].t;
			if (p->right&&p->right != last) {//存在右节点并且未放问过
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

//5层序遍历
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
		if (p->left)//左孩子入栈
			tf[front++].t = p->left;
		if (p->right)//右孩子入栈
			tf[front++].t = p->right;
	}
}

//6求树高度
int GetTreeHigh(Tree * t, int n) {//求树高
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

//7求树宽度
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

//8先序遍历第k个节点的值
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


//9值为x的节点，删除以它为根的子树
//删除用后序，查找用层序
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
		//左子树
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
		//右子树
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

//销毁树
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

