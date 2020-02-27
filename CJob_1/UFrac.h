// UFrac.h

#pragma once
#include "string"

using namespace std;

class TFrac
{
private:
	int num;             //Числитель
	int denom;           //Знаменатель
	int GetNOD(int a, int b) const; // поиск наибольшего общего делителя
	void SetNumDenom(int n, int d); // установить дробь

public:
	TFrac(); // конструктор по умолчанию
	~TFrac(); // деструктор
	TFrac(int n, int d); // конструктор число
	TFrac(string s); // конструктор строка
	TFrac(const TFrac& F); // копирование
	TFrac operator + (const TFrac right) const; // сложение
	TFrac operator * (const TFrac right) const; // умножение
	TFrac operator - (const TFrac right) const; // вычитание
	TFrac operator / (const TFrac right) const; // деление
	TFrac Square(); // квадрат
	TFrac Invert(); // обратное
	TFrac operator - () const; // минус
	bool operator == (const TFrac& right) const; // равно
	bool operator > (const TFrac& right) const; // больше
	bool operator < (const TFrac& right) const; // меньше
	string GetFrac(); // получить дробь
	template<typename T> T GetNum(); // получить числитель
	template<typename T> T GetDenom(); // получить знаменатель
};

