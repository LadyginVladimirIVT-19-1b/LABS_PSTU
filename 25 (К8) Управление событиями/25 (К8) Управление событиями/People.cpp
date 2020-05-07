#include "People.h"
#include "Event.h"


//конструктор без параметров
People::People(void)
{
	Name = "";
	Age = 0;
}


//деструктор
People::~People(void)
{}


//констрктор с параметрами
People::People(string N, int A)
{
	Name = N;
	Age = A;;
}


//конструктор копирования
People::People(const People& car)
{
	Name = car.Name;
	Age = car.Age;
}


//селекторы
void People::Set_Age(int A)
{
	Age = A;
}
void People::Set_Name(string N)
{
	Name = N;
}

//оператор присваивания
People& People::operator=(const People& c)
{
	if (&c == this)return *this;
	Name = c.Name;
	Age = c.Age;
	return *this;
}


//метод для просмотра атрибутов
void People::Show()
{
	cout << "\nName : " << Name;
	cout << "\nAge : " << Age;
	cout << endl << endl;
}


//метод для ввода значений атрибутов
void People::Input()
{
	cout << "\nName:"; cin >> Name;
	cout << "\nAge:"; cin >> Age;
	cout << endl << endl;
}


int sum = 0;
int k = 0;

void People::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)//событие-сообщение
	{
		switch (e.command)
		{
		case cmGet:
			sum = sum + Get_Age();
			k++;
			cout << "Возраст человека" << endl << Get_Age() << endl << endl;
			break;
		}
	}
}


void People::average_age(const TEvent& e)
{
	cout << "Общий возраст" << endl << sum << endl << endl;
	sum = sum / k;
	cout << "Средний возраст" << endl << sum << endl << endl;
}


