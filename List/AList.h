#include<stdio.h>
#include<stdlib.h>
#include"List.h"


template<class E>
class AList:virtual public List<E>{
	private:
	typedef typename List<E>::Link ALink;

	private:
	ALink* head;
	ALink* tail;
	ALink* curr;
	int cnt;
		
	public:
	AList(){
		head=tail=curr=new ALink;
		cnt=0;
	}
	~AList(){

	}
	
	public:
	void insert(const E& element){
			
	}	

};


