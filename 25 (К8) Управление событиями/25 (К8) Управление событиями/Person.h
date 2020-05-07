#pragma once
#include <iostream>
#include "Object.h"
#include "Event.h"
#include "Person.h"

using namespace std;


class Person
{
public:
	Person(int);//����������� � �����������
public:
	~Person(void);//����������
	void Add();//���������� �������� � Person
	void Del();
	void Show();
	
	int operator()();//������ Person
	void HandleEvent(const TEvent& e);
	void average_age(const TEvent& e);
protected:
	Object** beg;//��������� �� ������ ������� Person
	int size;//������
	int cur;//������� �������
};

