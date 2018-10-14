

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<assert.h>
#include"Car.h"
template<class E>
class LList{
	//The following defines a private class List.
	//As the class List will not be used outside the class LList, I decide
	//to set it to be private. And For every element type, a pair of LList 
	//class and List class of the same type is needed, so the class List is
	//effected by the same template declaration with class LList.
	private:
	class List{
		public:
		E element;
		List* next;
		public:
		List(List* itsNext=NULL):next(itsNext){}
		List(const E& e,List* itsNext=NULL):element(e),next(itsNext){}
	};
	
	//The following defines the private member variables.
	private:
	List* head;
	List* tail;
	List* curr;
	int cnt;

	//The following defines the public constructors and destructors.
	//(Though there is only one constructor and one destructor.)
	public:
	LList(){
		init();
	}
	~LList(){
		//Here I change the implementation
		removeAll();
	}
	
	
	//The following defines all private methods used.
	//(Though there is only one method....)
	private:

	//
	void init(){
		head=tail=curr=new List();
		cnt=0;
	}

	//The following defines all public methods except constructors and destructors.
	public:
	
	//Insert a new element preceding the one curr pointer points to
	//currently.
	void insert(const E& element){
		curr->next=new List(element,curr->next);
		if(curr==tail)
			tail=curr->next;
		cnt++;
	}
	
	//Remove the element curr pointer points to currently.	
	E remove(){
		assert(curr->next);
		if(curr->next==tail)
			tail=curr;
		E deletedElement=curr->next->element;
		List* tmp=curr->next;
		curr->next=curr->next->next;
		delete tmp;
		cnt--;
		return deletedElement; 
	}
	
	//Add a new element after the tail element and get
	//the tail pointer point to this new one.
	void append(const E& element){
		tail=tail->next=new List(element,NULL);
		cnt++;	
	}

	//Move the curr pointer to the start of the LList.
	void moveToStart(){curr=head;}
	
	//To judge if the curr point is at the end of the List
	bool atEnd(){return !curr->next;}
	
	//Move the curr pointer to the end of the LList.
	void moveToEnd(){curr=tail;}
	
	//Get the value of element curr pointer points to currently.
	E& getValue(){
		assert(curr!=tail);
		return curr->next->element;
	}
	
	//Return current amount of elements.
	int length(){return cnt;}
	
	//Move the curr pointer to the one preceding it.
	void prev(){
		if(curr!=head){
			List* tmp=head;
			while(tmp->next!=curr)
				tmp=tmp->next;
			curr=tmp;
		}
	}
	
	//Move the curr pointer to the one after it.
	bool next(){
		if(curr!=tail){
			curr=curr->next;
			return true;
		}else
			return false;
	}

	//
	void removeAll(){
		cnt=0;
		curr=tail=head;
		while(curr=head->next){
			head->next=head->next->next;
			delete curr;
		}
		curr=head;
	}
	
	//Reverse the LList
	void reverse(){
		if(cnt>1){	
			List** larray=new List*[cnt];//Create a array of List* to accommodate all elements for later relink.
			List* tmp=head;//A temporary pointer to tarverse the LList.
			
			//Use a for loop to fill larray in reversed order relative to the original LList.
			for(int i=0;i<cnt;i++){
				tmp=tmp->next;
				larray[cnt-i-1]=tmp;
			}
			
			//Set the curr pointer
			if(curr==head)
				curr=larray[cnt-2];
			else if (curr==tail||curr->next==tail)
				curr=head;
			else
				curr=curr->next->next;
			
			head->next=larray[0];//Set the head pointer.
			tail=larray[cnt-1];//Set the tail pointer.
			
			//Relink the LList in reversed order.
			for(int i=0;i<cnt-1;i++)
				larray[i]->next=larray[i+1];
			larray[cnt-1]->next=NULL;//Deal with the last one.
			delete[] larray;//Release the memory
		}
	}

	//Return the position of the element curr pointer points to.
	int getPos(){
		if(tail=head)
			return 0;
		int i=1;
		for(List* tmp=head;tmp!=curr;i++)
			tmp=tmp->next;
		return i;
	}
	
	//Merge two LList and return a LList pointer.
	LList<E>* merge(LList<E> llist){
		List* tmp1=head;//Set a pointer to follow the first LList.
		List* tmp2=llist.head;//Set a pointer to follow the second LList.
		head=head->next->element<llist.head->next->element?head:llist.head;//Set the final result of the head pointer.
		LList<E>* result=new LList<E>();//Set a LList as the result to return
		
		//Cycle until one of the LList reaching its end.
		while(tmp1->next&&tmp2->next){
			if(tmp1->next->element<tmp2->next->element){
				result->append(tmp1->next->element);
				tmp1=tmp1->next;
			}else{
				result->append(tmp2->next->element);
				tmp2=tmp2->next;
			}
		}
		
		//Connect the rest untraversed LList part.
		if(!tmp1->next)
			for(;tmp2->next;tmp2=tmp2->next)
				result->append(tmp2->next->element);
		else
			for(;tmp1->next;tmp1=tmp1->next)
				result->append(tmp1->next->element);
		return result;
	}
	
	//
	bool swap(int pos1,int pos2){
		if(pos1>length||pos2>length||pos1<1||pos2<1)
			return false;
		if(pos1==pos2) 
			return true;
		Link** container=new Link*[length+1];
		Link* tmp=head;
		int curPos=0;
		for(int i=1;i<=length;i++){
			if(tmp==curr)
				curPos=i;
			container[i]=tmp->next;
			tmp=tmp->next;
		}
		tmp=container[pos1];
		container[pos1]=container[pos2];
		container[pos2]=tmp;
		for(int i=1;i<=length-1;i++)
			container[i]->next=container[i+1];
		container[length]->next=0;
		head->next=container[1];
		tail=container[length];
		if(length=1)
			curr=head;
		else
			curr=container[curPos-1];
		delete [] container;
	}
};

