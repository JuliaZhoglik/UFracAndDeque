// CJob_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "windows.h"
#include "iostream"
#include "UFrac.h"
#include "InOutDo.h"
#include "deque"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	deque<TFrac> m;
	InOutDo::Input(m);
	InOutDo::Output(m);
	InOutDo::SortUp(m);
	InOutDo::Output(m);
	InOutDo::SortDown(m);
	InOutDo::Output(m);
	cout << "\nСумма = " <<InOutDo::Sum(m).GetFrac() << endl;
	system("pause");
	return 0;
}
