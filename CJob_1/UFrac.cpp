// UFrac.cpp

#include "pch.h"
#include "UFrac.h"
#include "string"
#include "sstream"
#include "iostream"

using namespace std;

// ����������� �� ���������
TFrac::TFrac() : num(0), denom(1)
{  }

// ����������
TFrac::~TFrac()
{
}

// ����� ����������� ������ ��������
int TFrac::GetNOD(int a, int b) const
{
	while (a != 0 && b != 0)
	{
		if (a >= b) a = a % b;
		else b = b % a;
	}
	return a + b;
}

// ���������� �����
void TFrac::SetNumDenom(int n, int d)
{
	if (d == 0)
	{
		cout << "��� ����� " << n << "/" << d << " ����������� �� ����� ���� ����� ����." << endl;
		num = 0;
		denom = 1;
	}
	else {
		int nod = GetNOD(abs(n), abs(d));
		if (d < 0)     //���������� ����� � ���������
		{
			n *= -1;
			d *= -1;
		}
		num = n / nod;
		denom = d / nod;
	}
}

// ����������� �����
TFrac::TFrac(int n, int d)
{
	SetNumDenom(n, d);
}

// ����������� ������
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

// �����������
TFrac::TFrac(const TFrac& F)
{
	num = F.num;
	denom = F.denom;
};

//������������� �������� +
TFrac TFrac::operator + (const TFrac right) const
{
	int tempnum = num * right.denom + denom * right.num;
	int tempdenom = denom * right.denom;
	TFrac Result = TFrac(tempnum, tempdenom);
	return Result;
}

//������������� �������� *
TFrac TFrac::operator * (const TFrac right) const
{
	int tempnum = num * right.num;
	int tempdenom = denom * right.denom;
	TFrac Result = TFrac(tempnum, tempdenom);
	return Result;
}

//������������� �������� -
TFrac TFrac::operator - (const TFrac right) const
{
	int tempnum = num * right.denom - denom * right.num;
	int tempdenom = denom * right.denom;
	TFrac Result = TFrac(tempnum, tempdenom);
	return Result;
}

//������������� �������� /
TFrac TFrac::operator / (const TFrac right) const
{
	TFrac Result;
	if (right.num == 0) {
		cout << "������� �� ���������. �������� �� ����� ���� ����� 0" << endl;
		Result = TFrac(num, denom);
	}
	else {
		int tempnum = num * right.denom;
		int tempdenom = denom * right.num;
		Result = TFrac(tempnum, tempdenom);
	}
	return Result;
}

//�������
TFrac TFrac::Square()
{
	int tempnum = num * num;
	int tempdenom = denom * denom;
	TFrac Result = TFrac(tempnum, tempdenom);
	return Result;
};

//��������
TFrac TFrac::Invert()
{
	int tempnum = denom;
	int tempdenom = num;
	TFrac Result = TFrac(tempnum, tempdenom);
	return Result;
};

//�����
TFrac TFrac::operator - () const
{
	int tempnum = -num;
	int tempdenom = denom;
	TFrac Result = TFrac(tempnum, tempdenom);
	return Result;
};

//�������������  �������� ==
bool TFrac::operator == (const TFrac& right) const
{
	return (((num == right.num) && (denom == right.denom)) ? true : false);
}

// ������
bool TFrac::operator > (const TFrac& right) const
{
	int a = num * right.denom;
	int b = right.num * denom;
	return ((a > b) ? true : false);
};

// ������
bool TFrac::operator < (const TFrac& right) const
{
	int a = num * right.denom;
	int b = right.num * denom;
	return ((a < b) ? true : false);
};

string TFrac::GetFrac() // �������� �����
{
	return to_string(num) + "/" + to_string(denom);
}

template<> int TFrac::GetNum() { return num; } // �������� ��������� �����
template<> string TFrac::GetNum() { return to_string(num); } // �������� ��������� ������
template<> int TFrac::GetDenom() { return denom; } // �������� ����������� �����
template<> string TFrac::GetDenom() { return to_string(denom); } // �������� ����������� ������

