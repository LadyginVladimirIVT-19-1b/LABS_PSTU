#pragma once


#include <iostream>
#include <cstdlib>
#include <vector>
#include "Money.h"
using namespace std;



//шаблон класса
template<class T>
class Vector
{
	vector <T> v;//последовательный контейнер дл€ хранени€ элементов вектора
	int len;
public:
	Vector(void);//конструктор без параметра
	Vector(int n);//конструктор с параметром
	~Vector(void);//деструктор

	void Print_vector();//печать	
	void Add_elem(T el, int pos);//добавление элемента el на позицию pos
	int Max();//найти номер максимальнго элемента
	void Delete_vector(Money key);//удалить элемент из позиции pos
	Money Min();//найти номер минимальнго элемента
	void Multiplication();//деление на минимальный
};


//конструктор без параметра
template <class T>
Vector<T>::Vector()
{
	len = 0;
}


//деструктор
template <class T>
Vector<T>::~Vector(void)
{
}


//конструктор с параметром
template <class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	len = v.size();
}



//печать
template <class T>
void Vector<T>::Print_vector()
{
	cout << "Ќаш вектор" << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "     ";
	cout << endl << endl;
}


//добавление элемента
template<class T>
void Vector<T>::Add_elem(T el, int pos)
{
	v.insert(v.begin() + pos, el);
}


//поиск максимального элемента
template <class T>
int Vector<T>::Max()
{
	T m = v[0];
	int n = 0;
	for (int i = 1; i < v.size(); i++)
		if (v[i] > m)
		{
			m = v[i];
			n = i;
		}
	cout << "ћаксимальный элемент   " << m << endl << endl;
	return n;
}


//удаление элемента из позиции pos
template<class T>
void Vector<T>::Delete_vector(Money key)
{
	bool answer = false;
	int num = 0;
	for (int i = 0; i < v.size(); i++)//перебор вектора
	{
		if (v[i] == key)
		{
			v.erase(v.begin() + num);
			answer = true;
			i--;
			num--;
		}
		num++;
	}
	cout << endl;

	if (answer == false)
	{
		cout << "¬ векторе нет элементов с данным значением" << endl;
	}
	cout << endl;
}


//поиск минимального элемента
template<class T>
Money Vector<T>::Min()
{
	T m = v[0];
	int n = 0;
	for (int i = 1; i < v.size(); i++)
		if (v[i] < m)
		{
			m = v[i];
			n = i;
		}
	cout << "ћинимальный элемент   " << m << endl << endl;
	return m;
}


//деление всех элементов вектора на минимальный элемент
template<class T>
void Vector<T>::Multiplication()
{
	int m = Max();
	T max = v[m];
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] * max;
}