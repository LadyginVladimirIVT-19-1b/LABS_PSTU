// Лаба4 (у Ольги Андреевны).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

/*Вариант№5: дан массив(int) с рандомайзером, выводим массив, удаляем все элементы массива кратные 7,
после каждого нечетного элемента добавляетм элемент с 0, выводим что получилось*/

#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
int n;
int mass[100];
int* pmass = new int[n];



void introduce_stattic_mass()		//Ввод массива
{
	int i = 0;
	for (int i = 0; i < n; i++)
	{
		mass[i] = rand() % 101 - 50;
		cout << mass[i] << " ";
	}
}

void change_mass()					//Удаление и добавление элемента
{

	int i = 0;
	int j = 0;
	while (i < n)
	{
		if (mass[i] == 0)														//Пропуск нуля
		{
			i++;
		}
		else if (abs(mass[i]) % 7 == 0)											//Уменьшение массива если элемент кратен 7
		{
			for (int j = i; j < n - 1; j++)									//Смещение массива влево 
			{
				mass[j] = mass[j + 1];
			}
			n--;
		}
		else if (abs(mass[i]) % 2 == 1)
		{
			for (int j = n; j >= i; j--)									//Увеличение массива и меняет элементы местами
			{
				mass[j + 1] = mass[j];
			}
			n++;
			mass[i + 1] = 0;													//Перед нечетными элементами ставится 0		
			i = i + 2;
		}
		else
		{
			i++;
		}
	}
	cout << endl;
}

void bring_out__static_mass()		//Вывод массива
{
	int i = 0;
	for (int i = 0; i < n; i++)
	{
		cout << mass[i] << " ";
	}
	cout << endl;
}


void introduce_dynamic_pmass()
{
	int i = 0;

	//Ввод массива
	for (int i = 0; i < n; i++)
	{
		pmass[i] = rand() % 101 - 50;
		cout << pmass[i] << " ";
	}
}


void change_pmass()
{
	int i = 0;
	int j = 0;
	while (i < n)
	{
		if (pmass[i] == 0)														//Пропуск нуля
		{
			i++;
		}
		else if (pmass[i] % 7 == 0)											//Уменьшение массива если элемент кратен 7
		{
			for (int j = i; j < n - 1; j++)									//Смещение массива влево 
			{
				pmass[j] = pmass[j + 1];
			}
			n--;
		}
		else if (abs(pmass[i]) % 2 == 1)									//После нечетными элементами ставится 0
		{
			for (int j = n; j >= i; j--)									//Увеличение массива и меняет элементы местами
			{
				pmass[j + 1] = pmass[j];
			}
			pmass[i + 1] = 0;													
			i = i + 2;
			n++;
		}
		else
		{
			i++;
		}
	}
	cout << endl;
}
void bring_out__dynamic_pmass()
{
	int i = 0;
	for (int i = 0; i < n; i++)
	{
		cout << pmass[i] << " ";
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, ("Russian"));
	srand(time(NULL));

	int work;

	n = 0;
	cout << "Введите какой массив будет, 0 - Статический, другое динамический." << endl;
	cin >> work;

	while (n <= 0)
	{
		cout << "Введите длину последовательности" << endl;
		cin >> n;
	}
	cout << endl;


	if (work == 0)
	{
		//Статический массви
		int mass[100];

		//Ввод массива
		introduce_stattic_mass();

		//Удаление и добавление элементов
		change_mass();


		//Ввывод массива
		bring_out__static_mass();
		
	}
	else
	{
		//Динамический массив

		//Ввод массива
		introduce_dynamic_pmass();

		// Работа с массивом
		change_pmass();

		//Ввывод массива
		bring_out__dynamic_pmass();
		delete[] pmass;
	}
}