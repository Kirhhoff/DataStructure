#ifndef ALIST_H
#define ALIST_H
#define DEFAULT_SIZE 25
#include<assert.h>
template<class E>
class AList{
    private:
        int size;
        int cnt;
        int curr;
        E* arrayList;

    public:
        AList(int _size=DEFAULT_SIZE):size(_size),cnt(0),curr(0),arrayList(new E[size]){}
        ~AList(){delete [] arrayList;}
    
    public:
        //Return the current amount of elements.
        int length(){return cnt;}

        //Return the current amount of elements
        int getPos(){return cnt?curr+1:0;}

        //Get the value of current position
        E& getValue(){
            assert(curr!=cnt);
            return arrayList[curr];
        }

        //Judge if the AList is empty
        bool isEmpty(){return !cnt;}

        //Judge if the curr pointer is at end of the list
        bool atEnd(){return curr==cnt;}

        //Move curr to the next element.
        void next(){atEnd()?0:curr++;}

        //Move the curr pointer to the end of the AList.
        void moveToEnd(){curr=cnt;}

        //Move the curr pointer to the start of the AList.
        void moveToStart(){curr=0;}

        //Insert an element at current position
        void insert(const E& element){
            assert(cnt<size);
            for(int backWard=cnt-1;backWard>=curr;backWard--)
                arrayList[backWard+1]=arrayList[backWard];
            arrayList[curr]=element;
            cnt++;
        }

        //Remove the element at current position
        E remove(){
            assert(curr!=cnt);
            E removedElement=arrayList[curr];
            for(int forWard=curr+1;forWard<=cnt-1;forWard++)
                arrayList[forWard-1]=arrayList[forWard];
            cnt--;
            return removedElement;
        }
};
#endif