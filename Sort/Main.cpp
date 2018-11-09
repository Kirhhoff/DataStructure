#include"NormalComp.h"
#include"inssort.cpp"
#include"qsort.cpp"
#include"heapsort.cpp"
#include"mergesort.cpp"
#include"radixsort.cpp"
#include"selsort.cpp"
#include"bubsort.cpp"
#include"shellsort.cpp"
#include<iomanip>
#include"GetKey.h"
#include<fstream>
#include<iostream>
using namespace std;
#define MAX_NUM_AMOUNT 1000000
const int DOMAIN_WIDTH=10;
const int WORD_WIDTH=14;
#include<time.h>
void examine(const char* filename,int total){
    ifstream fin(filename);
    cout<<left<<setw(DOMAIN_WIDTH)<<total<<"     ";
    cout<<right;
    int amount;
    int* numbers=new int[MAX_NUM_AMOUNT];
    clock_t begin,end;
    fin.clear();
    fin.seekg(0);
    amount=0;
    while(fin>>numbers[amount++]);
    begin=clock();
    inssort<int,NormalComp>(numbers,amount);
    end=clock();
    cout<<setw(DOMAIN_WIDTH)<<(end-begin)*1000/CLOCKS_PER_SEC<<"    ";

    fin.clear();
    fin.seekg(0);
    amount=0;
    while(fin>>numbers[amount++]);
    begin=clock();
    bubsort<int,NormalComp>(numbers,amount);
    end=clock();
    cout<<setw(DOMAIN_WIDTH)<<(end-begin)*1000/CLOCKS_PER_SEC<<"    ";

    fin.clear();
    fin.seekg(0);
    amount=0;
    while(fin>>numbers[amount++]);
    begin=clock();
    selsort<int,NormalComp>(numbers,amount);
    end=clock();
    cout<<setw(DOMAIN_WIDTH)<<(end-begin)*1000/CLOCKS_PER_SEC<<"    ";

    fin.clear();
    fin.seekg(0);
    amount=0;
    while(fin>>numbers[amount++]);
    begin=clock();
    shellsort<int,NormalComp>(numbers,amount);
    end=clock();
    cout<<setw(DOMAIN_WIDTH)<<(end-begin)*1000/CLOCKS_PER_SEC<<"    ";

    fin.clear();
    fin.seekg(0);
    amount=0;
    while(fin>>numbers[amount++]);
    begin=clock();
    mergesort<int,NormalComp>(numbers,amount);
    end=clock();
    cout<<setw(DOMAIN_WIDTH)<<(end-begin)*1000/CLOCKS_PER_SEC<<"    ";

    fin.clear();
    fin.seekg(0);
    amount=0;
    while(fin>>numbers[amount++]);
    begin=clock();
    heapsort<int,NormalComp>(numbers,amount);
    end=clock();
    cout<<setw(DOMAIN_WIDTH)<<(end-begin)*1000/CLOCKS_PER_SEC<<"    ";

    fin.clear();
    fin.seekg(0);
    amount=0;
    while(fin>>numbers[amount++]);
    begin=clock();
    qsort<int,NormalComp>(numbers,0,amount-1);
    end=clock();
    cout<<setw(DOMAIN_WIDTH)<<(end-begin)*1000/CLOCKS_PER_SEC<<"    ";

    fin.clear();
    fin.seekg(0);
    amount=0;
    while(fin>>numbers[amount++]);
    begin=clock();
    radixsort<int,getKey>(numbers,amount,10);
    end=clock();
    cout<<setw(DOMAIN_WIDTH)<<(end-begin)*1000/CLOCKS_PER_SEC<<"    ";

    cout<<endl;
    delete[] numbers;
    fin.close();
}
int main(){
    cout<<left
        <<setw(WORD_WIDTH)<<"Amount"
        <<right
        <<setw(WORD_WIDTH)<<"Insert"
        <<setw(WORD_WIDTH)<<"Bubble"
        <<setw(WORD_WIDTH)<<"Select"
        <<setw(WORD_WIDTH)<<"Shell"
        <<setw(WORD_WIDTH)<<"Merge"
        <<setw(WORD_WIDTH)<<"Heap"
        <<setw(WORD_WIDTH)<<"Quick"
        <<setw(WORD_WIDTH)<<"Radix"
        <<endl;
    examine("Sort/_1000.txt",1000);    
    examine("Sort/_10000.txt",10000);    
    examine("Sort/_100000.txt",100000);    
    // examine("Sort/_1000.txt",1000);    
}
