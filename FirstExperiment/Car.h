#ifndef CAR_H
#define CAR_H
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<fstream>
using std::string;
using std::ostream;
using std::ofstream;
using std::ifstream;
struct Date{
	int year;
	int month;
	int day;
};
bool operator<(const Date& date1,const Date& date2);
ostream& operator<<(ostream& out,const Date& date);
ofstream& operator<<(ofstream& fout,const Date& date);
ifstream& operator>>(ifstream& fin,Date& date);
class Car{
	private:
		string band;
		string model;
		string color;
		string license;
		Date producedDate;
	public:
		//store(string fileName);
	friend bool operator<(const Car& car1,const Car& car2);
	friend ostream& operator<<(ostream& out,const Car& car);
	friend ofstream& operator<<(ofstream& fout,const Car& car);
	friend ifstream& operator>>(ifstream& fin,Car& car);

};
#endif
