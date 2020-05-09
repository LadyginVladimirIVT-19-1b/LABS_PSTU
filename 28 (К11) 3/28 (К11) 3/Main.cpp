/*Параметризированный класс – Вектор (см. ЛР № 24 (7к))

Задание 1: Найти минимальный элемент и добавить его на заданную позицию контейнера
Задание 2: Найти элементы с ключами из заданного диапазона и удалить их из контейнера
Задание 3: Каждый элемент умножить на максимальный элемент контейнера*/



#include <iostream>
#include <cstdlib>
#include <vector>
#include "Vector.h"
#include "Money.h"
using namespace std;



int main()
{
	setlocale(LC_ALL, "Russian");
	int n;

	cout << "Количество элементов?   ";
	cin >> n;
	Vector<Money>v(n);

	v.Print_vector();//печать вектора

	Money m = v.Min();
	cout << "Добавить его на позицию?   ";
	int p;
	cin >> p;//ввести позицию для добавления
	v.Add_elem(m, p);//добавить элемент в вектор
	v.Print_vector();//печать вектора

	Money key;
	cout << "Введите значение, которое надо удалит?  " << endl;
	cin >> key;

	cout << "Удаляем все элементы, равные данному значению    " << key << endl;
	v.Delete_vector(key);//удаление
	v.Print_vector();//печать

	cout << "Умножаем все элементы на максимальный элемент" << endl;
	v.Multiplication();//деление
	v.Print_vector();

}

