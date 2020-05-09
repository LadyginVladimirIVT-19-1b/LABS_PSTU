#include "Time.h"



Time::Time()
{
	minutes = 0;
	seconds = 0;
}
Time::Time(int N, int A)
{
	minutes = N;
	seconds = A;
}
Time::Time(const Time& p)
{
	minutes = p.minutes;
	seconds = p.seconds;
}
Time::~Time()
{
}


Time Time::operator = (const Time& p)
{
	if (&p == this) return *this;
	minutes = p.minutes;
	seconds = p.seconds;
	return*this;
}



//���������� ���������� �������� ���������
Time& Time::operator++()
{
	int temp = minutes * 60 + seconds + 90;
	minutes = temp / 60;
	seconds = temp % 60;
	return *this;
}


//���������� ����������� �������� ���������
Time Time::operator ++(int)
{
	int temp = minutes * 60 + seconds + 90;
	Time t(minutes, seconds);
	minutes = temp / 60;
	seconds = temp % 60;
	return t;
}



//���������� ���������� ��������
bool operator == (const Time& temp1, const Time& temp2)
{
	return ((temp1.minutes == temp2.minutes) && (temp1.seconds == temp2.seconds));
}


bool operator!= (const Time& temp1, const Time& temp2)
{
	return !(temp1 == temp2);
}


bool operator > (const Time& temp1, const Time& temp2)
{
	return ((temp1.minutes > temp2.minutes) || ((temp1.minutes == temp2.minutes) && (temp1.seconds > temp2.seconds)));
}


ostream& operator << (ostream& out, const Time& p)
{
	cout << "����� - ��� ������ ����� �������" << endl;
	out << "�����" << endl;
	out << p.minutes << " : " << p.seconds << "\n";
	return out;
}


istream& operator >> (istream& in, Time& p)
{
	cout << endl;
	cout << "���������� �����?   ";
	in >> p.minutes;
	cout << "���������� ������?   ";
	in >> p.seconds;

	int tmp;
	tmp = p.minutes * 60 - p.seconds;
	p.minutes = tmp / 60;
	p.seconds = tmp % 60;


	return in;
}

//������������� ������� ��� ������ � ��������� ��������
fstream& operator >> (fstream& fin, Time& p)
{
	fin >> p.minutes;
	fin >> p.seconds;
	return fin;
}


fstream& operator << (fstream& fout, const Time& p)
{
	fout << p.minutes << "\n" << p.seconds << "\n";
	return fout;
}
