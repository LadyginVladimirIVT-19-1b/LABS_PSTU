/*Задача 1
Контейнер – вектор
Тип элементов – int

Задание 1: Найти минимальный элемент и добавить его на заданную позицию контейнера
Задание 2: Найти элементы с ключами из заданного диапазона и удалить их из контейнера
Задание 3: Каждый элемент умножить на максимальный элемент контейнера*/



#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;


typedef vector<int>Vec;//определяем тип для работы с вектором
//функция для формирования вектора
Vec make_vector(int n)
{
	Vec v;//пустой вектор
	for (int i = 0; i < n; i++)
	{
		int a = rand() % 101 - 50;
		v.push_back(a);//добавляем а в конец вектора
	}
	cout << endl;
	return v;//возвращаем вектор как результа работы функции
}


//функция для печати вектора
void print_vector(Vec v)
{
	cout << "Наш вектор" << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "   ";
	cout << endl << endl;
}
//основная функция



int srednee(Vec v)
{
	int s = 0;
	//перебор вектора
	for (int i = 0; i < v.size(); i++)
		s += v[i];
	int n = v.size();//количество элементов в векторе
	return s / n;
}



//поиск максимального элемента
int max(Vec v)
{
	int m = v[0],//минимальный элемент
		n = 0;//номер минимального элемента
	for (int i = 0; i < v.size(); i++)//перебор вектора
		if (m < v[i])
		{
			m = v[i];//максимальный элемент
			n = i;//номер максимального
		}

	cout << "Максимальный элемент   " << m << endl << endl;
	return n;
}



//поиск минимального элемента
int min(Vec v)
{
	int m = v[0],//минимальный элемент
		n = 0;//номер минимального элемента
	for (int i = 0; i < v.size(); i++)//перебор вектора
		if (m > v[i])
		{
			m = v[i];//минимальный элемент
			n = i;//номер минимального
		}
	return m;
}


void add_elem(Vec& v, int el, int pos)
{
	//добавляем на место pos элемент el
	v.insert(v.begin() + pos, el);
}


void delete_vector(Vec& v, int key)
{
	bool answer = false;
	int num = 0;
	for (int i = 0; i < v.size(); i++)//перебор вектора
	{
		if (v[i] == key)
		{
			v.erase(v.begin() + num);
			answer = true;
			num--;
			i--;
		}			
		num++;		
	}
	cout << endl;

	if (answer == false)
	{
		cout << "В векторе нет элементов с данным значением" << endl;
	}
	cout << endl;
}



void multiplication(Vec& v)
{
	int m = max(v);
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] * v[m];
}



void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));

	try
	{
		vector<int> v;
		vector<int>::iterator vi = v.begin();


		//формирование вектора
		int n;
		cout << "Количество элементов?   "; 
		cin >> n;
		v = make_vector(n);//создание вектора
		print_vector(v);//печать вектора


		//вычисление минимального элемента
		int el = min(v);
		cout << "Минимальный элемент   ";
		cout << el << endl << endl;

		//позиция для вставки
		cout << "На какую позицию ставим?   ";
		int pos;
		cin >> pos;

		//генерируем ошибку, если позиция для вставки больше размера вектора
		if (pos > v.size())throw 1;
		
		add_elem(v, el, pos);//добавление элемента		
		print_vector(v);



		int key;
		cout << "Элементы с какими значениями удалить?   ";
		cin >> key;
		delete_vector(v, key);//удаляем элементы по значению
		print_vector(v);



		//каждый элемент умножить на максимальное значение вектора
		cout << "Умножаем все элементы на максимальный элемент" << endl << endl;
		multiplication(v);//умножение всех элеменетов на максимальный элемент
		print_vector(v);
	}
	catch (int)//блок обработки ошибок
	{
		cout << "Ошибка!" << endl;
	}
	cout << endl << endl;
}