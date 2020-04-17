// Перед каждым четным числом ставится -1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


// Перед каждым четным элементом массива поставить -1

#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int main()
{
	setlocale(LC_ALL, ("RUSSIAN"));
	srand(time(NULL));
	int n, d;
	cout << "Введите число последовательности" << endl;
	cin >> n;
	int a[100];
	int i = 0;
										
	cout << endl;
	//Ввод массива
	for (int i = 0; i < n; i++)
	{
		a[i]= rand()%101-50;
		cout << a[i] << "   ";
	}
	cout << endl << endl;

	while (i < n)
	{
		if (a[i] == 0)
		{
			i++;
		}
		else if (a[i] % 2 == 0)
		{
			for (int j = n; j >= i; j--)				//смещение массива вправо
			{
				a[j + 1] = a[j];
			}
			d = a[i];									//заменаи нового элементов на -1
			a[i] = -1;
			a[i + 1] = d;
			i = i + 2;
			n++;
		}
		else
		{
			i++;
		}
	}
	cout << endl;
	//Ввывод массива													
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "   ";
	}
	cout << endl << endl;
}
