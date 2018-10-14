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
using std::istream;
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
	    string hash;
		string band;
		string model;
		string color;
		string license;
		Date producedDate;
	public:
		Car();
		Car(string _band,string _model,string _color,string _license,Date _producedDate);
	public:
		string getBand(){return band;}
		string getHash(){return hash;}
		void setBand(string& _band){band=_band;}
		void setModel(string& _model){model=_model;}
		void setColor(string& _color){color=_color;}
		void setLicense(string& _license){license=_license;}
	friend bool operator<(const Car& car1,const Car& car2);
	friend ostream& operator<<(ostream& out,const Car& car);
	friend ofstream& operator<<(ofstream& fout,const Car& car);
	friend istream& operator>>(istream& in,Car& car);
	friend ifstream& operator>>(ifstream& fin,Car& car);

};
#endif
