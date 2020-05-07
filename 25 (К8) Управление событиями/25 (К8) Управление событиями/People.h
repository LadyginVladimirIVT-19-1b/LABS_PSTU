#pragma once
#include <iostream>
#include "Object.h"
#include "People.h"
#include "Event.h"
using namespace std;


class People :
	public Object
{
public:
	People(void);				//конструктор без параметров

public:
	virtual ~People(void);		//деструктор
	void Show();				//функция для просмотра атрибутов класса с помощью указателя
	void Input();				//функция для ввода значений атрибутов
	People(string, int);		//конструктор с параметрами
	People(const People&);		//конструктор копирования

	//селекторы
	string Get_Name() { return Name; }
	int Get_Age() { return Age; }

	//модификаторы
	void Set_Name(string);
	void Set_Age(int);

	People& operator=(const People&);		//перегрузка операции присваивания
	void HandleEvent(const TEvent& e);
	void average_age(const TEvent& e);
protected:
	string Name;
	int Age;
};
