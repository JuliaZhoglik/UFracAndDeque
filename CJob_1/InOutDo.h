// InOutDo.h

#pragma once
#include "UFrac.h"
#include "deque"


class InOutDo
{
public:
	InOutDo();
	~InOutDo();
	static void Input(deque<TFrac>& m); //Вводим данные с клавиатуры и заносим в контейнер.
	static void Output(deque<TFrac>& m); //Выводим содержимое контейнера на монитор.
	static TFrac Sum(deque<TFrac>& m); //Находим сумму
	static void SortUp(deque<TFrac>& m); //Сортируем вектор по возрастанию
	static void SortDown(deque<TFrac>& m); //Сортируем вектор по убыванию

};

