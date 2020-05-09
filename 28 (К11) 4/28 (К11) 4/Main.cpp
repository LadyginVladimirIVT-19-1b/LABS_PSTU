/*Задача 4
Адаптер контейнера – очередь с приоритетами

Задание 1: Найти минимальный элемент и добавить его на заданную позицию контейнера
Задание 2: Найти элементы с ключами из заданного диапазона и удалить их из контейнера
Задание 3: Каждый элемент умножить на максимальный элемент контейнера*/


#include <iostream>
#include <ctime>
#include <vector>
#include<deque>
#include "Money.h"
using namespace std;

typedef deque <Money> Deq;//очередь
typedef vector <Money> Vec;//вектор



//копирует очередь в вектор
Vec copy_deque_to_vector(Deq s)
{
	Vec v;
	while (!s.empty())//пока очередь не пуста
	{
		//добавить в вектор элемент из вершиы очереди
		v.push_back(s.front());
		s.pop_front();
	}
	return v; //вернуть вектор как результат функции
}



//копирует вектор вочередь
Deq copy_vector_to_deque(Vec v)
{
	Deq s;
	for (int i = 0; i < v.size(); i++)
	{
		s.push_front(v[i]);//добавить в очередь элемент вектора
	}
	return s; //вернуть очередь как результат функции
}



Deq make_deque(int n)
{
	Deq d;
	Money t;
	for (int i = 0; i < n; i++)
	{
		cin >> t;//ввод переменной
		d.push_back(t);//добавление в очередь
	}
	return d;//вернуть очередь как результат функции
}


Deq print_deque(int n, Deq s)
{
	cout << "Наша очередь" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << s.front() << endl;
		s.pop_front();
	}
	cout << endl << endl;
	return s;//вернуть очередь как результат функции
}



//поиск максимального элемента в очереди
Money Max(Deq s)
{
	Money m = s.front();//переменной m присваиваем значение из вершины очереди
	Vec v = copy_deque_to_vector(s);//копируем очередь в вектор

	while (!s.empty())//пока очередь не пуста
	{
		if (s.front() > m)m = s.front();//сравниваем m и элемент в вершине очереди
		s.pop_front();//удаляем элемент из очереди
	}
	s = copy_vector_to_deque(v);//копиуем вектор в очередь

	cout << "Максимальный элемент   " << m << endl;
	return m; 
}


//поиск минимального элемента в очереди
Money Min(Deq s)
{
	Money m = s.front();
	Vec v = copy_deque_to_vector(s);

	while (!s.empty())
	{
		if (s.front() < m)m = s.front();
		s.pop_front();
	}
	s = copy_vector_to_deque(v);
	cout << "Минимальный элемент   " << m << endl;
	return m;
}


//добавление элемента в очередь
void Add_to_deque(Deq& s, Money el, int pos, int& n)
{
	Vec v;
	Money t;
	int i = 1;//номер элемента в очереди
	while (!s.empty())//пока очередь не пуста
	{
		t = s.front();//получить элемент из вершины
		//если номер равен номеру позиции, на котоую добвляем элемент
		if (i == pos)
		{
			v.push_back(el);//добавить новый элемент в вектор
			n++;
		}
		v.push_back(t);//добавить элемент из очереди в вектор
		s.pop_front();//удалить элемент из очереди
		i++;
	}
	s = copy_vector_to_deque(v);//копируем вектор в очередь
}



//Удалить элементы кратные ключу из очереди
void Delete_from_deque(Deq& s, int& n, Money key)
{
	Vec v;
	Money t;
	bool answer = false;

	while (!s.empty())//пока очередь не пустой
	{
		t = s.front();//получаем элемент из вершины очереди
		//если он не равен максимальному, заносим элемент в вектор
		if (t != key)
		{
			v.push_back(t);
		}
		else
		{
			n--;
			answer = true;
		}
		s.pop_front();//удаляем элемент из очереди
	}
	s = copy_vector_to_deque(v);//копируем вектор в очередь

	if (answer == false)
	{
		cout << "В векторе нет элементов с данным значением" << endl;
	}
}

//Умножение элементов
void multiplication(Deq& s)
{
	Money m = Max(s);//находим максимальный элемент очереди
	Vec v;
	Money t;
	while (!s.empty())//пока  очередь не пуста
	{
		t = s.front(); //получаем элемент из вершины  очереди
		v.push_back(t * m);//умножаем t на максимальный элемент  очереди и добавляем в вектор
		s.pop_front();//удаляем элемент из вершины  очереди
	}
	s = copy_vector_to_deque(v);//копируем вектор в очередь
}


void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	Money t;
	Deq s;
	int n;

	cout << "Введите количество элементов?   ";
	cin >> n;
	cout << endl;

	s = make_deque(n);//создать очередь
	print_deque(n, s);//печать очереди


	Money m = Min(s);
	cout << "Добавить его на позицию?   ";
	int pos;
	cin >> pos;//ввести позицию для добавления
	Add_to_deque(s, m, pos, n);
	print_deque(n, s);//печать очереди
	
	Money key;
	cout << "Введите значение, которое надо удалит?  " << endl;
	cin >> key;

	cout << "Удаляем все элементы, равные данному значению    " << key << endl;
	Delete_from_deque(s, n, key);//удаление
	print_deque(n, s);//печать очереди

	cout << "Умножаем все элементы на максимальный элемент" << endl;
	multiplication(s);
	print_deque(n, s);

}
