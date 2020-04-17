// Лаба20(К1,2).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

/*Задание К1:
заданного числа х на принадлежность диапазону [first;second].
Поле first – положительное целое число, часы, поле second – положительное целое число, минуты. 
Реализовать метод minutes() – приведение времени в минуты.

Задание К2:
Пользовательский класс УРАВНЕНИЕ Коэффициент
А – double Коэффициент 
B – double Коэффициент
C – double*/


#include <iostream>
#include <cmath>
using namespace std;

class time
{
private:
    int hour;
    int second;
public:
    time()
    {
        hour = second = 0;
    }

    time(int h, int s = 0)
    {
        hour = h;
        second = s;
    }

    time(int s)
    {
        hour = 0;
        second = s;
    }

    int translate()
    {
        return (hour * 60 + second / 60);
    }
};



class equation
{
private:

    double a, b, c;

public:

    equation(double a, double b, double c)
    {
        double d;
        double x1, x2;
        d = pow(b, 2) - 4 * a * c;
        cout << "Получился дискриминант" << endl;
        cout << d << endl << endl;

        if (d > 0)
        {
            cout << "Дискриминант больше нуля. Имеем 2 корня" << endl;

            x1 = (-b + sqrt(d)) / (2 * a);
            x2 = (-b - sqrt(d)) / (2 * a);
            cout << "x1=" << x1 << endl;
            cout << "x2=" << x2 << endl;
        }
        else if (d == 0)
        {
            cout << "Дискриминант равен нулю. Имеем 1 корнь" << endl;
            x1 = (-b) / (2 * a);
            cout << x1 << "\n";
        }
        else
        {
            cout << "Дискриминант меньше нуля. Корней нет " << endl;
        }
    }
};



int main()
{
    setlocale(LC_ALL, "Russian");
    int hour;
    int second;
    int work;

    cout << "Введите что будем находить" << endl
        << "1 - нахождение минут;    любая другая цифра - нахождение квадратного уравнения;" << endl;
    cin >> work;
    cout << endl;


    if (work == 1)
    {
        cout << "Ведите количество часов" << endl;
        cin >> hour;
        while (hour < 0)
        {
            cout << "Неправильный ввод, введите заного" << endl;
            cin >> hour;
        }
        cout << endl << endl;

        cout << "Ведите количество секунд" << endl;
        cin >> second;
        while (second < 0)
        {
            cout << "Неправильный ввод, введите заного" << endl;
            cin >> second;
        }
        cout << endl << endl;

        time x(hour, second);
        cout << "Количество минут при имеющихся данных" << endl;
        cout << x.translate() << endl;
    }

    else
    {
        double a, b, c;

        cout << "Ведите коэфициент при x^2" << endl;
        cin >> a;
        cout << endl;

        cout << "Ведите коэфициент при x" << endl;
        cin >> b;
        cout << endl;

        cout << "Ведите свободный член уравнения" << endl;
        cin >> c;
        cout << endl;

        equation x(a, b, c);
    }
    cout << endl << endl;
}

