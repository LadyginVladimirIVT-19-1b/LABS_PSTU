#include "Money.h"



//перегрузка операции присваивани€
Money& Money::operator = (const Money& t)
{
	//проверка на самоприсваивание
	if (&t == this) return *this;
	ruble = t.ruble;
	penny = t.penny;
	return *this;
}


//перегрузка глобальной функции-операции ввода
istream& operator >> (istream& in, Money& t)
{
	cout << " оличество рублей?   "; in >> t.ruble;
	cout << " оличество копеек?   "; in >> t.penny;


	int tmp;
	tmp = t.ruble * 100 + t.penny;
	t.ruble = tmp / 100;
	t.penny = tmp % 100;


	cout << endl;
	return in;
}



//перегрузка глобальной функции-операции вывода
ostream& operator<<(ostream& out, const Money& t)
{
	return (out << t.ruble << " : " << t.penny);
}


bool Money::operator < (const Money& t)
{
	if (ruble < t.ruble)return true;
	if (ruble == t.ruble && penny < t.penny)return true;
	return false;
}


bool Money::operator > (const Money& t)
{
	if (ruble > t.ruble)return true;
	if (ruble == t.ruble && penny > t.penny)return true;
	return false;
}


Money Money::operator + (const Money& t)
{
	int temp1 = ruble * 100 + penny;
	int temp2 = t.ruble * 100 + t.penny;
	Money p;
	p.ruble = (temp1 + temp2) / 100;
	p.penny = (temp1 + temp2) % 100;
	return p;
}

//перегрузка бинарной операции умножени€
Money Money::operator * (const Money& t)
{
	int temp1 = ruble * 100 + penny;
	int temp2 = t.ruble * 100 + t.penny;
	Money p;
	p.ruble = (temp1 * temp2) / 100;
	p.penny = (temp1 * temp2) % 100;
	return p;
}


Money Money::operator * (const int& t)
{
	int temp1 = ruble * 100 + penny;
	Money p;
	p.ruble = (temp1 * t) / 100;
	p.penny = (temp1 * t) % 100;
	return p;
}

//перегрузка логических операций
bool operator == (const Money& temp1, const Money& temp2)
{
	return ((temp1.ruble == temp2.ruble) && (temp1.penny == temp2.penny));
}



bool operator != (const Money& temp1, const Money& temp2)
{
	return !(temp1 == temp2);
}
