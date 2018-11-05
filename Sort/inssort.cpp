#ifndef INSSORT_CPP
#define INSSORT_CPP
#include<stdio.h>
template<class E,class Comp>
void inssort(E elements[],int amount){
    for(int kthToSort=0;kthToSort<amount;kthToSort++)//Now it is the kth one to be sorted.
        for(int nthToCompare=kthToSort-1;nthToCompare>=0;nthToCompare--)//Compare the element with thar preceding it one by one
            if(Comp::prior(elements[kthToSort],elements[nthToCompare])||!nthToCompare){//until find an element whose priority is lower than it.
                E tmp=elements[kthToSort];//Temporarily save the element 
                if(!Comp::prior(elements[kthToSort],elements[nthToCompare])) nthToCompare--;//Solve current element to sort is smaller than the first one
                for(int toMove=kthToSort-1;toMove>=nthToCompare+1;toMove--)//Move every one whose priority lower than it to the one 
                    elements[toMove+1]=elements[toMove];                 //after themselves one by one
                elements[nthToCompare+1]=tmp;//Set the previous position with the element we saved
                break;//Continue sorting the next element
            }
}
#endif