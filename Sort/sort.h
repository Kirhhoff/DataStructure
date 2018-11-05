#ifndef SORT_H
#define SORT_H

template<class E>
void swap(E elements[],int pos1,int pos2){
    E tmp=elements[pos1];
    elements[pos1]=elements[pos2];
    elements[pos2]=tmp;
}

template<class E,class Comp>
void inssort(E elements[],int amount);

template<class E,class Comp>
void qsort(E elements[],int leftest,int rightest);









#endif