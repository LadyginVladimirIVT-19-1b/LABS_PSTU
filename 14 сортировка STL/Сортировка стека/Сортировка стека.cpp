// Сортировка стека.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


//Отсоортировать стек с помощью STL контейнера

#include <iostream>
#include <ctime>
#include <stack>
using namespace std;


// возвращает отсортированный стек
stack<int> sortStack(stack<int>& dig)
{
    bool answer = false;
    stack <int> tmpStack;           // обьявление временного стека

    while (!dig.empty())            //проход по всем элементам
    {
        int tmp = dig.top();        // выскакиваем элемент
        dig.pop();                  // удаляем элемент

       // пока временный стек не пуст(empty) и верх стека больше чем временный стек
       while (!tmpStack.empty() && tmpStack.top() > tmp)
       {
            // Заканчивает временный стек, переход в стек ввода
            dig.push(tmpStack.top());
            tmpStack.pop();
            answer = true;
       }

        // вставляем элемент во временную шкалу
        tmpStack.push(tmp);
    }
    if(answer==false)
    {
        cout << "Все элементы стека одинаковые" << endl;
    }
    cout << endl;
    return tmpStack;
}



int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    stack<int> dig;     //обьявление стека
    int n = 0;          // для количества элементов
    int k = 0;          // для присвоения рандомного числа в стек
   

    cout << "Введите количество элементов" << endl;
    cin >> n;
    while (n < 1)
    {
        cout << "Неправильный ввод, введите заного" << endl;
        cin >> n;
    }
    cout << endl;

    cout << "Наш стек" << endl;                 // Ввод стека
    cout << "Введите данные" << endl;
    for (int i = n; i > 0; i--) 
    {
        int tmp;
        cin >> tmp;
        dig.push(tmp);        //добавление элемента
        
    }
    cout << endl << endl;

    cout << "Сортируем стек" << endl;
    stack<int> tmpStack = sortStack(dig);       // обьявление временного стека для того чтобы можно было сортировать
    
    cout << "Получившийся стек" << endl;
    while (!tmpStack.empty())                   // выводит отсортированный стек
    {
        cout << tmpStack.top() << "   ";
        tmpStack.pop();
    }
    cout << endl << endl;
}