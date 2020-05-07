#pragma once
#include <iostream>
#include "Object.h"
#include "Event.h"
#include "Person.h"

using namespace std;


class Person
{
public:
	Person(int);//конструктор с параметрами
public:
	~Person(void);//деструктор
	void Add();//добавление элемента в Person
	void Del();
	void Show();
	
	int operator()();//размер Person
	void HandleEvent(const TEvent& e);
	void average_age(const TEvent& e);
protected:
	Object** beg;//указатель на первый элемент Person
	int size;//размер
	int cur;//текущая позиция
};

