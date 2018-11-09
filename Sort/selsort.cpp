#ifndef SELSORT_CPP
#define SELSORT_CPP
#include"sort.h"
template<class E,class Comp>
void selsort(E elements[],int amount){
    if(amount<=0) return;//avoid wrong arguments
    E min;
    int minIndex;
    for(int kthToSel=0;kthToSel<amount;kthToSel++){//the kth element to select
        min=elements[kthToSel];//first assume the kth element is minimum
        minIndex=kthToSel;//set its index as the minIndex
        for(int nthToCompare=kthToSel+1;nthToCompare<amount;nthToCompare++){//traverse all rest elements
            if(Comp::prior(min,elements[nthToCompare])){//if there exists an element has lower priority 
                min=elements[nthToCompare];//set it minimum element
                minIndex=nthToCompare;//set its index minIndex
            }        
        }
        if(minIndex!=kthToSel) swap(elements,minIndex,kthToSel);//This means the kth element isn't the minimum element, so swap them
    }
}
#endif