// Не линейные уравнения итог.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

// Решить уравнение методом Ньютона, методом половинного аргумента и методом итераций


#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;


double func(double x)			// Выполнение исходной функции
{
	return (0.25 * pow(x, 3) + x - 1.2502);
}

double derivative1(double x)		// Выполнение первой производной
{
	return (0.75 * pow(x, 2) + 1);
}

double derivative2(double x)		// Выполнение второй производной
{
	return (1, 5 * x);
}


double Newton_method(double eps, double a = 0.0, double b = 2.0)		// Метод Ньютона
{
	double x = a - 1;
	cout << "Введите неизвестную функции, она лежит в интервале от 0 до 2" << endl;
	cin >> x;
	while ((x < a || x > b) && (func(x) * derivative2(x)) > 0)		// Вводим любую переменную в интервале a,b
	{
		cout << "Ввод неизвестной не попадает в интервал от 0 до 2" << endl;
		cin >> x;
	}
	cout << endl;
	// x1 = функцию поделить на её производную
	double x1;
	x = x - func(x) / derivative1(x);			// Нахождение первого элемента
	x1 = x - func(x) / derivative1(x);		    // Нахождение второго элемента

	while (abs(x1 - x) > eps)					// Нахождение n-го элемента 
	{
		x = x1;
		x1 = x - func(x) / derivative1(x);
		cout << "Шаг итерации" << endl;
		cout << "x1=  " << x1 << endl;
	}
	cout << endl << "Ответ" << endl << x1 << endl;
	return x1;
}



double half_argument(double a = 0.0, double b = 2.0, double eps = 0.00001)		// Метод половинного аргумента
{
	double x = (a + b) / 2;			// Нахожедение первого элемента

	if (abs(b - a) > eps)
	{
		cout << "Шаг итерации" << endl;
		cout << "a = " << a << "\t";
		cout << " b = " << b << endl;
		cout << "x = " << x << endl << endl;
		if ((func(a) * func(x)) <= 0)
		{
			x = half_argument(a, x);
		}
		else
		{
			x = half_argument(x, b);
		}
	}
	
	return  x;
}



//(0.25 * pow(x, 3) + x - 1.2502) = 0 - исходня функция
//(1.2502 / (0.25 * pow(x, 2) + 1)) - выразили x из начального уравнения

double iteration(double eps, double a = 0.0, double b = 2.0)		// Метод итераций
{
	double x = a - 1;
	cout << "Введите неизвестную функции, она лежит в интервале 0 до 2" << endl;
	cin >> x;
	while ((x < a || x > b) && (func(x) * derivative2(x)) > 0)		// Вводим любую переменную в интервале a,b
	{
		cout << "Ввод неизвестной не попадает в интервал от 0 до 2" << endl;
		cin >> x;
	}
	cout << endl;

	double x1 = -1;				// Для перехода к следующей итерации
	int i = 0;					// Для размера количества итераций

	while (abs(x1 - x) > eps && i <= 100000)
	{
		x1 = x;
		x = (1.2502 / (0.25 * pow(x, 2) + 1));
		i += 1;
		cout << i << " Шаг итерации" << endl;
		cout << "x1=  " << x1 << endl << endl;
	}
	cout << i + 1 << " Шаг итерации" << endl;
	cout << "x1=  ";
	return x;
}



int main()
{
	setlocale(LC_ALL, "Russian");
	double x = 0;
	double eps;
	double a = 0;
	double b = 0;
	int work = 0;

	cout << "Введите до какой точности будем работать" << endl;
	cin >> eps;
	while (eps <= 0 || eps >= 1)		// Вводим точность приближения
	{
		if (eps > 1)
		{
			cout << "Ввод превышает допустимые занчения. Введите заного" << endl;
			cin >> eps;
		}
		else
		{
			cout << "Ввод меньше допустимых значений. Введите заного" << endl;
			cin >> eps;
		}
	}
	cout << endl;

	while (work <= 0 || work > 3)
	{
		cout << "Введите каким методом будем решать уравнение: 1 - Метод Ньютона; 2 - Метод Половинного Аргумента; любое другое - Метод Итераций" << endl;
		cin >> work;
	}
	cout << endl << endl << endl;


	if (work == 1)
	{
		cout << "Метод Ньютона" << endl << endl;
		Newton_method(eps);					// Вызов метода Ньютона
		cout << endl << endl;
	}
	else if (work == 2)
	{
		cout << "Метод Половинного Аргумента" << endl << endl;
		cout << half_argument() << endl;			// Вызов метода половинного аргумента
		cout << endl << endl;
	}
	else
	{
		cout << "Метод Итераций" << endl << endl;
		cout << iteration(eps) << endl;				// Вызов метода интераций
		cout << endl << endl;
	}
}