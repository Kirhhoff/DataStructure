#ifndef BUBSORT_CPP
#define BUBSORT_CPP
#include"sort.h"
template<class E,class Comp>
void bubsort(E elements[],int amount){
    for(int kthMinBub=0;kthMinBub<amount;kthMinBub++)//generate the kth buble
        for(int nthCheck=amount-1;nthCheck>kthMinBub;nthCheck--)//the nth to check to swap
            if(Comp::prior(elements[nthCheck-1],elements[nthCheck]))
                swap(elements,nthCheck-1,nthCheck);
}
#endif