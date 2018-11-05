#include"Comp.h"
#include"inssort.cpp"
#include"qsort.cpp"
#include<fstream>
#include<iostream>
using namespace std;
#define MAX_NUM_AMOUNT 30

int main(){
    ifstream fin("BinaryTree/Heap.txt");
    if(!fin.is_open())
        exit(78);
    int amount=0;
    int numbers[MAX_NUM_AMOUNT];
    while(fin>>numbers[amount]) amount++;
    inssort<int,NormalComp>(numbers,amount);
    //qsort<int,NormalComp>(numbers,0,amount-1);
    for(int i=0;i<amount;i++) cout<<numbers[i]<<endl;
}