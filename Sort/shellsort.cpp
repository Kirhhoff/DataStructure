#ifndef SHELLSORT_CPP
#define SHELLSORT_CPP
#include"sort.h"
#include<stdio.h>
template<class E,class Comp>
void shellsort(E elements[],int amount){
    if(amount<=0) return;
    int radix=5;
    for(int block=radix;(block<=amount)||((block/radix)<=amount);block*=radix){//increase the size of block after every cycle
        int step=(amount+block-1)/block;//set the step size for every cycle
        for(int start=0;start<step;start++)//set beginning index for every group
            for(int kthToSort=1;kthToSort*step+start<amount;kthToSort++)//find the position of the kth element
                for(int nthToComp=kthToSort-1;nthToComp>=0;nthToComp--)//compare it with preceding elements
                    if(Comp::prior(elements[start+kthToSort*step],elements[start+nthToComp*step])||!nthToComp){//until find one with lower priority than it
                        if(!Comp::prior(elements[start+kthToSort*step],elements[start+nthToComp*step])) nthToComp--;
                        E tmp=elements[start+kthToSort*step];//save the element
                        for(int xthToMove=kthToSort-1;xthToMove>nthToComp;xthToMove--)//move it to the position after that element with lower priority 
                            elements[start+(xthToMove+1)*step]=elements[start+xthToMove*step];
                        elements[start+(nthToComp+1)*step]=tmp;
                        break;        
                    }
    }
}
#endif