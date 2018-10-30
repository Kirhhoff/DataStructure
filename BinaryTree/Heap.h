#ifndef HEAP_H
#define HEAP_H
#define DEFAULT_HEAP_SIZE 20
#include"Exception.h"
#include<assert.h>
template<class E,class Comp>
class Heap{
    private:
        int maxSize;
        E* heap;
        int count;
    public:
        Heap(int size=DEFAULT_HEAP_SIZE):maxSize(size),heap(new E[size]),count(0){}
        Heap(E* _heap,int _count,int _maxSize):maxSize(_maxSize),heap(_heap),count(_count){buildHeap();}
        ~Heap(){delete[] heap;}

    private:
        void swap(E* heap,int pos1,int pos2);

    public:

        bool isLeaf(int pos)const{return leftChild(pos)>=count;}
        
        int leftChild(int pos)const{return 2*pos+1;}
        
        int rightChild(int pos)const{return 2*pos+2;}
        
        int parent(int pos)const{assert(pos>0);return (pos-1)/2;}
        
        int isEmpty()const{return !count;}
        
        void buildHeap(){for(int i=count/2-1;i>=0;i--) shiftDown(i);}
        
        void shiftDown(int pos);

        void insert(const E& element);
        
        E remove(int pos);
        
        E removeFirst(){return remove(0);}

        int size() const{return count;}
};
#endif