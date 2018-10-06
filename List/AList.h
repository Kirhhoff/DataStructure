#include<stdio.h>
#include<stdlib.h>
#include"List.h"


template<class E>
class AList:virtual public List<E>{
	private:
	typename List<E>::Link* head;
	typename List<E>::Link* tail;
	typename List<E>::Link* curr;
	int cnt;
		
	public:
	AList(){
		head=tail=curr=new typename List<E>::Link();
		cnt=0;
	}
	~AList(){
		delete head;
	}
	
	public:
	void insert(const E& element){
		
	}	

};


