#include "Vector.h"
#include "error.h"
#include <iostream>
#include <ctime>
using namespace std;


Vector::Vector(int s, int k)
{
	if (s > MAX_SIZE)
	{
		throw error("Длина вектора больше максимального размера\n");
	}
	if (s < 0)
	{
		throw error("Длина вектора меньше нуля\n");
	}
	
	size = s;
	beg = new int[s];

	for (int i = 0; i < size; i++)
		beg[i] = k;
}


Vector::Vector(const Vector& v)
{
	size = v.size;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = v.beg[i];
}


Vector::~Vector()
{
	if (beg != 0) delete[]beg;
}


Vector::Vector(int s, int* mas)
{
	if (s > MAX_SIZE) throw error("Длина вектора больше максимального размера\n");
	size = s;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = mas[i];
}


const Vector& Vector::operator = (const Vector& v)
{
	if (this == &v)return *this;
	size = v.size;
	if (beg != 0) delete[]beg;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = v.beg[i];
	return*this;
}


ostream& operator << (ostream& out, const Vector& v)
{
	if (v.size == 0) out << "Empty\n";
	else
	{
		for (int i = 0; i < v.size; i++)
			out << v.beg[i] << "   ";
		out << endl;
	}
	return out;
}


istream& operator >> (istream& in, Vector& v)
{
	for (int i = 0; i < v.size; i++)
	{
		cout << ">";
		in >> v.beg[i];
	}
	return in;
}


int Vector::operator [] (int i)
{
	if (i<size)	return beg[i];
	if (i < 0) throw error("index < 0");
	else if (i >= size) throw error("index > size");
}


int Vector::operator ()()
{
	return size;
}

int Vector::operator + (int n1)
{
	if (n1 < 0) throw error("index < 0");
	if (n1 >= size) throw error("index > size");
	return beg[n1];
}








