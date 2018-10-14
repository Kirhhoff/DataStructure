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
		LList<Car>* cars;//Car information read from local file.
		ofstream fout;
		ifstream fin;
		string databaseFile;//The path of database file.
	public:
		Interface(string carDatabase);
		~Interface();
	public:
		void operating();/*		This function works as the whole program life cycle.
								The menu is implemented like a tree. The main 
							menu is like the root node of a tree which has a variaty 
							of subnodes on behalf of different function entrance.
								But this is just a anology while the program is
							not implented by tree ADT.I mean, when you select a 
							function option to,such as list all cars' information
							or delete cars, it looks like you travel forward a 
							subnode. And when you choose to "back to previous menu",
							in which way you just return to the calling funtion,
							it looks like you come back to the parent node.
								In this way, I can make sure the stack memory is 
							enough.
								So in this function named "operating",I adopt a while 
							cycle to refresh the main menu. Among every cycle,the main 
							menu is shown, you can select a function entrance by input
							1,2,3.... After that,you jump into the function you select.
							When you finish your updating,deleting and etc, you jump back
							to here, and the screen is flushed, the next cycle begins.
								You will continue the cycle until you choose to quit. 
						*/
		void clean();/*		This function provides the screen flushing.In different platform
						it has different implementation. Under Windows, I adpot command "cls",
						while under Linux, I adopt command "clear" or sometimes command "reset".
					*/
		void showEntries();/* 	This function shows the main menu*/
		void Entry(int entryNumber);/*		This function requires a entry number as argument
										to judge which submenu to jump to. After that it will
										show relative interface and  execute relative behaviors 
										according to the entry number.
											In a word,it almost contains all submenu logic.
									*/
		void Error(errorType errorNumber);/*	This is a error handling function.
											According to error number,it will show relative 
											prompts to prompt users to modify their inputs.
											*/
		LList<Car>* search(searchGist gistNumber);
	private:
		void sync();//Rewrite the cars information into local file.
		void readDatabase(string databaseFileName);//Read cars information from local file.
		int getEntryInput();/*	This is the input handling function of entry select.
							As some people may input at random, I have to wrap a function 
							to handle it.
								Among this function,it will prompt user to input and analyse
							the input.If the input is valid,it will directly return the input.
							If not, it will return -1 to indicate user has make an invalid input,
							after which relative error handling function will be called.
							*/
		int getCarInput(Car& carReceipt);/*	This is the input handling function of car information input.
										As some people may input at random, I have to wrap a function 
										to handle it.	
											If the user input is valid,it will return 0 and assign the input
										to the carReceipt for later date insert.
											If user inputs an invalid produced date it will return an INVALID_DATE
										macro.If user input is not enough or has other invalid information,it will
										return an  INVALID_CAR_INFO macro.
											All these error will be later handled.
										*/
		void backup(string databaseToBackup);
};

#endif
