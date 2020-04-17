﻿// Лаба12.3(стек).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


//Тип информационного поля int. Удалить из списка все элементы с четными информационными полями.

#include <iostream>
using namespace std;

struct Node
{
    int data;                                     // информационное поле     
    Node* next;                                   // указатель на следующий элемент
};


void push(Node** top)                           // добавление одного элемента
{// принимаем указатль на вершину стека 
    Node* tmp;                                 
    tmp = new Node();                           
    int temp;
    cin >> temp;

    tmp->data = temp;                           // Записываем необходимое число  в data элемента
    if (top == NULL)                            // Если вершины нет, то наш стек пустой
    {                               
        *top = tmp;                             // вершиной стека будет новый элемент
    }
    else                                        // если стек не пустой
    {
        tmp->next = *top;                       // Проводим связь от нового элемента, к вершине
        *top = tmp;                             // Обозначаем, что вершиной теперь является новый элемент
    }
}




void print(Node* top)                           // вывод стека
{// принимает указатель на вершину стека		
    Node* tmp = top;                            // устанавливаем tmp на вершину
    while (tmp != NULL)                         // пока tmp не пустой 
    {
        cout << tmp->data << "\t";;             // выводим на экран данные ячейки стека
        tmp = tmp->next;                        // после того как вывели передвигаем q на следующий элемент(ячейку)
    }
    cout << endl << endl;
}




void delete_elem(Node** top, bool& answer)      // удаление элемента
{// функция которая принимает вершину top
    Node* tmp = *top;                           // создаем указатель типа Node и приравниваем(ставим) его на вершину стека
    Node* prev = NULL;                          // создаем указатель на предыдуший элемент, с начала он будет пустым
   

    while (tmp != NULL)                         // пока указатель tmp не пустой, мы будем выполнять код в цикле, если он все же пустой цикл заканчивается
    {
        if (tmp->data % 2 == 0)                 // если Data элемента равна числу, которое нам нужно удалить
        {
            cout << "Удаляем   " << tmp->data << endl;
            if (tmp == *top)                    // если такой указатель равен вершине, то есть элемент, который нам нужно удалить - вершина
            {
                *top = tmp->next;               // передвигаем вершину на следующий элемент
                free(tmp);                      // очищаем ячейку
                tmp->data = NULL;               // Далее во избежание ошибок мы обнуляем переменные в удаленной ячейке, так как в некоторых компиляторах удаленная ячейка имеет переменные не NULL значения,
                tmp->next = NULL;               // а дословно "Чтение памяти невозможно" или числа  "-2738568384" или другие, в зависимости от компилятора.
            }
            else                                // если элемент последний или находится между двумя другими элементами
            {
                prev->next = tmp->next;         // Проводим связь от предыдущего элемента к следующему
                free(tmp);                      // очищаем ячейку 
                tmp->data = NULL;               // обнуляем переменные
                tmp->next = NULL;
            }
            answer = true;           
        }                                       // если Data элемента НЕ равна числу, которое нам нужно удалить
        prev = tmp;                             // запоминаем текущую ячейку как предыдущую
        tmp = tmp->next;                        // перемещаем указатель tmp на следующий элемент
    }
    
}





void main()
{
    setlocale(LC_ALL, "Russian");
    Node* top = NULL;                               // под создание структуры
    int n;                                          // количество элементов
    bool answer = false;                            // для понимания удалили ли элемент

    cout << "Введите количество элементов в списке" << endl;
    cin >> n;
    while (n < 1)
    {
        cout << "Неправильный ввод, введите заного" << endl;
        cin >> n;
    }

    cout << endl << "Введите данные" << endl;;
    for (int i = 0; i < n; i++)
    {
        push(&top);
    }
    cout << endl << "Наш стек" << endl;
    print(top);


    cout << "Удаляем все элементы кратные двум" << endl;
    for (int i = 1; i <= n; i++)
    {
        delete_elem(&top, answer);
    }
    cout << endl << endl;
    
    if(top == NULL)
    {
        cout << "Элементов в стеке не осталось" << endl << endl;
    }
    else
    {
        if (answer == false)
        {
            cout << "В стеке нет элементов с четным информационным полем" << endl;
            cout << "Наш стек" << endl;
            print(top);
        }
        else
        {
            cout << "Получившийся стек" << endl;
            print(top);
        }
    }
}