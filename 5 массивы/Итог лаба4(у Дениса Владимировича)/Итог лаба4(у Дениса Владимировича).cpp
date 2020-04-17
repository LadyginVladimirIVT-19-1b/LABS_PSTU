// Итог лаба4(у Дениса Владимировича).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


/* Задание:
1)Ввести одномерный массив, удалить элемент выбранный пользователем. 
2)Ввести двумерный массив, в начале добавить еще одну строку.*/

#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;


void introduce_mass1(int mass[], int n) //Ввод массива
{
    int i = -1;
    
    for (int i = 0; i < n; i++)
    {
        mass[i] = rand() % 101 - 50;
        cout << mass[i] << "\t";
    }
    cout << endl << endl;
}

void delete_elem(int mass[], int n, int num)     //Удаление элемента
{
    int i = -1;
    while (i < num)                                
    {
        int j = 0;
        i = num;
        for (int j = i; j < n - 1; j++)			//Смещение массива влево 
        {
            mass[j] = mass[j + 1];
        }
    }
    cout << endl;
}

void bring_out_mass1(int mass[], int n)       //Вывод массива
{
    int i = -1;
    for (int i = 0; i < n; i++)
    {
        cout << mass[i] << "\t";
    }
    cout << endl << endl;
}

void introduce_mass2(int* mass[], int n, int m)      //Ввод двумерного массива
{
    int i = 0;
    int j = 0;
    cout << "Наш массив" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mass[i][j] = rand() % 101 - 50;
            cout << mass[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void add_line(int* mass1[], int* mass[], int n, int m)
{
    int i = 0;
    int j = 0;
    cout << "Добавили строку к данному массиву" << endl;
    for (int i = 0; i < 1; i++)
    {
        mass1[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            mass1[i][j] = rand() % 101 - 50;
            cout << mass1[i][j] << "\t";
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mass[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    int work;
    cout << "Введите с каким масиивом будем работать, 0 - одномерный, другое двумерный" << endl;
    cin >> work;
    cout << endl;

    if (work == 0)
    {
        int n = 0;
        int num = -1;
        int i = -1;

        while (n <= 0)                                     //Ввод количество элементов массвива
        {
            cout << "Введите количество элементов массвива" << endl;
            cin >> n;
        }
        cout << endl;

        //Ввод массива
        int* mass = new int[n];
        introduce_mass1(mass, n);


        while (num < 0 || num >= n)                     //Ввод элемента, который удалим
        {
            cout << "Введите элемент массвива, который хотите удалить(начало с 0)" << endl;
            cin >> num;
        }
        cout << endl;

        //Удаление элемента
        delete_elem(mass, n, num);                                
        n--;

        //Вывод массива
        bring_out_mass1(mass, n);

        delete[] mass;
    }


    else
    {
        int n = 0;
        int m = 0;
      

        while (n <= 0)				//Обьявление количества строк
        {
            cout << "Введите количество строк массива" << endl;
            cin >> n;
        }
        cout << endl;

        while (m <= 0)				//Обьявление количства столбцов
        {
            cout << "Введите количество столбцов массива" << endl;
            cin >> m;
        }
        cout << endl;


        //обьявление двумерного массива
        int** mass = new int* [n];
        for (int i = 0; i < n; i++)
        {
            mass[i] = new int[m];
        }
        //Ввод двумерного массива
        introduce_mass2(mass, n, m);

        //Добовление строки в массив
        int** mass1 = new int* [n];
        add_line(mass1, mass, n, m);
        delete[] mass;
        delete[] mass1;
    }
}
