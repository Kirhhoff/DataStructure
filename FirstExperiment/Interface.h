#ifndef INTERFACE_H
#define INTERFACE_H

#include<iostream>
#include<fstream>
#include"LLDictionary.h"
#include"Car.h"
#include"Key.h"
#include"config.h"
using std::ofstream;
using std::ifstream;
class Interface{
	private:
		LLDictionary<Key,Car> dictionary;
		ofstream fout;
		ifstream fin;
		string databaseFile;//The path of database file.
	public:
		Interface(string carDatabase);/*	Among the constructor it will first back-up data then read.
										Read the detail about reasons by go to its definition.
									*/

		~Interface();//Among this function it will synchronize the data to file.
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
		void clean() const;/*	This function provides the screen flushing.In different platform
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
	private:
		void showCars();//Relative to option 1
		void insertCars();//Relative to option 2
		void deleteCars();//Relative to option 3
		void updateCars();//Relative to option 4
		void searchCars();//Relative to option 5
		
	private:
		void readDatabase(string databaseFileName);//Read cars information from local file.
		void backup(string databaseToBackup);/*		Back up the database every time this program
												launches.
											*/
		void sync();//Rewrite the cars information into local file.
		int getEntryInput();/*	This is the input handling function of entry select.
							As some people may input at random, I have to wrap a function 
							to handle it.
								If the input is valid,it will directly return the input.
								If not, it will clean the input buffer and return -1 to indicate 
							user has make an invalid input,after which relative error handling function will be called.
							*/
		int getCarInput(Car& carReceipt);/*	This is the input handling function of car information input.
										As some people may input at random, I have to wrap a function 
										to handle it.	
											If the user input is valid,it will return 0 and assign the input
										to the carReceipt for later date insert.
											If user inputs an invalid produced date it will return an INVALID_DATE
										macro.If user input is not enough or has other invalid information,it will
										return an  INVALID_CAR_INFO macro.
										*/
		int getGistNumber();/*	This is the input handling function of gist number input.
							As some people may input at random, I have to wrap a function 
							to handle it.
								If the user input is valid,it will directly return the gist number 
							for later we get users' gist value.
								If not, it will clear the cin, clean the input buffer and return 
							an INVALID_GIST_NUMBER macro.
							*/
		LList<KVpair<Key,Car>>* search(searchGist gistNumber);/*	This function contains serveral switch statements. So it seems 
																redundant and clumsy.But to implement the Polymorphsim to diffrent gist this 
																is necessary.And I think for such a simple problem to add a FSM here
																is far more clumsy.
																	As for a car, its hash,band,model,color and license are all stored 
																of type string. So under their cases, some handles are the same among 
																the switch case. And for date, it has an extra but also similar and simply
																handle.
																	The search is implemented truly clumsy.It creates a new pointer named 
																result to store the search result and directly traverses the database.
																	For every entry in the database, it compare the gist value got form 
																preceding switch statement with the entry's relative attribute. If they are
																equal,insert the entry into the result.
																	After the traversing,directly return.
																	Clumsy but easy.
															*/
		void showPairList(LList<KVpair<Key,Car>>* pairList);//	Show all content of a pairList
															
};

#endif
