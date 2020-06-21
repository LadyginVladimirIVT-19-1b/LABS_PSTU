#pragma once
#include "MyForm.h"
#include <iostream>
using namespace std;

class Operations {
public:
	int numerator1, numerator2, denuminator1, denominator2;

	Operations() {
	};
	int Amount_numerator(int numerator1, int numerator2, int denominator1, int denominator2);
	int Amount_denominator(int denominator1, int denominator2);

	int Difference_numerator(int numerator1, int numerator2, int denominator1, int denominator2);
	int Difference_denominator(int denominator1, int denominator2);

	int Multiplication_numerator(int numerator1, int numerator2);
	int Multiplication_denominator(int denominator1, int denominator2);

	int Division_numerator(int numerator1, int denominator2);
	int Division_denominator(int numerator2, int denominator1);
	double Plain(double numerator1, double denominator1);

	int Exponentiation_numerator(int numerator1, int numerator2, int denominator1, int denominator2);
	int Exponentiation_denominator(int numerator1, int numerator2, int denominator1, int denominator2);

	int Swap_numerator(int denominator1);
	int Swap_denominator(int numerator1);

	int Change_sign_numerator(int numerator1);
	int Change_sign_denominator(int denominator1);

	int Lenght_string(int number);

	~Operations() {};
};


int Operations::Amount_numerator(int numerator1, int numerator2, int denominator1, int denominator2) 
{
	return (numerator1 * denominator2) + (denominator1 * numerator2);
}

int Operations::Amount_denominator(int denominator1, int denominator2) 
{
	return denominator1 * denominator2;
}

int Operations::Difference_numerator(int numerator1, int numerator2, int denominator1, int denominator2) 
{
	return (numerator1 * denominator2) - (denominator1 * numerator2);
}
int Operations::Difference_denominator(int denominator1, int denominator2) 
{
	return denominator1 * denominator2;
}

int Operations::Multiplication_numerator(int numerator1, int numerator2) 
{
	return numerator1 * numerator2;
}

int Operations::Multiplication_denominator(int denominator1, int denominator2) 
{
	return denominator1 * denominator2;
}

int Operations::Division_numerator(int numerator1, int denominator2) 
{
	return numerator1 * denominator2;
}

int Operations::Division_denominator(int numerator2, int denominator1) 
{
	return numerator2 * denominator1;
}

double Operations::Plain(double numerator1, double denominator1) 
{
	return numerator1 / denominator1;
}

int Operations::Exponentiation_numerator(int numerator1, int denominator1, int numerator2, int denominator2)
{
	int tmp= numerator2 / denominator2;
	int elem = numerator1;
	for (int i = 1; i < tmp; i++)
	{
		elem *= numerator1;
	}

	return elem ;
}


int Operations::Exponentiation_denominator(int numerator1,int denuminator1, int numerator2, int denominator2)
{
	int tmp = numerator2 / denominator2;
	int elem = denuminator1;
	for (int i = 1; i < tmp; i++)
	{
		elem *= denuminator1;
	}

	return elem;
}

int Operations::Swap_numerator(int denuminator1)
{
	return denuminator1;
}

int Operations::Swap_denominator(int numerator1)
{
	return numerator1;
}

int Operations::Change_sign_numerator(int numerator1)
{
	return -numerator1;
}

int Operations::Change_sign_denominator(int denominator1)
{
	return denominator1;
}

int Operations::Lenght_string(int number) 
{
	int count = 0;
	while (number > 1) {
		number /= 10;
		count++;
	}
	return count;
}
