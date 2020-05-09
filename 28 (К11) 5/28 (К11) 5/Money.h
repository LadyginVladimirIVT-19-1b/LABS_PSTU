#pragma once


#include <iostream>
using namespace std;


class Money
{
	int ruble;
	int penny;
public:
	Money() { ruble = 0; penny = 0; };
	Money(int r, int p) { ruble = r; penny = p; }
	Money(const Money& t) { ruble = t.ruble; penny = t.penny; }
	~Money() {};


	int get_min() { return ruble; }
	int get_sec() { return penny; }
	void set_min(int r) { ruble = r; }
	void set_sec(int p) { penny = p; }


	//перегруженные операции
	Money& operator = (const Money&);
	Money operator + (const Money&);
	Money operator * (const Money&);
	Money operator * (const int&);
	bool operator > (const Money&);
	bool operator < (const Money&);


	//глобальные функции ввода-вывода
	friend istream& operator >> (istream& in, Money& t);
	friend ostream& operator << (ostream& out, const Money& t);

	//перегруженные бинарная операции
	friend bool operator == (const Money& temp1, const Money& temp2);
	friend bool operator != (const Money& temp1, const Money& temp2);
};



