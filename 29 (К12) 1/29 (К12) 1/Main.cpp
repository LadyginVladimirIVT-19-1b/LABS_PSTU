/*Задача 1
1 Контейнер - set
2 Тип элементов - float

1) Найти минимальный элемент и добавить его на заданную позицию контейнера
2) Найти элементы большие среднего арифметического и удалить их из контейнера
3) Каждый элемент домножить на максимальный элемент контейнера*/




#include <iostream>
#include <iterator>  
#include <set>        
using namespace std;



typedef set<float, less<float>>tset;//определение типа tset
tset::iterator it;//итератор


//функция для формирования контейнера
tset make_set(int n)
{
	tset m;
	float a;
	for (int i = 0; i < n; i++)
	{
		cout << "Введите данные элемента" << endl;
		cin >> a;
		
		m.insert(a);// добавляем элемент в контейнер
	}
	cout << endl;
	return m;//возвращаем получившийся контейнер
}

// вывод контейнера
void print_set(tset m)
{
	cout << "Наш set контейнер" << endl;
	for (it = m.begin(); it != m.end(); ++it)
		cout << *it << "   ";
	cout << endl << endl;
}

//среднее арифметическое значение
int srednee(tset m)
{
	float sum = 0.0;
	//перебор всех элементов
	for (it = m.begin(); it != m.end(); ++it)
		sum += *it;
	int n = m.size();//количество элементов
	return sum / n;
}

//умножение всех элементов контейнера на максимальный элемент 
void multiplication(tset& m)
{
	float max;
	max = *m.rbegin();
	cout << "Максимальный элемент: " << max << endl << endl;


	float tmp;
	cout << "Умножаем элементы на максимальный" << endl;
	for (it = m.begin(); it != m.end(); ++it)
	{
		tmp = *it * max;
		cout << tmp << "   ";
	}
}

//удаление улементов превышающих среднее арифметическое значение
void delete_set(tset& m, float middle)
{
	if (*m.rbegin() > middle)
	{
		m.erase(*m.rbegin());//удаление элемента	
		delete_set(m, middle);
	}	
}


int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите количество элементов" << endl;
	cin >> n;
	cout << endl;


	tset m = make_set(n);
	print_set(m);


	float min;
	min = *m.begin();
	cout << "Минимальный элемент: " << min << endl ;
	cout << "Добавлять минимальный элемент нет смысла" << endl << endl;


	cout << "Среднее арифметическое значение равно" << endl;
	float middle = srednee(m);
	cout << middle << endl;

	cout << "Удаляем все элементы больше среднего арифметического значения" << endl;
	delete_set(m, middle);
	print_set(m);


	multiplication(m);
	cout << endl << endl;
}





