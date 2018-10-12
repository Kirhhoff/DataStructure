
#include<stdlib.h>
#include<stdio.h>
#include<string>
using std::string;
struct Date{
	int year;
	int month;
	int day;
};
bool operator<(const Date& date1,const Date& date2);
class Car{
	private:
		string band;
		string model;
		string color;
		string license;
		Date producedDate;
	public:
		store(string fileName);		
		

};

