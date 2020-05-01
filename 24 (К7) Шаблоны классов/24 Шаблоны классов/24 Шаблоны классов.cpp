// 24 Шаблоны классов.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

/*1)ВЕКТОР с элементами типа int. Реализовать операции: 
[] – доступа по индексу; 
int() – определение размера вектора;
* вектор – умножение элементов векторов a[i]*b[i]
2)Time для работы с временными интервалами. 
Интервал должен быть представлен в виде двух полей:минуты типа int и секунды типа int. 
При выводе минуты отделяются от секунд двоеточием*/



#include <iostream>
using namespace std;



template <class T> //T - параметр шаблона
class Vector
{
public:
	//конструктор с параметрами: выделяет память под s элементов и заполняет их
	//значением k
	Vector(int s, T k);

	//конструктор с параметрами
	Vector(const Vector<T>& a);

	//деструктор
	~Vector();

	//оператор присваивания
	Vector& operator=(const Vector<T>& a);

	//операция доступа по индексу
	T& operator[](int index);


	//операция, возвращающая длину вектора
	int operator()();
	
	
	//перегруженные операции ввода-вывода
	// <> - указывают на то, что функция является шаблоном
	friend ostream& operator<< <>(ostream& out, const Vector<T>& a);
	friend istream& operator>> <>(istream& in, Vector<T>& a);


private:
	int size;//размер вектора
	T* data;//укзатель на динамический массив значений вектора
};


//конструктор с параметрами
template <class T>
Vector<T>::Vector(int s, T k)
{
	size = s;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = k;
}


//конструктор копирования
template <class T>
Vector<T>::Vector(const Vector& a)
{
	size = a.size;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];

}


//деструктор
template <class T>
Vector<T>::~Vector()
{
	delete[]data;
	data = 0;
}


//операция присваивания
template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& a)
{
	if (this == &a)return *this;
	size = a.size;
	if (data != 0) delete[]data;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
	return *this;
}


//операция доступа по индексу
template <class T>
T& Vector<T>::operator[](int index)
{
	if (index < size) return data[index];
	else cout << endl << "Ошибка! Индекс больше размера" << endl;
}



//операция для получения длины вектора
template <class T>
int Vector<T>::operator ()()
{
	return size;
}



//операции для вывода
template <class T>
ostream& operator<< (ostream& out, const Vector<T>& a)
{
	cout << "Получили вектор" << endl;
	for (int i = 0; i < a.size; ++i)
		out << a.data[i] << "   ";
	return out;
}

//операции для ввода
template <class T>
istream& operator>> (istream& in, Vector<T>& a)
{
	for (int i = 0; i < a.size; ++i)
		in >> a.data[i];
	return in;
}




class Time
{
public:
	int minutes;
	int seconds;
	
	Time()
	{
		minutes = 0;
		seconds = 0;
	};

	Time(int m, int s)
	{
		minutes = m;
		seconds = s;
	}

	Time(const Time& t)
	{
		minutes = t.minutes;
		seconds = t.seconds;
	}

	~Time()
	{ };

	int get_min() {
		return minutes;
	}

	int get_sec()
	{
		return seconds;
	}

	void set_min(int m)
	{
		minutes = m;
	}

	void set_sec(int s)
	{
		seconds = s;
	}

	Time& operator = (const Time&);

	//глобальные функции ввода-вывода
	friend istream& operator >> (istream& in, Time& t);
	friend ostream& operator << (ostream& out, const Time& t);

};


Time& Time::operator = (const Time& t)
{
	//проверка на самоприсваивание
	if (&t == this) return *this;
	minutes = t.minutes;
	seconds = t.seconds;
	return *this;
}


//перегрузка функции-операции ввода
istream& operator>>	(istream& in, Time& t)
{
	cout << "Введите количество минут" << endl;
	in >> t.minutes;
	cout << "Введите количество секунд" << endl;
	in >> t.seconds;
	cout << endl;

	if (t.seconds > 60)
	{
		t.minutes = t.minutes + (t.seconds / 60);
		t.seconds = t.seconds % 60;
	}

	return in;
}


//перегрузка функции-операции вывода
ostream& operator<< (ostream& out, Time& t)
{
	return (out << t.minutes << " : " << t.seconds);
}






int main()
{
	setlocale(LC_ALL, "Russian");
	int work;
	cout << "Введите с чем будем работать:    1 - вектор;  другое - время" << endl;
	cin >> work;
	

	if (work == 1)
	{
		//инициализация, ввод и вывод значений вектора
		Vector<int>A(5, 0);

		cout << "Введите 5 элементов вектора А" << endl;
		cin >> A;
		cout << A << endl;
		cout << endl << endl;


		//инициализация и вывод значений вектора
		Vector <int>B(5, 3);
		cout << "Данные вектора В" << endl;

		cout << B << endl;
		//операция присваивания
		cout << endl << endl;


		//доступ по индексу
		cout << "Данные вектора А по индексу 2" << endl;
		cout << A[2] << endl;
		cout << endl << endl;


		//получение длины вектора
		cout << "Длинна вектора А" << endl;
		cout << "size=  " << A() << endl;
		cout << endl << endl;

		cout << "Умножение элементов векторов A[i]*B[i]" << endl;
		for (int i = 0; i < 5; i++)
		{
			A[i] = A[i] * B[i];
		}
		cout << A << endl;
	}
	
	else
	{
		cout << endl << endl;
		Time a;

		cout << "Введите время" << endl;
		cin >> a;
		cout << endl;

		cout << "Полученое время" << endl << a;
	}
	cout << endl << endl;
}

