// Лаба21(К4).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

/*Базовый класс:
Пара чисел first - int, second - int.
Определить методы изменения полей и операцию сложения пар (a,b)+(c,d)=(a+b,c+d)
Производный класс:
ДЕНЕЖНАЯ_СУММА(MONEY), с полями Рубли и Копейки.
Переопределить операцию сложения и определить операции вычитания и деления денежных сумм.*/


#include <iostream>
using namespace std;

// Базовый класс
class Pair
{
	int first, second;
public:
	Pair()
	{
		int firsi = 0;
		int second = 0;
	}

	~Pair() {}

	Pair(int f, int s)
	{
		first = f;
		second = s;
	}

	Pair(const Pair& t)
	{
		first = t.first;
		second = t.second;
	}

	int get_first() 
	{ 
		return first; 
	};

	int get_second() 
	{ 
		return second;
	};

	void set_first(int f)
	{
		first = f;
	}


	void set_second(int s)
	{
		second = s;
	}

	//перегруженные операции
	Pair& operator = (const Pair&);
	Pair operator + (const Pair&);

	//глобальные функции ввода-вывода
	friend istream& operator >> (istream& in, Pair& t);
	friend ostream& operator << (ostream& out, Pair& t);
};


Pair& Pair::operator = (const Pair& t)
{
	if (&t == this)
	{
		return *this;
	}
	first = t.first;
	second = t.second;
	return *this;
}


Pair Pair::operator + (const Pair& t)
{
	int temp1 = first;
	int temp2 = second;
	int  temp3 = t.first;
	int temp4 = t.second;

	Pair p;
	p.first = (temp1 + temp2);
	p.second = (temp3 + temp4);
	return p;
}


istream& operator >> (istream& in, Pair& t)
{
	cout << "Введите первое число: "; in >> t.first;
	cout << "Введите второе число: "; in >> t.second;
	cout << endl;
	return in;
}


ostream& operator << (ostream& out, Pair& t)
{
	out << "Первое число = " << t.first << endl;
	out << "Второе число = " << t.second << endl;
	out << endl;
	return out;
}








// Производный класс
class Money : public Pair
{
	long ruble;
	int penny;
public:
	Money()
	{
		ruble = 0;
		penny = 0;
	};

	Money(int m, int s)
	{
		ruble = m;
		penny = s;
	}

	Money(const Money& t)
	{
		ruble = t.ruble;
		penny = t.penny;
	}

	~Money()
	{ };

	int get_rub() {
		return ruble;
	}

	int get_pen()
	{
		return penny;
	}

	void set_rub(int m)
	{
		ruble = m;
	}

	void set_pen(int s)
	{
		penny = s;
	}

	//перегруженные операции
	Money& operator = (const Money&);
	Money operator + (const Money&);
	Money operator - (const Money&);
	Money operator / (const Money&);
	Money operator % (const Money&);

	//глобальные функции ввода-вывода
	friend istream& operator >> (istream& in, Money& t);
	friend ostream& operator << (ostream& out, const Money& t);
};



Money& Money::operator = (const Money& t)
{
	//проверка на самоприсваивание
	if (&t == this)
	{
		return *this;
	}
	ruble = t.ruble;
	penny = t.penny;
	return *this;
}


//перегрузка бинарной операции сложения
Money Money::operator + (const Money& t)
{
	int temp1 = ruble * 100 + penny;
	int temp2 = t.ruble * 100 + t.penny;
	Money p;
	p.ruble = (temp1 + temp2) / 100;
	p.penny = (temp1 + temp2) % 100;
	return p;
}


//перегрузка бинарной операции вычитания
Money Money::operator - (const Money& t)
{
	int temp1 = ruble * 100 + penny;
	int temp2 = t.ruble * 100 + t.penny;
	Money p;
	p.ruble = (temp1 - temp2) / 100;
	p.penny = (temp1 - temp2) % 100;
	return p;
}


//перегрузка бинарной операции деления
Money Money::operator / (const Money& t)
{
	int temp1 = ruble * 100 + penny;
	int temp2 = t.ruble * 100 + t.penny;
	Money p;
	p.ruble = (temp1 - temp2) / 100;
	return p;
}


//перегрузка бинарной операции остатока от деления
Money Money::operator % (const Money& t)
{
	int temp1 = ruble * 100 + penny;
	int temp2 = t.ruble * 100 + t.penny;
	Money p;
	p.penny = (temp1 - temp2) % 100;
	return p;
}


//перегрузка глобальной функции-операции ввода
istream& operator>>(istream& in, Money& t)
{
	cout << "Введите количество рублей" << endl;
	in >> t.ruble;
	cout << "Введите количество копеек" << endl;
	in >> t.penny;
	cout << endl;
	return in;
}


//перегрузка глобальной функции-операции вывода
ostream& operator<<(ostream& out, const Money& t)
{
	return (out << t.ruble << " , " << t.penny);
}







int main() {

	setlocale(LC_ALL, "Rus");

	Pair a;
	Pair b;
	Pair c;

	cout << "Введите данные двух чисел" << endl;
	cin >> a;
	cin >> b;
	cout << endl << endl;

	cout << "Использовав формулу (a,b)+(c,d)=(a+b,c+d). Получилось" << endl;
	c = a + b;
	cout << c << endl << endl;

	Money d;
	Money e;
	Money f;
	Money g;
	Money k;

	cout << "Введите данные двух чисел" << endl;
	cin >> d;
	cin >> e;


	cout << "Получены данные" << endl;
	cout << "d =  " << d << endl;
	cout << "e =  " << e << endl << endl;


	cout << "Разность между этими числами" << endl;
	f = d - e;
	cout << f << endl << endl;

	cout << "Целая часть от этого числа" << endl;
	g = d / e;
	cout << g << endl << endl;

	cout << "Дробная часть от этого числа" << endl;
	k = d % e;
	cout << k;

	cout << endl << endl;
}