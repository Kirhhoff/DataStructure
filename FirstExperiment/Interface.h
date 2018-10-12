#ifndef INTERFACE_H
#define INTERFACE_H
#include<iostream>
#include<fstream>
#include"LList.h"
#include"Car.h"
#include"config.h"
using std::ofstream;
using std::ifstream;
class Interface{
	private:
		LList<Car>* cars;
		ofstream fout;
		ifstream fin;
	public:
		Interface(string databaseFileName=carDatabase);
		~Interface();
	public:
		void operating();
		void clean();
		void showEntries();
		void Entry(int entryNumber);
		void Error(errorType errorNumber);
		void search(searchGist gistNumber);
	private:
		void readDatabase(string databaseFileName);
		int getEntryInput();
		void showEntry(int entryNumber);
		void logicOfEntry(int entryNumber);

};

#endif
