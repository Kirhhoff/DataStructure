#ifndef QSORT_CPP
#define QSORT_CPP
#include"sort.h"
#include<stdio.h>
#include<iostream>
using namespace std;
template<class E,class Comp>
int findPivot(E elements[],int left,int right){
    int mid=(left+right)/2;
    if(Comp::prior(elements[mid],elements[left])){//If left<mid
        if(Comp::prior(elements[right],elements[mid])) return mid;//if mid<right
        if(Comp::prior(elements[left],elements[right])) return left;//if right<left
        return right;
    }
    //if mid<=left
    if(Comp::prior(elements[mid],elements[right])) return mid;//if right<mid
    if(Comp::prior(elements[right],elements[left])) return left;//if left<right
    return right;
}

template<class E,class Comp>
int partition(E elements[],int leftest,int rightest){
    int pivot=findPivot<E,Comp>(elements,leftest,rightest);
    int save=rightest;
    E pivotElement=elements[pivot];//save the element at where pivot points to
    swap(elements,pivot,rightest--);//swap the pivot to the rear of elements to sort in this cycle
    while(rightest>leftest){
        swap(elements,leftest,rightest);
        while(leftest<save&&(Comp::prior(pivotElement,elements[leftest])||!Comp::prior(elements[leftest],pivotElement))) leftest++;
        while(rightest&&(Comp::prior(elements[rightest],pivotElement)||!Comp::prior(pivotElement,elements[rightest]))) rightest--;
    }
    if(Comp::prior(elements[save],elements[leftest])) leftest+=1;//Solve the problem that when rightest equals leftest it doesn't compare them
    swap(elements,pivot=leftest,save);    //else pivot--;
    return pivot;//return the leftest one of right subarray
}

template<class E,class Comp>
void qsort(E elements[],int leftest,int rightest){
    if(rightest<=leftest) return;

    /*  part the array to two subarrays and get the 
    *   partition point.(the leftest one of right subarray)
    */
    int partPonit=partition<E,Comp>(elements,leftest,rightest);
    //continue sorting two subarrays
    qsort<E,Comp>(elements,leftest,partPonit-1);
    qsort<E,Comp>(elements,partPonit+1,rightest);
}

#endif