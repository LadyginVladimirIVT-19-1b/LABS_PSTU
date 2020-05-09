#pragma once



#include <iostream>
#include <fstream> 
#include <string>
using namespace std;


class Time
{
public:
	Time();
	Time(int, int);
	Time(const Time&);
	~Time();


	//перегрузка логических операций
	friend bool operator == (const Time& temp1, const Time& temp2);
	friend bool operator != (const Time& temp1, const Time& temp2);
	friend bool operator > (const Time& temp1, const Time& temp2);

	Time& operator ++ ();
	Time operator ++ (int);


	Time operator = (const Time&);
	friend ostream& operator << (ostream& out, const Time& p);
	friend istream& operator >> (istream& in, Time& p);

	friend fstream& operator >> (fstream& fin, Time& p);
	friend fstream& operator << (fstream& fout, const Time& p);


private:
	int minutes;
	int seconds;
};




