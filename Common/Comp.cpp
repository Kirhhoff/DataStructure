#ifndef COMP_CPP
#define COMP_CPP
#include"Comp.h"
#include"HuffTree.cpp"

template<class E>
bool MinHeapComp::prior(const HuffTree<E>* tree1,const HuffTree<E>* tree2){
    return tree1->weight()<tree2->weight();
}

#endif
