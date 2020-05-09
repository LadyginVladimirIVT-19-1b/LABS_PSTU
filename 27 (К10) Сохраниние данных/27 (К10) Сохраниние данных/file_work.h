#pragma once

#include "Time.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int n;


int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc);//открыть для записи
	if (!stream)return -1;//ошибка открытия файла

	Time p;
	cout << "Количество элементов?   ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> p;//ввод атрибутов объекта из стандартного потока
		stream << p << "\n";//запись объекта в файловый поток
	}

	stream.close();//закрыть поток
	return n;//вернуть количество записанных объектов
}


int print_file(const char* f_name)
{
	fstream stream(f_name, ios::in);//открыть для чтения
	if (!stream)return -1;//ошибка открытия файла

	Time p;
	int i = 0;

	while (stream >> p)
	{
		cout << p << "\n";
		i++;
	}

	stream.close();
	return i;
}


int del_file(const char* f_name, int k)
{
	fstream temp("temp", ios::out);//открыть для записи
	fstream stream(f_name, ios::in);//открыть для чтения
	if (!stream)return -1;//ошибка открытия файла

	int i = 0;
	Time p;
	Time value;
	bool answer = false;

	cout << "Введите значение" << endl;
	cin >> value;
	cout << "Все элементы, которые будут больше заданного значения - удалены" << endl;

	while (stream >> p)//пока нет конца файла выполняем чтение объекта
	{
		//если прочитан признак конца файла,то выход из цикла
		if (stream.eof())break;
		i++;

		if (value > p)
		{
			temp << p;//если элемент объекта меньше значения, то записываем его во вспомогательый файл
		}
	}

	if (answer == false)
	{
		cout << "Все элементы меньше зажанного значения" << endl;
	}

	//закрыть файлы
	stream.close();
	temp.close();
	remove(f_name);//удалить старый файл
	rename("temp", f_name);// переименовать temp
	return i;//количество прочитанных
}

int add_file(const char* f_name, int k, Time pp)
{
	fstream temp("temp", ios::out);//открыть для записи
	fstream stream(f_name, ios::in);//открыть для чтения
	if (!stream)return -1;//ошибка открытия файла

	Time p;
	int i = 0, l = 0;

	while (stream >> p)
	{
		if (stream.eof())break;
		i++;
		if (i == k)
		{
			temp << pp;//записать в temp новую запись
			l++;
		}
		temp << p;
	}

	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;//количество добавленных
}


int add_end(const char* f_name, Time pp)
{
	fstream stream(f_name, ios::app);//открыть для добавления
	if (!stream)return -1;//ошибка открытия файла
	stream << pp; //записать новую запись
	return 1;
}


int change_file(const char* f_name, int k)
{
	fstream temp("temp", ios::out);//открыть для записи
	fstream stream(f_name, ios::in);//открыть для чтения
	if (!stream)return -1;//ошибка открытия файла

	Time p;
	int i = 0, l = 0;
	bool answer = false;
	Time value;

	cout << "Какое значение увеличить на 1 : 30" << endl;
	cin >> value;


	while (stream >> p)
	{
		if (stream.eof())break;
		i++;

		if (p == value)
		{
			cout << "Было  " << endl << p << endl;
			p++;
			cout << "Стало  " << endl << p << endl;
			i++;
			answer = true;
		}
		temp << p;//записать в temp новую запись

		l++;

	}

	if (answer == false)
	{
		cout << "Нет элементов совподающих со значением, которое увеличивали на 1 : 30" << endl;
	}

	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return 0;
}

