// Лаба12.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//Тип информационного поля char*. Добавить в список элемент после элемента с заданным информационным полем.


#include <iostream>
#include <ctime>
#include <string.h>
#include <Windows.h>
using namespace std;


struct Node
{
    char data[20];           //информационное поле
    Node* next;              //адресное поле
};


//создание однонаправленного списка
Node* make_list(int n)
{
    Node* tmp, * p, * r;
    tmp = NULL;
    p = new Node;
    cin >> p->data;                      // создание первого элемента
    tmp = p;
    if (n > 1)
    {
        for (int i = 2; i <= n; i++)     // создание n-го количества элементов    
        {
            r = new Node;
            cin >> r->data;
            p->next = r;
            r->next = NULL;
            p = r;
        }
    }

    cout << endl;
    return tmp;
}


void Print(Node* list, int n)        // вывод списка  
{
    Node* p = list;                  // начало списка
    if (n < 2)
    {
        cout << p->data;
    }
    else
    {
        while (p != NULL)           // пока не закончится список выводим элементы
        {
            cout << p->data << "   ";
            p = p->next;
        }
    }
    cout << endl << endl;
}

Node* add_point(Node* list, int n)       // вставка элемента
//добавление элемента с номером k
{
    Node* p = list;                     //встали на первый элемент
    Node* tmp = new Node();             //создали новый элемент
    char k[20];
    int num = -1;
    bool answer = false;

    cout << "Введите после какого элемента добавить новый" << endl;
    cin >> k;

    for (int i = 0; i < n && p != 0; i++)
    {
        num++;
        if (strcmp(p->data, k) == 0)
        {
            i = n + 1;
            answer = true;
        }
        else
        {
            p = p->next;
        }
    }

    p = list;
    if (answer == true)
    {
        cout << "Введите данные нового элемента" << endl;
        cin >> tmp->data;

        for (int i = 0; i < num && p->next != 0; i++)
        {
            p = p->next;
        }                                   //проходим по списку до k элемента 

        if (p != 0)                         //если k-й элемент существует
        {
            tmp->next = p->next;             //связываем tmp и k-й элемент
            p->next = tmp;                  //связываем (k-1)элемент и tmp
        }

    }
    else
    {
        cout << "Такой буквы нет" << endl;
    }
    return list;
}



int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));

    int n;


    cout << "Введите количество элементов списка" << endl;
    cin >> n;
    while (n <= 0)
    {
        cout << "Неправильный ввод, введите заного" << endl;
        cin >> n;
    }
    cout << endl;

    cout << "Введите данные" << endl;
    Node* list = make_list(n);

    cout << "Наш список" << endl;
    Print(list, n);
    cout << endl << endl;




    add_point(list, n);
    cout << endl << endl;
    cout << "Получившийся список" << endl;
    Print(list, n);
    cout << endl << endl;
}