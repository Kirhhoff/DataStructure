#ifndef ASTACK_H
#define ASTACK_H
#include"Stack.h"
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
			Assert(top,"Stack is empty!\n");
			return listArray[--top];
		}
		virtual void push(const E& element){
			Assert(top!=maxSize,"Stack is full!\n");
			listArray[top++]=element;
		}
		virtual const E& topValue()const{
			Assert(top,"Stack is empty!\n");
			return listArray[top-1];
		}
		virtual int length()const{
			return top;
		}
		virtual void clear(){
			top=0;
		}

		

};



#endif
