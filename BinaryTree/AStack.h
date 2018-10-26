#ifndef ASTACK_H
#define ASTACK_H
#include"Stack.h"
#include<assert.h>
#define defaultSize 5
template<class E>
class AStack:public Stack<E>{
	private:
		int maxSize;
		int top;
		E* listArray;

	public:
		AStack(int size=defaultSize):maxSize(size),top(0),listArray(new E[maxSize]){}
		virtual ~AStack(){}
	
	public:
		virtual E pop(){
			assert(top);
			return listArray[--top];
		}
		virtual void push(const E& element){
			assert(top!=maxSize);
			listArray[top++]=element;
		}
		virtual const E& topValue()const{
			assert(top);
			return listArray[top-1];
		}
		virtual int length()const{return top;}
		virtual void clear(){top=0;}
		virtual bool isEmpty() const{return !length();}
};
#endif
