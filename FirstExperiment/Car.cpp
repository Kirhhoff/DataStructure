#include"Car.h"
#include<iomanip>
#include"global.h"
using namespace std;

string carDatabase="CarDatabase.txt";
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
	char monthPrefix=date.month<10?'0':'\0';
	char dayPrefix=date.day<10?'0':'\0';
	out<<date.year<<"-"<<monthPrefix<<date.month<<"-"<<dayPrefix<<date.day;
	return out;
}

ofstream& operator<<(ofstream& fout,const Date& date){
	char monthPrefix=date.month<10?'0':'\0';
	char dayPrefix=date.day<10?'0':'\0';
	fout<<date.year<<"-"<<monthPrefix<<date.month<<"-"<<dayPrefix<<date.day;
	return fout;
}

ifstream& operator>>(ifstream& fin,Date& date){
	fin>>date.year;
	fin.get();
	fin>>date.month;
	fin.get();
	fin>>date.day;
	return fin;
}

ostream& operator<<(ostream& out,const Car& car){
	out<<right;
	out	<<setw(BAND_WIDTH)<<car.band
		<<setw(MODEL_WIDTH)<<car.model
		<<setw(COLOR_WIDTH)<<car.color
		<<setw(LICENSE_WIDTH)<<car.license
		<<setw(DATE_WIDTH)<<car.producedDate
		<<endl;
	return out;
}
ofstream& operator<<(ofstream& fout,const Car& car){
	fout<<right;
	fout<<setw(BAND_WIDTH)<<car.band
		<<setw(MODEL_WIDTH)<<car.model
		<<setw(COLOR_WIDTH)<<car.color
		<<setw(LICENSE_WIDTH)<<car.license
		<<setw(DATE_WIDTH)<<car.producedDate
		<<endl;
	return fout;
}

ifstream& operator>>(ifstream& fin,Car& car){ 
	fin>>car.band>>car.model>>car.color>>car.license;
	fin>>car.producedDate;
	return fin;
}
