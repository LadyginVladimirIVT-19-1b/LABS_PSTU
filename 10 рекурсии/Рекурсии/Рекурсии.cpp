// Рекурсии.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


//Составить программу вычисления суммы четных факториалов(n - четное) : f(n) = !n + !(n - 2) + !(n - 4) + ... + !(n - 2k), где n = 2k, k∈Z Например : f(10) = !10 + !8 + !6 + …!0

#include <iostream>
#include <cmath>
using namespace std;
int n;

int factorial(int n)		// Вычисляем факториал с заданым числом
{
	int fact = 1;
	for (int i = 1; i <= n; i++)
	{
		fact = fact * i;
	}
	return fact;
}


int sum_factorial(int n)		// Вычисляем сумму четных факториалов
{
	int sum = 0;

	while (n > 0)
	{
		if (n % 2 == 0)
		{
			sum = sum + factorial(n);
			n--;
		}
		else
		{
			n--;
		}
	}
	return sum;
}



int main()
{
	setlocale(LC_ALL, "Russian");

	n = -1;
	int sum = 0;

	while (n < 0)
	{
		cout << "Введите какой факториал ищем" << endl;
		cin >> n;
	}
	cout << endl;

	cout << "Сумма четных факториалов" << endl;
	cout << sum_factorial(n) << endl;
}
