#pragma once
#include<iostream>
#include<math.h>
using namespace std;
class Heep
{
private:
	int* a;
	int count;
	int lenth;
	void swap(int a, int b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	void shifup(int b)
	{
		while (b>1 && a[b / 2]<a[b])
		{
			swap(a[b / 2], a[b]);
			b = b / 2;
		}
	}
	void shifdown(int b)
	{
		while (2 * b <= count)
		{
			int j = 2 * b;
			if (j + 1 <= count && a[j + 1]>a[j]) j = j + 1;
			if (a[b]>a[j]) break;
			swap(a[b], a[j]);
			b = j;
		}
	}
public:
	Heep(int len)
	{
		a = new int[len + 1];
		lenth = len;
		count = 0;
	}
	~Heep() {
		delete[]a;
	}
	void insert(int k)
	{
		if (lenth<count) return;
		count++;
		a[count] = k;
		shifup(count);
	}
	int size() {
		return count;
	}
	bool isEmpty() {
		return count == 0;
	}
	int popMax()
	{
		if (count == 0)return 0;
		swap(a[1], a[count]);
		shifdown(1);
		count = count - 1;
		return a[count + 1];
	}
	void show()
	{
		for (int i = 1; i<count; i++)
		{
			printf("%d ", a[i]);
		}
	}
	void print() {
		double lengh = size();
		int h = log2(lengh);
		for (int i = 1; i <= lengh; i++) {
			int j = pow(2, h);
			if (j - 1 == i) {
				printf("\n");
				h = h - 1;
				j = pow(2, h);
			}
			printBanck(j);
			printf("%d", a[i]);
		}
	}
	void printBanck(int n) {
		while (n > 0) {
			printf(" ");
			n--;
		}
	}
};