#include<stdio.h>
#include<stdlib.h>
void Assert(bool normal,const char* msg){
	if(!normal){
		printf("%s",msg);
		exit(0);
	}
}
