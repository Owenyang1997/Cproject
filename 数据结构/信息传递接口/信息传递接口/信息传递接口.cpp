#include<iostream>
#include<string>
using namespace std;
void show(string *s, int n);
int main() {
	int t, n;
	cin >> t >> n;
	string *swork = new string[n];
	char work[2][8];
	char wait[2][8];
	int Wtop[3];
	for (int i = 0; i < n; i++) 
	{
		Wtop[i] = -1;
	}
	for (int i = 0; i<t; i++)
	{
		cin >> swork[i];	
	}
	show(swork, n);
	system("pause");
	return 0;
}
void show(string *s, int n) {
	for (int i = 0; i<n; i++)
	{
		cout << s[i].length;
	}
}