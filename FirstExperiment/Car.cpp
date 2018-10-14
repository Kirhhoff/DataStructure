#include"Car.h"
#include<iomanip>
#include"global.h"
#include"Hash.h"
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
istream& operator>>(istream& in,Date& date){
	in>>date.year>>date.month>>date.day;
	return in;
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
	out	<<setw(HASH_WIDTH)<<car.hash
		<<setw(BAND_WIDTH)<<car.band
		<<setw(MODEL_WIDTH)<<car.model
		<<setw(COLOR_WIDTH)<<car.color
		<<setw(LICENSE_WIDTH)<<car.license
		<<setw(DATE_WIDTH)<<car.producedDate
		<<endl;
	return out;
}
ofstream& operator<<(ofstream& fout,const Car& car){
	fout<<right;
	fout<<setw(HASH_WIDTH)<<car.hash
		<<setw(BAND_WIDTH)<<car.band
		<<setw(MODEL_WIDTH)<<car.model
		<<setw(COLOR_WIDTH)<<car.color
		<<setw(LICENSE_WIDTH)<<car.license
		<<setw(DATE_WIDTH)<<car.producedDate
		<<endl;
	return fout;
}
istream& operator>>(istream& in,Car& car){
	in>>car.band>>car.model>>car.color>>car.license>>car.producedDate;
}
ifstream& operator>>(ifstream& fin,Car& car){ 
	fin>>car.hash>>car.band>>car.model>>car.color>>car.license;
	fin>>car.producedDate;
	return fin;
}
Car::Car():hash(Hash::generate(HASH_LENGTH)){}
Car::Car(string _band,string _model,string _color,string _license,Date _producedDate):
	hash(Hash::generate(HASH_LENGTH)),band(_band),model(_model),color(_color),license(_license),producedDate(_producedDate){}
