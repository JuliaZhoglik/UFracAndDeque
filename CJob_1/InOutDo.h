// InOutDo.h

#pragma once
#include "UFrac.h"
#include "deque"


class InOutDo
{
public:
	InOutDo();
	~InOutDo();
	static void Input(deque<TFrac>& m); //������ ������ � ���������� � ������� � ���������.
	static void Output(deque<TFrac>& m); //������� ���������� ���������� �� �������.
	static TFrac Sum(deque<TFrac>& m); //������� �����
	static void SortUp(deque<TFrac>& m); //��������� ������ �� �����������
	static void SortDown(deque<TFrac>& m); //��������� ������ �� ��������

};

