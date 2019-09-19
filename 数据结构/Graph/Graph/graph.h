#include<iostream>
using namespace std;
int n = 7;
int *book=new int[n];
int *path = new int[n];
int *dist = new int[n];
void show(int map[6][6]); 
void Fold();
void Prim(int v);
void print(int a[]);
void Init();
void Dijkstra(int v);
void printPath(int path[]);
void Dfs(int v);
void Bfs(int v);