#include "Object.h"
#include "People.h"
#include "Abiturient.h"
#include "Person.h"
#include "Event.h"



//деструктор
Person::~Person(void)
{
	if (beg != 0)delete[] beg;
	beg = 0;
}


//конструктор с параметрами
Person::Person(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}


//добавление объекта, на который указывает указатель p в Person
void Person::Add()
{
	Object* p;
	//выбор из объектов двух возможных классов
	cout << "1.People" << endl;
	cout << "2.Abiturient" << endl;
	int y;
	cin >> y;
	if (y == 1)//добавление объекта класса People
	{
		People* a = new (People);
		a->Input();//ввод значений атрибутов
		p = a;
		if (cur < size)
		{
			beg[cur] = p;//добавление в Person
			cur++;
		}
	}
	else
	{
		if (y == 2) //добавление объекта класса Abiturient
		{
			Abiturient* b = new Abiturient;
			b->Input();
			p = b;
			if (cur < size)
			{
				beg[cur] = p;
				cur++;
			}
		}

		else return;
	}
}


//просмотр Person
void Person::Show()
{
	if (cur == 0) cout << "Empty" << endl << endl;
	Object** p = beg;//указатель на указатель типа Object
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();//вызов метода Show() (позднее связывание)
		p++;//передвигаем указатель на следующий объект
	}
}



//операция, которая возвращает размер Person
int Person::operator ()()
{
	return cur;
}


//удаление элемента из Person, память не освобождается!
void Person::Del()
{
	if (cur == 0)return;//пустой
	cur--;
}



void Person::HandleEvent(const TEvent& e)
{
	if (cur == 0)
	{
		cout << "Empty" << endl << endl;
	}
	else
	{
		if (e.what == evMessage)
		{
			Object** p = beg;
			for (int i = 0; i < cur; i++)
			{
				(*p)->HandleEvent(e);//вызов метода (позднее связывание)
				p++;//передвигаем указатель на следующий объект				
			}
			p = beg;
			(*p)->average_age(e);//вызов метода (позднее связывание)
		}
	}
}

