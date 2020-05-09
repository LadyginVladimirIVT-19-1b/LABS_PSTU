#pragma once


#include <iostream>
#include <ctime>
#include <vector>
#include<deque>
#include "Money.h"
using namespace std;


template<class T>
class Vector
{
	deque <T> s;//контейнер
	int len;//размер контейнера
public:
	Vector();//конструктор без параметров
	Vector(int n);//конструктор с параметрами
	Vector(const Vector<T>&);//конструктор копирования


	void Print_deque();
	void Add_to_deque(T el, int pos);
	T Max();
	T Min();
	void Delete_from_deque(T key);
	void Multiplication();
};



//конструктор без параметров
template <class T>
Vector<T>::Vector()
{
	len = 0;
}



//конструктор с параметром
template <class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		s.push_back(a);//добавить в стек элемент а
	}
	len = s.size();
}



//конструктор копирования
template <class T>
Vector<T>::Vector(const Vector<T>& Vec)
{
	len = Vec.len;
	//копируем значения стека Vec.s в вектор v
	Vector v = copy_deque_to_vector(v.s);
	//копируем вектор v в стек s
	s = copy_vector_to_deque(Vec);
}




//копирование очереди в вектор
template <class T>
vector<T> copy_deque_to_vector(deque<T> s)
{
	vector<T> v;
	while (!s.empty())
	{
		v.push_back(s.front());
		s.pop_front();
	}
	return v;
}


//копирование вектора в очередь
template <class T>
deque<T> copy_vector_to_deque(vector<T> v)
{
	deque<T> s;
	for (int i = 0; i < v.size(); i++)
	{
		s.push_back(v[i]);
	}
	return s;
}




//печать
template <class T>
void Vector<T>::Print_deque()
{
	cout << "Наша очередь" << endl;
	//копируем очереди в вектор
	vector<T> v = copy_deque_to_vector(s);

	while (!s.empty())//пока очередь не пуста
	{
		cout << s.front() << endl;//вывод элемента в вершине очереди
		s.pop_front();//удаляем элемент из вершины очереди
	}

	//копируем вектор в очередь
	s = copy_vector_to_deque(v);
	cout << endl << endl;
}



//поиск максимального элемента очереди
template <class T>
T Vector<T>::Max()
{
	T m = s.front();//m присвоить значение из вершины очереди
	//в вектор скопировать элементы очереди
	vector<T> v = copy_deque_to_vector(s);

	while (!s.empty())//пока очередь не пуста
	{
		//сравниваем m и элемент в вершине очереди
		if (s.front() > m)m = s.front();
		s.pop_front();//удаляем элемент из вершины очереди
	}

	s = copy_vector_to_deque(v);//копируем вектор в очередь
	cout << "Максимальный элемент   " << m << endl;
	return m;
}


//поиск минимального элемента очереди
template <class T>
T Vector<T>::Min()
{
	T m = s.front();
	vector<T> v = copy_deque_to_vector(s);

	while (!s.empty())
	{
		if (s.front() < m)m = s.front();
		s.pop_front();
	}

	s = copy_vector_to_deque(v);
	cout << "Минимальный элемент   " << m << endl;
	return m;
}




//добавление элемента key в очередm на позицию pos
template <class T>
void Vector<T>::Add_to_deque(T key, int pos)
{
	vector <T>v;//вспомогательный вектор
	T t;
	int i = 1;

	while (!s.empty())//пока очередь не пуста
	{
		t = s.front();//получить элемент из вершины очереди
		//если номер элемента равен pos добавляем в вектор новый элемент 
		if (i == pos)
		{
			v.push_back(key);
		}
		v.push_back(t);//добавляем t в вектор
		s.pop_front();//удаляем элемент из вершины очереди
		i++;
	}

	s = copy_vector_to_deque(v);//копируем вектор в очередь
}



//удаление элемента из вектора
template <class T>
void Vector<T>::Delete_from_deque(T key)
{
	vector<T> v;
	T t;
	bool answer = false;

	while (!s.empty())//пока очередь не пуста
	{
		t = s.front();//получить элемент из вершины очереди
		//если t не равен ключу, то добавить его в вектор
		if (t != key)
		{
			v.push_back(t);
		}
		else
		{
			answer = true;
		}
		s.pop_front();//удалить элемент из очереди
	}

	//копируем вектор в очередь
	s = copy_vector_to_deque(v);

	if (answer == false)
	{
		cout << "В векторе нет элементов с данным значением" << endl;
	}
}




//умножение всех элементов на максимальный элемент очереди
template <class T>
void Vector<T>::Multiplication()
{
	vector<T> v;
	T m = Max();
	T t;

	while (!s.empty())
	{
		t = s.front();
		v.push_back(t * m);
		s.pop_front();
	}

	s = copy_vector_to_deque(v);
}
