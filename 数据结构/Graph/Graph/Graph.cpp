#include<iostream>
#include"graph.h"
using namespace std;
int GetMinNerbor(int *root, int book[]);
int f = 100;
/*int G[6][6] = {
{f,6,1,5,f,f},
{6,f,5,f,3,f},
{1,5,f,5,6,4},
{5,f,5,f,f,2},
{f,3,6,f,f,6},
{f,f,4,2,6,f}
};*/
/*int G[3][3] = {
{f,6,13},
{10,f,4},
{5,f,f}
};*/
int G[7][7]{
{f,4,6,6,f,f,f},
{f,f,1,f,7,f,f},
{f,f,f,f,6,4,f},
{f,f,2,f,f,5,f},
{f,f,f,f,f,f,6},
{f,f,f,f,1,f,8},
{f,f,f,f,f,f,f}
};
int main() {
	//Prim(0);
	//Dijkstra(0);
	//cout << endl;
	//print(path);
	//show(G);
	//Fold();
	//show(G);
	//printPath(path);
	Dfs(0);
	cout << endl;
	Init();
	Bfs(0);
	system("pause");
	return 0;
}
void show(int map[6][6]){
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}
//多源点到个顶点最短路径
void Fold() {
	int path1[7][7];
	for (int j = 0; j < n; j++)
	{
		for (int k = 0; k < n; k++)
		{
			if (j != k && G[j][k] < f) path1[j][k] = j;
			else path1[j][k] = -1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (G[j][i] + G[i][k] < G[j][k] && i != j) {
					G[j][k] = G[j][i] + G[i][k];
					path1[j][k] = i;
				}
			}
		}
	}
}
//最小生成树
void Prim(int v) {
	int count = 0;
	book[v] = 1;
	while (count != n) {
		int root = 0;
		int index = GetMinNerbor(&root,book);
		book[index] = 1;
		path[index] = root;
		count++;
	}
}
int GetMinNerbor(int *root,int book[]) {
	int min = 100; int index = 0;
	for (int i = 0; i < n; i++) {
		if (book[i] == 1) {
			for (int j = 0; j < n; j++) {
				if (book[j] == 0 && min > G[i][j])
				{
					min = G[i][j]; *root = i; index = j;
				}
			}
		}
	}
	return index;
}
void print(int a[]) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}
void Init() {
	for (int i = 0; i < n; i++) {
		book[i] = 0;
		path[i] = -1;
	}
}
//path[i]:记录到i定点的前驱节点
//单源点到各顶点的最短路径
void Dijkstra(int v) {
	book[v] = 1;
	int index,m;
	for (int i = 0; i < n; i++) 
	{
		dist[i] = G[v][i];
		if (dist[i] < f) path[i] = v;
		else path[i] = -1;
	}	
	for (int i = 0; i < n; i++) 
	{
		m = f;
		for (int j = 0; j < n; j++)
		{
			if (m > dist[j]&&book[j]==0) 
			{
				index = j;
				m = dist[j];
			}
		}
		book[index] = 1; 
		for (int j = 0; j < n; j++) 
		{//更新每个节点的距离，并记录到该节点的前驱节点
			if (dist[index] + G[index][j] < dist[j]&&book[j]==0) 
			{
				dist[j] = dist[index] + G[index][j];
				path[j] = index;
			}
		}
	}
}
void printPath(int path[]) {
	int *apath = new int[n];
	int count;
	for (int i = 0; i < n; i++) {
		if (i != 0) {
			cout << 0 << "到顶点：" << i << "最短路径为：";
			count = 0;
			apath[count] = i;
			int k = path[i];
			if (k == -1)
				cout << "无路径";
			else {
				while (k != 0) {
					apath[++count] = k;
					k = path[k];
				}
				apath[++count] = 0;
				for (int j = count; j >= 0; j--) {
					cout << apath[j] << " ";
				}
				cout << endl;
			}
		}
		
	}
}

void Dfs(int v) {
	int *s=new int[n];
	int top = -1;
	s[++top] = v; book[v] = 1;
	while (top > -1) {
		v = s[top--];
		cout << v << " ";
		for (int i = 0; i < n; i++) {
			if (book[i] != 1 && G[v][i] < f) {
				s[++top] = i; book[i] = 1;
			}
		}
	}
}
void Bfs(int v) {
	int *s = new int[n];
	int front=0, rear=0;
	s[front++] = v; book[v] = 1;
	while (front > rear) {
		v = s[rear++];
		cout << v << " ";
		for (int i = 0; i < n; i++) {
			if (book[i] != 1 && G[v][i] < f) {
				s[front++] = i; book[i] = 1;
			}
		}
	}
}