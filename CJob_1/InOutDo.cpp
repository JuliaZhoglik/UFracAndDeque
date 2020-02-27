// InOutDo.cpp

#include "pch.h"
#include "InOutDo.h"
#include "iostream"
#include <numeric>      // accumulate
#include <algorithm> // sort

using namespace std;


InOutDo::InOutDo()
{
}


InOutDo::~InOutDo()
{
}

void InOutDo::Input(deque<TFrac>& m)
{ //������ ������ � ���������� � ������� � ���������.
	char answer;
	do {
		string sf;
		cout << "\n������� ������� ����� (������ -1/2): ";
		cin >> sf;
		TFrac f(sf);
		m.push_back(f);
		cout << "\n���������� (y/n)? ";
		cin >> answer;
	} while (answer != 'n');
}

void InOutDo::Output(deque<TFrac>& m)
{ //������� ���������� ���������� �� �������.
	cout << "\n���������� ���������� deque: ";
	for (auto x : m) {
		cout << x.GetFrac() << " ; ";
	}
}

TFrac InOutDo::Sum(deque<TFrac>& m)
{ //������� �����
	TFrac Result = accumulate(m.begin(), m.end(), TFrac(), plus<TFrac>());
	return Result;
}

void InOutDo::SortUp(deque<TFrac>& m)
{ //��������� �� �����������
	cout << "\n���������� ���������� deque �� �����������";
	sort(m.begin(), m.end(), less<TFrac>());
}
void InOutDo::SortDown(deque<TFrac>& m)
{ //��������� �� ��������
	cout << "\n���������� ���������� deque �� ��������";
	sort(m.begin(), m.end(), greater<TFrac>());
}
