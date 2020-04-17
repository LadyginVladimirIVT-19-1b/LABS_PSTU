// Ферзи.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


// Задача о 8 ферзях


#include <iostream>
#include<cmath>
using namespace std;

int board[8][8];        // шахматная доска в виде матрицы, хранит сколько королев бьют каждую ячейку

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
    board[i][j] = -1;       // место ферзя
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
    board[i][j] = 0;        // место ферзя
}

bool tryqueen(int i)        // Ставит ферзя на i столбец
{
    bool result = false;    // значение поставило ферзя(true) или нет(false)

    for (int j = 0; j < 8; j++)     // проверка строк
    {
        if (board[i][j] == 0)       // означает, что ячейку никто не бьет 
        {
            setqueen(i, j);
            if (i == 7)         // если истина
            {
                result = true;
            }
            else            // попытка поставить ферзя на следующий столбец
            {
                if (!(result = tryqueen(i + 1)))        // если не получилось поставить королеву, то убираем ферзя с позиции
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


int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Задача о 8 ферзях" << endl;
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
    cout << endl;
}








