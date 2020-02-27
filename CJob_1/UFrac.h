// UFrac.h

#pragma once
#include "string"

using namespace std;

class TFrac
{
private:
	int num;             //���������
	int denom;           //�����������
	int GetNOD(int a, int b) const; // ����� ����������� ������ ��������
	void SetNumDenom(int n, int d); // ���������� �����

public:
	TFrac(); // ����������� �� ���������
	~TFrac(); // ����������
	TFrac(int n, int d); // ����������� �����
	TFrac(string s); // ����������� ������
	TFrac(const TFrac& F); // �����������
	TFrac operator + (const TFrac right) const; // ��������
	TFrac operator * (const TFrac right) const; // ���������
	TFrac operator - (const TFrac right) const; // ���������
	TFrac operator / (const TFrac right) const; // �������
	TFrac Square(); // �������
	TFrac Invert(); // ��������
	TFrac operator - () const; // �����
	bool operator == (const TFrac& right) const; // �����
	bool operator > (const TFrac& right) const; // ������
	bool operator < (const TFrac& right) const; // ������
	string GetFrac(); // �������� �����
	template<typename T> T GetNum(); // �������� ���������
	template<typename T> T GetDenom(); // �������� �����������
};

