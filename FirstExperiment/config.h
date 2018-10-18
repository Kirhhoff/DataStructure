#ifndef CONFIG_H
#define CONFIG_H
#include<string>
using std::string;

//This is the maximum entry number
#define MAX_ENTRY 5

/*
    These macroes define the width of different car information field.
*/
#define HASH_WIDTH 20
#define BAND_WIDTH 20
#define MODEL_WIDTH 20
#define COLOR_WIDTH 20
#define LICENSE_WIDTH 20
#define DATE_WIDTH 20

/*
    These macroes define the different function entries and invalid entry case
*/
#define INVALID_ENTRY -1
#define QUIT 0
#define SHOW_CARS 1
#define INSERT_CARS 2
#define DELETE_CARS 3
#define UPDATE_CARS 4
#define SEARCH_CARS 5

/*
    These macroes define different search gist.So these are gist numbers.
*/
#define HASH 1
#define BAND 2
#define MODEL 3
#define COLOR 4
#define LICENSE 5
#define DATE 6
#define MAX_GIST 6

/*  
    These are some errors
*/
#define INVALID_GIST_NUMBER -1
#define FINE 0
#define INVALID_SEARCH_GIST 1
#define INVALID_CAR_INFO 2
#define INVALID_DATE 3

//This is the hash code length
#define HASH_LENGTH 15
extern string carDatabase;
typedef int searchGist;




#endif


