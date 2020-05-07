
/*Класс- контейнер ВЕКТОР с элементами типа int.
Реализовать операции:
[] – доступа по индексу;
() – определение размера вектора;
* вектор – умножение элементов векторов a[i]*b[i];
+ n – переход вправо к элементу с номером n .
Вариант реализации: 2 , 3*/


#include "Vector.h"
#include "error.h"
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;



int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	try
	{
		int n;
		cout << "Введите количество элементов" << endl;
		cin >> n;

		Vector a(n, 0);
		Vector b(n, 3);
		int i;
		
		
		cout << "Введите элементы вектора a" << endl;
		cin >> a;
		cout << endl;
		cout << "Вектор a" << endl;
		cout << a << endl << endl;
		cout << "Вектор b заданный через параметр" << endl;
		cout << b << endl << endl;

		cout << "Размер вектора a" << endl;
		cout << a() << endl << endl;

		cout << "Введите номер элемента вектора a" << endl;
		cin >> i;
		cout << "Элемент под номером  " << i << endl;
		cout << a[i] << endl << endl;

		cout << "Введите к какому элементу вектора a перейти" << endl;
		cin >> i;
		cout << "Этот элемент" << endl;
		cout << a + i << endl << endl;


		cout << "Умножение элементов векторов a[i]*b[i]" << endl;	
		for (int i = 0; i < n; i++)
		{
			cout << a[i] * b[i] << "  ";
		}
		cout << endl << endl;
	}
	catch (error e)
	{
		e.what();
	}
	return 0;
}