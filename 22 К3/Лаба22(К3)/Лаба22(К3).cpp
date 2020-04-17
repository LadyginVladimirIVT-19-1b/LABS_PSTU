// Лаба22(К3).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

/*Создать класс Money для работы с денежными суммами.
Число должно быть представлено двумя полями : типа long для рублей и типа int для копеек.
Дробная часть числа при выводе на экран должна быть отделена от целой части запятой.
Реализовать :
	— вычитание дробного числа из суммы,
	— операции сравнения(== , != ).*/


#include <iostream>
using namespace std;


class Money
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
	Money& operator ++ ();
	Money operator ++ (int);			//постфиксная операция
	Money& operator -- ();
	Money operator -- (int);			
	Money operator + (const Money&);

	//глобальные функции ввода-вывода
	friend istream& operator >> (istream& in, Money& t);
	friend ostream& operator << (ostream& out, const Money& t);
	friend bool operator == (const Money& temp1, const Money& temp2);
	friend bool operator != (const Money& temp1, const Money& temp2);
};




Money& Money::operator = (const Money& t)
{
	//проверка на самоприсваивание
	if (&t == this) return *this;
	ruble = t.ruble;
	penny = t.penny;
	return *this;
} 


//перегрузка префиксной операции инкремент
Money& Money::operator++()
{
	int temp = ruble * 100 + penny;
	temp++;
	ruble = temp / 100;
	penny = temp % 100;
	return *this;
}


//перегрузка постфиксной операции инкремент
Money Money::operator ++(int)
{
	int temp = ruble * 100 + penny;
	temp++;
	Money t(ruble, penny);
	ruble = temp / 100;
	penny = temp % 100;
	return t;
}


//перегрузка префиксной операции декремент
Money& Money::operator--()
{
	int temp = ruble * 100 + penny;
	temp--;
	ruble = temp / 100;
	penny = temp % 100;
	return *this;
} 


//перегрузка постфиксной операции декремент
Money Money::operator -- (int)
{
	int temp = ruble * 100 + penny;
	temp--;
	Money t(ruble, penny);
	ruble = temp / 100;
	penny = temp % 100;
	return t;
}


//перегрузка бинарной операции сложения
Money Money::operator+(const Money& t)
{
	int temp1 = ruble * 100 - penny;
	int temp2 = t.ruble * 100 - t.penny;
	Money p;
	p.ruble = (temp1 + temp2) / 100;
	p.penny = (temp1 + temp2) % 100;
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


//перегрузка логических операций
bool operator == (const Money& temp1, const Money& temp2)
{
	return ((temp1.ruble == temp2.ruble) && (temp1.penny == temp2.penny));
}


bool operator!= (const Money& temp1, const Money& temp2)
{
	return !(temp1 == temp2);
}



int main()
{
	setlocale(LC_ALL, "Russian");
	Money a;						//конструктор без параметров
	Money b;						//конструктор без параметров
	Money c;						//конструктор без параметров

	cout << "Введите два элемента" << endl;
	cin >> a;					
	cin >> b;
	cout << endl;

	if (a == b)
	{
		cout << "Элементы одинаковые" << endl << endl;
	}
	if (a != b)
	{
		cout << "Элементы не одинаковые" << endl << endl;
	}

	++a;							//префиксная операция инкремент
	cout << "Инкрементировали первый элемент" << endl;
	cout << a << endl << endl;

	cout << endl;
	--b;							//префиксная операция инкремент
	cout << "Декрементировали второй элемент" << endl;
	cout << b << endl << endl;

	--a;
	++b;

	c = a + b;					

	cout << "Подсчитываем данные" << endl;
	cout << "a=" << a << endl; 
	cout << "b=" << b << endl; 
	cout << "c=" << c << endl;
	cout << endl;
}