#ifndef HEAD_H
#define HEAD_H
#include<iostream>

#define MAX_ENTRY 7
typedef int errorType;
#define INVALID_ENTRY 0

class Interface{
	
	public:
		void operating();
		void clean();
		void showEntries();
		void Entry(int entryNumber);
		void Error(errorType errorNumber);
	private:
		int getEntryInput();
		void showEntry(int entryNumber);
		void logicOfEntry(int entryNumber);

};

#endif
