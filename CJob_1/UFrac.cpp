// UFrac.cpp

#include "pch.h"
#include "UFrac.h"
#include "string"
#include "sstream"
#include "iostream"

using namespace std;

// конструктор по умолчанию
TFrac::TFrac() : num(0), denom(1)
{  }

// деструктор
TFrac::~TFrac()
{
}

// поиск наибольшего общего делителя
int TFrac::GetNOD(int a, int b) const
{
	while (a != 0 && b != 0)
	{
		if (a >= b) a = a % b;
		else b = b % a;
	}
	return a + b;
}

// установить дробь
void TFrac::SetNumDenom(int n, int d)
{
	if (d == 0)
	{
		cout << "Для дроби " << n << "/" << d << " знаменатель не может быть равен нулю." << endl;
		num = 0;
		denom = 1;
	}
	else {
		int nod = GetNOD(abs(n), abs(d));
		if (d < 0)     //приведение знака к числителю
		{
			n *= -1;
			d *= -1;
		}
		num = n / nod;
		denom = d / nod;
	}
}

// конструктор число
TFrac::TFrac(int n, int d)
{
	SetNumDenom(n, d);
}

// конструктор строка
TFrac::TFrac(string s)
{
	istringstream iss(s);
	string sn, sd;
	getline(iss, sn, '/');
	getline(iss, sd);
	int n, d;
	n = stoi(sn);
	d = stoi(sd);

	SetNumDenom(n, d);
};

// копирование
TFrac::TFrac(const TFrac& F)
{
	num = F.num;
	denom = F.denom;
};

//перегружаемая операция +
TFrac TFrac::operator + (const TFrac right) const
{
	int tempnum = num * right.denom + denom * right.num;
	int tempdenom = denom * right.denom;
	TFrac Result = TFrac(tempnum, tempdenom);
	return Result;
}

//перегружаемая операция *
TFrac TFrac::operator * (const TFrac right) const
{
	int tempnum = num * right.num;
	int tempdenom = denom * right.denom;
	TFrac Result = TFrac(tempnum, tempdenom);
	return Result;
}

//перегружаемая операция -
TFrac TFrac::operator - (const TFrac right) const
{
	int tempnum = num * right.denom - denom * right.num;
	int tempdenom = denom * right.denom;
	TFrac Result = TFrac(tempnum, tempdenom);
	return Result;
}

//перегружаемая операция /
TFrac TFrac::operator / (const TFrac right) const
{
	TFrac Result;
	if (right.num == 0) {
		cout << "Деление не произошло. Делитель не может быть равен 0" << endl;
		Result = TFrac(num, denom);
	}
	else {
		int tempnum = num * right.denom;
		int tempdenom = denom * right.num;
		Result = TFrac(tempnum, tempdenom);
	}
	return Result;
}

//квадрат
TFrac TFrac::Square()
{
	int tempnum = num * num;
	int tempdenom = denom * denom;
	TFrac Result = TFrac(tempnum, tempdenom);
	return Result;
};

//обратное
TFrac TFrac::Invert()
{
	int tempnum = denom;
	int tempdenom = num;
	TFrac Result = TFrac(tempnum, tempdenom);
	return Result;
};

//минус
TFrac TFrac::operator - () const
{
	int tempnum = -num;
	int tempdenom = denom;
	TFrac Result = TFrac(tempnum, tempdenom);
	return Result;
};

//перегруженный  оператор ==
bool TFrac::operator == (const TFrac& right) const
{
	return (((num == right.num) && (denom == right.denom)) ? true : false);
}

// больше
bool TFrac::operator > (const TFrac& right) const
{
	int a = num * right.denom;
	int b = right.num * denom;
	return ((a > b) ? true : false);
};

// меньше
bool TFrac::operator < (const TFrac& right) const
{
	int a = num * right.denom;
	int b = right.num * denom;
	return ((a < b) ? true : false);
};

string TFrac::GetFrac() // получить дробь
{
	return to_string(num) + "/" + to_string(denom);
}

template<> int TFrac::GetNum() { return num; } // получить числитель число
template<> string TFrac::GetNum() { return to_string(num); } // получить числитель строка
template<> int TFrac::GetDenom() { return denom; } // получить знаменатель число
template<> string TFrac::GetDenom() { return to_string(denom); } // получить знаменатель строка

