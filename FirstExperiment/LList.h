#ifndef LLIST_H
#define LLIST_H

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

	//Move the curr pointer to the start of the LList.
	void moveToStart(){curr=head;}
	
	//To judge if the curr point is at the end of the List
	bool atEnd(){return !curr->next;}
	
	//Move the curr pointer to the end of the LList.
	void moveToEnd(){curr=tail;}
	
	//Used when inserting with sort to find the appropriate position for new element.
	void moveToPosition(const E& element){
		moveToStart();
		//break when it reachs the tail
		//or
		//it finds one bigger than it.
		while(curr->next){
			if(element<curr->next->element)
				break;
			curr=curr->next;
		}
	}
	//Insert with sorting.
	void sortedInsert(const E& element){
		moveToPosition(element);
		insert(element);
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

	//Remove all element for reuse or destructor.
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
	
	//swap the value at two specified positions.
	bool swap(int pos1,int pos2){
		//Directly return when postion overflows or it is too small
		if(pos1>cnt||pos2>cnt||pos1<1||pos2<1)
			return false;
		
		//If the two position are the same, directly return.
		if(pos1==pos2) 
			return true;

		
		List** container=new List*[cnt+1];//the array to accommodate all Links. 
		List* tmp=head;//iterator 
		int curPos=0;//Later record the postion of curr pointer.
		
		//Transfer all 
		for(int i=1;i<=cnt;i++){
			if(tmp==curr)
				curPos=i;
			container[i]=tmp->next;
			tmp=tmp->next;
		}
		tmp=container[pos1];
		container[pos1]=container[pos2];
		container[pos2]=tmp;
		for(int i=1;i<=cnt-1;i++)
			container[i]->next=container[i+1];
		container[cnt]->next=0;
		head->next=container[1];
		tail=container[cnt];
		if(cnt=1)
			curr=head;
		else
			curr=container[curPos-1];
		delete [] container;
	}
	
	//sort the elements
	void sort(){
		if(cnt<=1)
			return;
		List** container=new List*[cnt+1];
		List* tmpLink;
		for(int kthToSort=1;kthToSort<=cnt;kthToSort++){
			for(int prevkthToCompare=1;prevkthToCompare<=kthToSort;prevkthToCompare++)
				if(container[prevkthToCompare]->element>container[kthToSort]->element
				&&(prevkthToCompare==1||container[prevkthToCompare-1]->element>container[kthToSort]->element)){
					tmpLink=container[kthToSort];
					for(int kthToMove=kthToSort-1;kthToMove>=prevkthToCompare;kthToMove--)
						container[kthToMove+1]=container[kthToMove];
					container[prevkthToCompare]=tmpLink;
					break;
				}
		}
		for(int i=1;i<cnt;i++)
			container[i]->next=container[i+1];
		head->next=container[1];
		tail=container[cnt];
		tail->next=0;
		delete [] container;
	}
	
	
};

#endif