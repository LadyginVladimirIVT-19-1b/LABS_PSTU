// Лаба 16(поиски).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


// Поиск 2 методами: интерполяции, Буера Мура.


#include <iostream>
# include <limits.h>
# include <string.h>
#include <Windows.h>
# include <stdio.h>
using namespace std;
# define NO_OF_CHARS 256

const int n = 10;


////////////////////////////////////////////////////////////////////
//интерполяционный поиск
int InterpolSearch(int mass[], int key)
{
	int mid;
	int left = 0;
	int right = n - 1;

	while (mass[left] <= key && mass[right] >= key)
	{
		mid = left + ((key - mass[left]) * (right - left)) / (mass[right] - mass[left]);
		if (mass[mid] < key)
		{
			left = mid + 1;
		}
		else if (mass[mid] > key)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}

	if (mass[left] == key)
	{
		return left;
	}
	else
	{
		return -1;
	}
}


////////////////////////////////////////////////////////////////////
// Функция полезности для получения максимум двух целых чисел
int max_elem(int a, int b)
{
	return (a > b) ? a : b;
}

// Функция предварительной обработки для плохого характера Бойера Мура
void badCharHeuristic(char* key, int size, int badchar[NO_OF_CHARS])
{
	int i;

	// Инициализировать все вхождения как -1
	for (i = 0; i < NO_OF_CHARS; i++)
		badchar[i] = -1;

	// Заполните фактическое значение последнего появления символа
	for (i = 0; i < size; i++)
		badchar[(int)key[i]] = i;
}

void search(char* txt, char* key)
{
	int m = strlen(key);
	int n = strlen(txt);
	bool answer = false;

	int badchar[NO_OF_CHARS];

	badCharHeuristic(key, m, badchar);

	int s = 0; // s - смещение шаблона относительно текста
	while (s <= (n - m))
	{
		int j = m - 1;

		while (j >= 0 && key[j] == txt[s + j])
			j--;

		if (j < 0)
		{
			cout << "\nсовпадение происходит на  " << s;

			s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
			answer = true;
		}

		else
			s += max_elem(1, j - badchar[txt[s + j]]);
	}

	if (answer == false)
	{
		cout << "В данном тексте нет совпадений с этими символами" << endl;
	}
	cout << endl << endl;
}


////////////////////////////////////////////////////////////////////


void main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int work;
	cout << "Выберите с каким поискам будет работа" << endl;
	cout << "1 - интерполяция;   2 - алгоритм Бойера — Мура" << endl;
	cin >> work;

	while (work < 1 || work>2)
	{
		cout << "Неправильный ввод. Введите 1 или 2" << endl;
		cin >> work;
	}

	if (work == 1)
	{
		cout << "Вы выбрали интерполяционный поиск" << endl;

		int i, key;

		int mass[n] = { 2,5,11,19,23,29,30,35,46,49 };

		cout << "Наш массив: " << endl;
		for (i = 0; i < n; i++)
		{
			cout << mass[i] << "   "; //вывод массива
		}
		cout << endl;

		cout << "Введите, что нужно найти" << endl;
		cin >> key; //ввод ключа
		cout << endl;

		if (InterpolSearch(mass, key) == -1)
		{
			cout << "\nЭлемент не найден";
		}
		else
		{
			cout << "\nНомер данного элемента: " << InterpolSearch(mass, key) + 1;
		}
		cout << endl;
	}
	else
	{
		cout << "Вы выбрали алгоритм Бойера — Мура" << endl;
		
		char txt[] = "FGHTEOPSTERDSAF";
		cout << "Наш текст состоит из такого набора символов" << endl << txt << endl << endl;

		char key[] = "TER";
		cout << "То, что мы ищим будет" << endl << key << endl << endl;

		search(txt, key);
	}
}
	
