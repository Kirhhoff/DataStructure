#ifndef HEAP_H
#define HEAP_H
#define HEAP_DEFAULT_SIZE 20
#include"Exception.h"
template<class E,class Comp>
class Heap{
    private:
        int maxSize;
        E* heap;
        int count;
    
    public:
        Heap(int size=HEAP_DEFAULT_SIZE):maxSize(size),heap(new E[size]),count(0){}
        Heap(E* _heap,int _count,int _maxSize):maxSize(_maxSize),heap(_heap),count(_count){buildHeap();}
        ~Heap(){delete[] heap;}
    
    private:
        void swap(E* heap,int pos1,int pos2);

    public:
        bool isLeaf(int pos){return leftChild(pos)>=count;}
        
        int leftChild(int pos)const{return 2*pos+1;}
        
        int rightChild(int pos)const{return 2*pos+2;}
        
        int parent(int pos)const{return (pos-1)/2;}
        
        int isEmpty(){return !count;}
        
        void buildHeap(){for(int i=count/2-1;i>=0;i--) shiftDown(i);}
        
        void shiftDown(int pos);

        void insert(const E& element);
        
        E remove(int pos);
        
        E removeFirst(){return remove(0);}
};
#endif