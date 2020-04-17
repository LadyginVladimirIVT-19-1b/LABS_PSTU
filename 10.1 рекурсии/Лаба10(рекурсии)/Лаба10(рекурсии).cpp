// Лаба10(рекурсии).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

/*
1)Числа фибоначи
2)Задача о 8 ферзях
3)Ханойская башня
*/

#include <iostream>
#include<cmath>
using namespace std;

int board[8][8];        // шахматная доска в виде матрицы, хранит сколько королев бьют каждую ячейку

// Нахождение числа фибоначи 
int fib(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
   
    return fib(n - 1) + fib(n - 2);
}


///////////////////////////////////////////////////////////////
// Задача о 8 ферзях
void setqueen(int i, int j)     // ставит королеву, смотрит какие ячейки бьет королева
{
    for (int x = 0; x < 8; x++)
    {
        board[x][j]++;      // работаем по горизонтали
        board[i][x]++;      // работаем по вертикали

        int foo;            // диагональ
        foo = j - i + x;
        if (foo >= 0 && foo < 8)
        {
            board[x][foo]++;        // работаем по диагонали
        }
        foo = j + i - x;
        if (foo >= 0 && foo < 8)
        {
            board[x][foo]++;        // работаем по диагонали
        }
    }
    board[i][j] = -1;       // место ферзь
}

void resetqueen(int i, int j)       // убирает ферзя с доски
{
    for (int x = 0; x < 8; x++)
    {
        board[x][j]--;      // работаем по горизонтали
        board[i][x]--;      // работаем по вертикали

        int foo;            // диагональ
        foo = j - i + x;
        if (foo >= 0 && foo < 8)
        {
            board[x][foo]--;         // работаем по диагонали
        }
        foo = j + i - x;
        if (foo >= 1 && foo <= 8)
        {
            board[x][foo]--;         // работаем по диагонали
        }
    }
    board[i][j] = 0;        // место ферзь
}


bool tryqueen(int i)        // Ставит ферзя на i столбец
{
    bool result = false;    // значение поставило ферзя(true) или нет(false)

    for (int j = 0; j < 8; j++)     // проверка строк
    {
        if (board[i][j] == 0)       // очначает, что ячейку никто не бьет
        {
            setqueen(i, j);
            if (i == 7)         // если истина
            {
                result = true;
            }
            else            // попытка поставить ферзя на следующий столбец
            {
                if (!(result = tryqueen(i + 1)))        // усли не получилось поставить королеву, то убераем ферзя с позиции
                {
                    resetqueen(i, j);       // убирает королеву с (i , j)
                }
            }
        }
        if (result == true)     // если удалось поставить ферзя на какую-то из ячеек, то выход из цикла
        {
            break;
        }
    }
    return result;
}
//////////////////////////////////////////////////////////////////////////////


// Задача о Ханойских башнях
void hanoi_towers(int quantity, int from, int to, int buf_peg)   // quantity-число колец,
                                                                 // from-начальное положение колец(1-3),
                                                                 // to-конечное положение колец(1-3)
{                                                                // buf_peg - промежуточный колышек(1-3)
    if (quantity != 0)
    {
        hanoi_towers(quantity - 1, from, buf_peg, to);

        cout << from << " -> " << to << endl;

        hanoi_towers(quantity - 1, buf_peg, to, from);
    }
}





int main()
{
    setlocale(LC_ALL, "Russian");
    int work = 0;
   
    while ((work <= 0) || (work > 3))
    {
        cout << "Введите какое задание выполнием: 1 - Число Фибоначи; 2 - Задача о 8 ферзях; 3 - Ханойская башня  " << endl;
        cin >> work;
    }
    cout << endl;

    //Число фибоначи
    if (work == 1)  
    {
        int n = 0;
        while (n <= 0)
        {
            cout << "Введите число которое хотим найти" << endl;
            cin >> n;
        }
        cout << endl;

        cout << "Число фибоначи" << endl;
        cout << fib(n) << endl;
    }

    // Задача о 8 ферзях
    else if (work == 2)
    {
        for (int i = 0; i < 8; i++)         // проход по строкам
        {
            for (int j = 0; j < 8; j++)     // проход по столбцам
            {
                board[i][j] = 0;            // отчиска доски
            }
        }
        tryqueen(0);
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (board[i][j] == -1)      // вывод королевы
                {
                    cout << "Ф" << " ";
                }
                else        //вывод пустой клетки
                {
                    cout << "." << " ";
                }
            }
            cout << endl;
        }
    }

    // Ханойская башня
    else
    {
        int start_peg, destination_peg, buffer_peg, plate_quantity;

        cout << "Номер первого столбика:" << endl;
        cin >> start_peg;
        cout << endl;

        cout << "Номер конечного столбика:" << endl;
        cin >> destination_peg;
        cout << endl;

        cout << "Номер промежуточного столбика:" << endl;
        cin >> buffer_peg;
        cout << endl;

        cout << "Количество дисков:" << endl;
        cin >> plate_quantity;
        cout << endl;

        hanoi_towers(plate_quantity, start_peg, destination_peg, buffer_peg);
    }
}
