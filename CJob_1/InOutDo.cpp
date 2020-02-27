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
{ //Вводим данные с клавиатуры и заносим в контейнер.
	char answer;
	do {
		string sf;
		cout << "\nВведите простую дробь (формат -1/2): ";
		cin >> sf;
		TFrac f(sf);
		m.push_back(f);
		cout << "\nПродолжить (y/n)? ";
		cin >> answer;
	} while (answer != 'n');
}

void InOutDo::Output(deque<TFrac>& m)
{ //Выводим содержимое контейнера на монитор.
	cout << "\nСодержимое контейнера deque: ";
	for (auto x : m) {
		cout << x.GetFrac() << " ; ";
	}
}

TFrac InOutDo::Sum(deque<TFrac>& m)
{ //Находим сумму
	TFrac Result = accumulate(m.begin(), m.end(), TFrac(), plus<TFrac>());
	return Result;
}

void InOutDo::SortUp(deque<TFrac>& m)
{ //Сортируем по возрастанию
	cout << "\nСортировка контейнера deque по возрастанию";
	sort(m.begin(), m.end(), less<TFrac>());
}
void InOutDo::SortDown(deque<TFrac>& m)
{ //Сортируем по убыванию
	cout << "\nСортировка контейнера deque по убыванию";
	sort(m.begin(), m.end(), greater<TFrac>());
}
