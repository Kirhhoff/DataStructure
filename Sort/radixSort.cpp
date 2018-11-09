#ifndef RADIXSORT_CPP
#define RADIXSORT_CPP
#include<math.h>

template<class E,class getKey>
void radixsortHelper(E elements[],E radixHelper[],int amount,int radix,int bit,int divisor,int maxbit){
    int* cnt=new int[radix+1]{};
    for(int i=0;i<amount;i++) cnt[(getKey::key(elements[i])/divisor)%radix+1]++;//count how many elements are there for every radix
    for(int i=1;i<radix;i++) cnt[i]+=cnt[i-1];//calculate the divider for every radix
    for(int i=0;i<amount;i++) radixHelper[cnt[(getKey::key(elements[i])/divisor)%radix]++]=elements[i];//scan the whole array
    for(int i=0;i<amount;i++) elements[i]=radixHelper[i];//scan the whole array
    delete[] cnt;
    if(bit<maxbit) radixsortHelper<E,getKey>(elements,radixHelper,amount,radix,++bit,divisor*radix,maxbit);    
}

template<class E,class getKey>
void radixsort(E elements[],int amount,int radix){
    E* radixHelper=new E[amount];
    int maxbit=0;
    for(int i=0;i<amount;i++) if((int)(log(getKey::key(elements[i]))/log(radix))>maxbit) maxbit=log(getKey::key(elements[i]))/log(radix);
    radixsortHelper<E,getKey>(elements,radixHelper,amount,radix,0,1,maxbit);
}

#endif