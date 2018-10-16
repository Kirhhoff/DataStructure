#ifndef CONFIG_H
#define CONFIG_H
#include<string>
using std::string;
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
    These macroes define the different function entries.
*/
#define SHOW_CARS 1
#define INSERT_CARS 2
#define DELETE_CARS 3
#define UPDATE_CARS 4
#define SEARCH_CARS 5


#define HASH 0
#define BAND 1
#define MODEL 2
#define COLOR 3
#define LICENSE 4
#define DATE 5

/*
    
*/
#define FINE 0
#define INVALID_ENTRY 1
#define INVALID_SEARCH_GIST 2
#define INVALID_CAR_INFO 3
#define INVALID_DATE 4
#define INVALID_GIST_NUMBER -1

#define HASH_LENGTH 15
extern string carDatabase;
typedef int errorType;
typedef int searchGist;




#endif


