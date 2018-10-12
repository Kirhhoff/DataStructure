#include"Car.h"


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

ofstream& operator<<(ofstream& fout,const Car& car){

}

ifstream& operator>>(ifstream& fin,Car& car){

}
