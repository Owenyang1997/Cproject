#include<iostream>
#include<string>
using namespace std;
int IsPush(char Dstack[], char op, int Dtop);//�ж��Ƿ���ջ
int getIndex(char op);
int OptionData(int data1, int data2, char op);
char option[] = { '+','-','&','*','/' };
int main() {
	int n=2;
	int Otop = -1;
	int Dtop = -1;
	char *Ostack = new char[4];//����ջ 
	char  *Dstack = new char[5];//����ջ 
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
			//�����������ջ
			if (op[i][j] >= 48 && op[i][j] <= 57) {
				Dstack[++Dtop] = op[i][j]-'0';
			}
			else {
				//�������ж����ȼ�
				if (!IsPush(Ostack, op[i][j], Otop)) {
					//��ջ��������ȡ������ȡ�����������������Ĳ���������ջ���������������ѹջ
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
					//����������ȼ�����ջ 
					Ostack[++Otop] = op[i][j];
				}
			}
		}
		while (Otop != -1) {
			//��ջ��������ȡ������ȡ���������������������������ѹջ
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
//���ջ���ķ������ȼ�С����ջ 
int IsPush(char Ostack[], char op, int Otop)
{
	//���ջ��û����������ջ 
	if (Otop == -1) {
		return 1;
	}
	if (getIndex(op) - getIndex(Ostack[Otop]) >2 ) {//ջ��Ԫ�ش� 
		return 1;
	}
	else {
		return 0;
	}
}
//��ȡ���������±꣬��ʵ�����ȼ����ж� 
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

