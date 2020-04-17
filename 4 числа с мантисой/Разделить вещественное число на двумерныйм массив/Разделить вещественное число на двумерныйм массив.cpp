// Разделить вещественное число на двумерныйм массив.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


//разделить числа с мантиссой на двумерный массив


#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int n=0;
    
    while (n <= 0)              //Ввод количества элементов массива
    {
        cout << "Введите количество элементов массива" << endl;
        cin >> n;
    }

    int** pmass = new int* [2];           //создание двумерного массива
    pmass[0] = new int[n];                  //указатели массивов
    pmass[1] = new int[n];

    for (int i = 0; i < n; i++)             //Ввод числе
    {
        cin >> ((int*)pmass[0])[i] >> ((float*)pmass[1])[i];
    }
    cout << endl;
        
    for (int i = 0; i < n; i++)             //вывод чисел
    {
        cout << ((int*)pmass[0])[i] << '\t' << ((float*)pmass[1])[i] << endl;
    }
}

