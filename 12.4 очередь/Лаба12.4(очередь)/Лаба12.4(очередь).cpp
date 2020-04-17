// Лаба12.4(очередь).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


//Тип информационного поля int. Удалить из списка все элементы с четными информационными полями.


#include <iostream>
using namespace std;

struct Node
{
    int data;           //информационное поле
    Node* next;          //адресное поле
};


//создание однонаправленного списка
Node* make_list(int n)
{
    Node* tmp, * p, * r;
    tmp = NULL;
    p = new Node;


    cin >> p->data;                      // создание первого элемента
    tmp = p;
    tmp->next = NULL;

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




void delete_elem(Node** list, bool& answer)         // удаление элемента
{// функция которая принимает вершину top
    Node* tmp = *list;                              // создаем указатель типа Node и приравниваем(ставим) его на вершину стека
    Node* prev = NULL;                              // создаем указатель на предыдуший элемент, с начала он будет пустым


    while (tmp != NULL)                             // пока указатель tmp не пустой, мы будем выполнять код в цикле, если он все же пустой цикл заканчивается
    {
        if (tmp->data % 2 == 0)                     // если Data элемента равна числу, которое нам нужно удалить
        {
            cout << "Удаляем   " << tmp->data << endl;
            if (tmp == *list)                       // если такой указатель равен вершине, то есть элемент, который нам нужно удалить - вершина
            {
                *list = tmp->next;                   // передвигаем вершину на следующий элемент
                free(tmp);                          // очищаем ячейку
                tmp->data = NULL;                   // Далее во избежание ошибок мы обнуляем переменные в удаленной ячейке, так как в некоторых компиляторах удаленная ячейка имеет переменные не NULL значения,
                tmp->next = NULL;                   // а дословно "Чтение памяти невозможно" или числа  "-2738568384" или другие, в зависимости от компилятора.
            }
            else                                    // если элемент последний или находится между двумя другими элементами
            {
                prev->next = tmp->next;             // Проводим связь от предыдущего элемента к следующему
                free(tmp);                          // очищаем ячейку 
                tmp->data = NULL;                   // обнуляем переменные
                tmp->next = NULL;
            }
            answer = true;
        }                                           // если Data элемента НЕ равна числу, которое нам нужно удалить
        prev = tmp;                                 // запоминаем текущую ячейку как предыдущую
        tmp = tmp->next;                            // перемещаем указатель tmp на следующий элемент
    }

}




int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    bool answer = false;

    cout << "Введите количество элементов в очереди" << endl;
    cin >> n;
    while (n <= 0)
    {
        cout << "Неправильный ввод, введите заного" << endl;
        cin >> n;
    }
    cout << endl;


    cout << "Введите данные" << endl;
    Node* list = make_list(n);
    cout << endl;


    cout << "Наша очередь" << endl;
    Print(list, n);
    cout << endl << endl;


    cout << "Удаляем все элементы кратные двум" << endl;
    for (int i = 1; i <= n; i++)
    {
        delete_elem(&list, answer);
    }
    cout << endl << endl;


    if (list == NULL)
    {
        cout << "Элементов в очереди не осталось" << endl << endl;
    }
    else
    {
        if (answer == false)
        {
            cout << "В очереде нет элементов с четным информационным полем" << endl;
            cout << "Наша очередь" << endl;
            Print(list, n);
        }
        else
        {
            cout << "Получившаяся очередь" << endl;
            Print(list, n);
        }
    }


    cout << endl << endl;
}





