#include"Car.h"
#include<iomanip>
#include"global.h"
#include"Hash.h"
using namespace std;

bool operator==(const Date& date1,const Date& date2){return date1.year==date2.year&&date1.month==date2.month&&date1.day==date2.day;}
bool operator<(const Date& date1,const Date& date2){
	if(date1.year!=date2.year)
		return date1.year<date2.year;
	if(date1.month!=date2.month)
		return date1.month<date2.month;
	return date1.day<date2.day;
}

bool operator<(const Car& car1,const Car& car2){
	return car1.producedDate<car2.producedDate;
}

ostream& operator<<(ostream& out,const Date& date){
	out<<date.year<<" ";
	if(date.month<10)
		out<<0;
	out<<date.month<<" ";
	if(date.day<10)
		out<<0;
	out<<date.day;
	return out;
}

ofstream& operator<<(ofstream& fout,const Date& date){
	fout<<date.year<<" "<<date.month<<" "<<date.day;
	return fout;
}
istream& operator>>(istream& in,Date& date){
	in>>date.year>>date.month>>date.day;
	return in;
}
ifstream& operator>>(ifstream& fin,Date& date){
	fin>>date.year>>date.month>>date.day;
	return fin;
}

ostream& operator<<(ostream& out,const Car& car){
	out<<right;
	out	<<setw(BAND_WIDTH)<<car.band
		<<setw(MODEL_WIDTH)<<car.model
		<<setw(COLOR_WIDTH)<<car.color
		<<setw(LICENSE_WIDTH)<<car.license
		<<setw(DATE_WIDTH)<<car.producedDate;
	return out;
}
ofstream& operator<<(ofstream& fout,const Car& car){
	fout<<right;
	fout<<setw(BAND_WIDTH)<<car.band
		<<setw(MODEL_WIDTH)<<car.model
		<<setw(COLOR_WIDTH)<<car.color
		<<setw(LICENSE_WIDTH)<<car.license
		<<setw(DATE_WIDTH)<<car.producedDate;
	return fout;
}
istream& operator>>(istream& in,Car& car){
	in>>car.band>>car.model>>car.color>>car.license>>car.producedDate;
}
ifstream& operator>>(ifstream& fin,Car& car){ 
	fin>>car.band>>car.model>>car.color>>car.license>>car.producedDate;
	return fin;
}
Car::Car(){}
Car::Car(string _band,string _model,string _color,string _license,Date _producedDate):
	band(_band),model(_model),color(_color),license(_license),producedDate(_producedDate){}
