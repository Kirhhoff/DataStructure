#ifndef MERGESORT_CPP
#define MERGESORT_CPP
#include"sort.h"
template<class E,class Comp>
void mergesortHelper(E elements[],E mergeHelper[],int amount){
    if(amount==1) return;//when the subarray has been divied to one
    E *left,*right;//left subarray and right subarray
    int ptr=0,lptr=0,rptr=0,lsize=amount/2,rsize=(amount+1)/2;/*  define tracker for total array
                                                                define left&right tracker
                                                                define size of left&right subarray
                                                            */
    mergesortHelper<E,Comp>(left=elements,mergeHelper,lsize);         //ensure before merging left
    mergesortHelper<E,Comp>(right=elements+amount/2,mergeHelper,rsize);//part and right part are both in order
    
    //Begin merging
    while(lptr<lsize&&rptr<rsize)//make the total array is also in order
        mergeHelper[ptr++]=Comp::prior(left[lptr],right[rptr])?right[rptr++]:left[lptr++];
    //cope with rest elements
    if(lptr==lsize) while(rptr<rsize) mergeHelper[ptr++]=right[rptr++];
    else while(lptr<lsize) mergeHelper[ptr++]=left[lptr++];
    for(ptr=0;ptr<amount;ptr++) elements[ptr]=mergeHelper[ptr];//transfer elements to total array
}

template<class E,class Comp>
void mergesort(E elements[],int amount){
    E* mergeHelper=new E[amount];//create a helper array
    mergesortHelper<E,Comp>(elements,mergeHelper,amount);
    delete[] mergeHelper;
}
#endif