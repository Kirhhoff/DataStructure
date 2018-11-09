#ifndef HEAPSORT_CPP
#define HEAPSORT_CPP
#include"sort.h"
#include"Heap.cpp"
template<class E,class Comp>
void heapsort(E elements[],int amount){
    Heap<E,Comp> heap(amount);//Create a heap of the same capacity with input array
    for(int i=0;i<amount;i++)//Build heap by inserting
        heap.insert(elements[i]);    
    for(int i=0;i<amount;i++)//Output sorted array
        elements[i]=heap.removeFirst();    
}




#endif