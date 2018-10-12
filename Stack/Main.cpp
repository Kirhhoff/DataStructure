#include"AStack.h"
#include<string.h>
#include<stdio.h>

long fact(int n){
	Assert(n>=0,"n must be positive!\n");
	AStack<int> stack(n);
	stack.push(1);
	stack.push(1);
	for(int k=2;k<n;k++){
		int v1=stack.pop();
		int v2=stack.pop();
		stack.push(v2);
		stack.push(v1);
		stack.push(v1+v2);
	}
	while(stack.length())
		printf("%d ",stack.pop());
}

long factWithoutStack(int n){
	
}
int main(){
	AStack<char>* CS=new AStack<char>(40);
	char word[]="I am here waiting for U.";
	int ptr=0;
	while(ptr<strlen(word))
		CS->push(word[ptr++]);
	while(--ptr>=0)
		printf("%c\n%d\n%c\n",CS->pop(),CS->length(),CS->topValue());
	delete CS;
	
	fact(15);



}
