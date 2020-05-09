/*Задача 5
Параметризированный класс – Вектор
Адаптер контейнера – очередь

Задание 1: Найти минимальный элемент и добавить его на заданную позицию контейнера
Задание 2: Найти элементы с ключами из заданного диапазона и удалить их из контейнера
Задание 3: Каждый элемент умножить на максимальный элемент контейнера*/



#include <iostream>
#include <stack>
#include <vector>
#include "Vector.h"
#include "Time.h"
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int n;

	cout << "Введите количество элементов?   ";
	cin >> n;
	cout << endl;

	Vector<Money>v(n);
	v.Print_deque();


	Money m = v.Min();
	cout << "Добавить его на позицию?   ";
	int pos;
	cin >> pos;//ввести позицию для добавления

	v.Add_to_deque(m, pos);
	v.Print_deque();//печать очереди



	Money key;
	cout << "Введите значение, которое надо удалит?  " << endl;
	cin >> key;

	cout << "Удаляем все элементы, равные данному значению    " << key << endl;
	v.Delete_from_deque(key);
	v.Print_deque();



	cout << "Умножаем все элементы на максимальный элемент" << endl;
	v.Multiplication();
	v.Print_deque();
}