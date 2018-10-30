#ifndef HEAP_CPP
#define HEAP_CPP
#include"Heap.h"
#include<assert.h>

template<class E,class Comp>
void Heap<E,Comp>::swap(E* heap,int pos1,int pos2){
    E tmp=heap[pos1];
    heap[pos1]=heap[pos2];
    heap[pos2]=tmp; 
}

template<class E,class Comp>
void Heap<E,Comp>::shiftDown(int pos){
    //Continue until in current positon is a leaf node. 
    while(!isLeaf(pos)){
        int biggerChild;//index of bigger child
        if(rightChild(pos)<count)//This indicates node in current position has two children
            biggerChild=Comp::prior(heap[leftChild(pos)],heap[rightChild(pos)])?leftChild(pos):rightChild(pos);//Select the one has bigger priority
        else biggerChild=leftChild(pos);//If only one child,directly select it

        //Compare the node and its bigger child, if the later is bigger, swap and continue
        if(Comp::prior(heap[biggerChild],heap[pos])){
            swap(heap,pos,biggerChild);
            pos=biggerChild;
        }else return;
    }
}

template<class E,class Comp>
void Heap<E,Comp>::insert(const E& element){
    //Check if the heap is full
    assert(count<maxSize);
    int pos=count++;
    heap[pos]=element;//insert into the rear of the heap
    
    //Shift up unti reaching the 0 posotion
    while(pos&&Comp::prior(heap[pos],heap[parent(pos)])){
        swap(heap,pos,parent(pos));
        pos=parent(pos);
    }
}

template<class E,class Comp>
E Heap<E,Comp>::remove(int pos){
    //Check if the heap is empty
    assert(pos<count);
    E removedElement=heap[pos];//Store the removed element
    swap(heap,pos,--count);
    shiftDown(pos);
    return removedElement;
}
#endif 