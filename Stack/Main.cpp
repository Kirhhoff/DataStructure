#include"AStack.h"
#include<string.h>
#include<stdio.h>
int main(){
	AStack<char>* CS=new AStack<char>(40);
	char word[]="I am here waiting for U.";
	int ptr=0;
	while(ptr<strlen(word))
		CS->push(word[ptr++]);
	while(--ptr>=0)
		printf("%c\n%d\n%c\n",CS->pop(),CS->length(),CS->topValue());
	delete CS;





}
