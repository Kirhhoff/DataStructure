#include"Heap.h"
#include<assert.h>
template<class E>
void Heap<E>::swap(E* heap,int pos1,int pos2){
    E tmp=heap[pos1];
    heap[pos1]=heap[pos2];
    heap[pos2]=tmp; 
}
template<class E>
void Heap<E>::shiftDown(int pos){
    while(!isLeaf(pos)){
        int biggerChild;
        if(rightChild(pos)<count)
            biggerChild=heap[leftChild(pos)]>heap[rightChild(pos)]?leftChild(pos):rightChild(pos);
        else biggerChild=leftChild(pos);
        if(heap[biggerChild]>heap[pos]){
            swap(heap,pos,biggerChild);
            pos=biggerChild;
        }else return;
    }
}

template<class E>
void Heap<E>::insert(const E& element){
    assert(count<maxSize);
    int pos=count++;
    heap[pos]=element;
    while(pos&&heap[parent(pos)]<heap[pos]){
        swap(heap,pos,parent(pos));
        pos=parent(pos);
    }
}

template<class E>
E Heap<E>::remove(int pos){
    assert(pos<count);
    E removedElement=heap[pos];
    swap(heap,pos,--count);
    shiftDown(pos);
    return removedElement;
}
