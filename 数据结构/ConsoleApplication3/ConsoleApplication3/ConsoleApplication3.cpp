// ConsoleApplication3.cpp: 定义控制台应用程序的入口点。
#include<iostream>
#include "stdafx.h"
using namespace std;

enum CPU_Rank { p1 = 1, p2, p3, p4, p5, p6, p7 };
class CPU
{
private:
	CPU_Rank rank;
	int frequentcy;
	float voltage;

public:
	CPU(CPU_Rank r, int f, float v)
	{
		rank = r;
		frequentcy = f;
		voltage = v;
		std::cout << "构造了一个CPU！" << endl;
	}
	~CPU()
	{
		std::cout << "析构了一个CPU！" << endl;
	}
	CPU_Rank GetRank()const { return rank; }
	int GetFrequency()const { return frequentcy; }
	float GetVoltage()const { return voltage; }

	void SetRank(CPU_Rank r) { rank = r; }
	void SetFrequency(int f) { frequentcy = f; }
	void SetVoltage(float v) { voltage = v; }

	void Run() {
		std::cout << "CPU开始运行！" << endl;
	}

	void Stop() {
		std::cout<<"CPU停止运行！";
	}
};
int main()
{
	CPU a(p6, 300, 2.8);
	a.Run();
	a.Stop();
	// return 0;
}