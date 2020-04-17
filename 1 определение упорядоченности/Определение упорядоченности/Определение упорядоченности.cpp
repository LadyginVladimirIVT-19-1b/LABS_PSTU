// Определение упорядоченности.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


// Определить упорядочен ли массив


#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");


    int n, d;
    bool ordered = true;

    cout << "Введите длинну массива : \n";
    cin >> n;
    int a[100];
    d = 0;
    cout << endl;
                                                                  //srand(time(NULL));
//Ввод массива
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        /*a[i]=rand()/101-1;
        cout<< a[i] << " ";*/
    }
    while ((d < n - 1) && (ordered == true))                      //Проверка упорядоченности с помощью сравнение двух элементов
    {
        if (a[d] >= a[d + 1])
        {
            ordered = false;
            cout << "Элементы не упорядочены по возрастанию! \n";
        }
        d++;
    }
    if (ordered == true)
    {
        cout << "Элементы упорядочены по возрастанию! \n";
    }
}


