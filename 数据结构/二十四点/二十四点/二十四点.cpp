#include<iostream>
#include<string>
using namespace std;
int IsPush(char Dstack[], char op, int Dtop);//判断是否入栈
int getIndex(char op);
int OptionData(int data1, int data2, char op);
char option[] = { '+','-','&','*','/' };
int main() {
	int n=2;
	int Otop = -1;
	int Dtop = -1;
	char *Ostack = new char[4];//符号栈 
	char  *Dstack = new char[5];//数据栈 
	//cin >> n;
	char op[2][7];
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<7; j++)
		{
			cin >> op[i][j];
		}
	}
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<7; j++)
		{
			//如果是数据入栈
			if (op[i][j] >= 48 && op[i][j] <= 57) {
				Dstack[++Dtop] = op[i][j]-'0';
			}
			else {
				//操作符判断优先级
				if (!IsPush(Ostack, op[i][j], Otop)) {
					//将栈顶操作符取出，并取出两个操作数，将改操作符号入栈，并将运算的数据压栈
					do {
						int data1 = Dstack[Dtop--];
						int data2 = Dstack[Dtop--];
						char op1 = Ostack[Otop--];
						int data3 = OptionData(data2, data1, op1);
						Dstack[++Dtop] = data3;
					} while (!IsPush(Ostack, op[i][j], Otop));
					Ostack[++Otop] = op[i][j];
				}
				else {
					//如果操作优先级大入栈 
					Ostack[++Otop] = op[i][j];
				}
			}
		}
		while (Otop != -1) {
			//将栈顶操作符取出，并取出两个操作数，并将运算的数据压栈
			int data1 = Dstack[Dtop--];
			int data2 = Dstack[Dtop--];
			char op1 = Ostack[Otop--];
			int data3 = OptionData(data2, data1, op1);
			Dstack[++Dtop] = data3;
		}
		int c = Dstack[Dtop];
		if (c == 24)
			cout << "yes"<<endl;
		else
			cout << "no";
	}
	system("pause");
}
//如果栈顶的符号优先级小则入栈 
int IsPush(char Ostack[], char op, int Otop)
{
	//如果栈内没有数据则入栈 
	if (Otop == -1) {
		return 1;
	}
	if (getIndex(op) - getIndex(Ostack[Otop]) >2 ) {//栈内元素大 
		return 1;
	}
	else {
		return 0;
	}
}
//获取操作符的下标，来实现优先级的判断 
int getIndex(char op) {
	for (int i = 0; i<4; i++) {
		if (op == option[i])
			return i;
	}
}

int OptionData(int data1, int data2, char op) {
	int data = 0;
	switch (op) {
	case '+': data = data1 + data2; break;
	case '-': data = data1 - data2; break;
	case '*': data = data1 * data2; break;
	case '/': data = data1 / data2; break;
	}
	return data;
}

