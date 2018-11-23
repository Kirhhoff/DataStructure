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
#include<windows.h>
#include<iostream>
using namespace std;
#define MAX_NUM_AMOUNT 10000000
const int DOMAIN_WIDTH=10;
void examine(const char* filename,int total){
    LARGE_INTEGER cpufre;
    QueryPerformanceFrequency(&cpufre);
    ifstream fin(filename);
    cout<<left<<setw(DOMAIN_WIDTH)<<total;
    cout<<right;
    int amount;
    int* numbers=new int[MAX_NUM_AMOUNT];
    LARGE_INTEGER begin,end;
    if(total<1000000){
        fin.clear();
        fin.seekg(0);
        amount=0;
        while(fin>>numbers[amount++]);
        QueryPerformanceCounter(&begin);
        inssort<int,NormalComp>(numbers,amount);
        QueryPerformanceCounter(&end);
        cout<<setw(DOMAIN_WIDTH)<<(double)(end.QuadPart-begin.QuadPart)*10000/cpufre.QuadPart;

        fin.clear();
        fin.seekg(0);
        amount=0;
        while(fin>>numbers[amount++]);
        QueryPerformanceCounter(&begin);
        bubsort<int,NormalComp>(numbers,amount);
        QueryPerformanceCounter(&end);
        cout<<setw(DOMAIN_WIDTH)<<(double)(end.QuadPart-begin.QuadPart)*10000/cpufre.QuadPart;

        fin.clear();
        fin.seekg(0);
        amount=0;
        while(fin>>numbers[amount++]);
        QueryPerformanceCounter(&begin);
        selsort<int,NormalComp>(numbers,amount);
        QueryPerformanceCounter(&end);
        cout<<setw(DOMAIN_WIDTH)<<(double)(end.QuadPart-begin.QuadPart)*10000/cpufre.QuadPart;
    }else cout<<setw(DOMAIN_WIDTH)<<"-"<<setw(DOMAIN_WIDTH)<<"-"<<setw(DOMAIN_WIDTH)<<"-";

    fin.clear();
    fin.seekg(0);
    amount=0;
    while(fin>>numbers[amount++]);
    QueryPerformanceCounter(&begin);
    shellsort<int,NormalComp>(numbers,amount);
    QueryPerformanceCounter(&end);
    cout<<setw(DOMAIN_WIDTH)<<(double)(end.QuadPart-begin.QuadPart)*10000/cpufre.QuadPart;

    fin.clear();
    fin.seekg(0);
    amount=0;
    while(fin>>numbers[amount++]);
    QueryPerformanceCounter(&begin);
    mergesort<int,NormalComp>(numbers,amount);
    QueryPerformanceCounter(&end);
    cout<<setw(DOMAIN_WIDTH)<<(double)(end.QuadPart-begin.QuadPart)*10000/cpufre.QuadPart;

    fin.clear();
    fin.seekg(0);
    amount=0;
    while(fin>>numbers[amount++]);
    QueryPerformanceCounter(&begin);
    heapsort<int,NormalComp>(numbers,amount);
    QueryPerformanceCounter(&end);
    cout<<setw(DOMAIN_WIDTH)<<(double)(end.QuadPart-begin.QuadPart)*10000/cpufre.QuadPart;

    fin.clear();
    fin.seekg(0);
    amount=0;
    while(fin>>numbers[amount++]);
    QueryPerformanceCounter(&begin);
    qsort<int,NormalComp>(numbers,0,amount-1);
    QueryPerformanceCounter(&end);
    cout<<setw(DOMAIN_WIDTH)<<(double)(end.QuadPart-begin.QuadPart)*10000/cpufre.QuadPart;


    fin.clear();
    fin.seekg(0);
    amount=0;
    while(fin>>numbers[amount++]);
    QueryPerformanceCounter(&begin);
    radixsort<int,getKey>(numbers,amount,10);
    QueryPerformanceCounter(&end);
    cout<<setw(DOMAIN_WIDTH)<<(double)(end.QuadPart-begin.QuadPart)*10000/cpufre.QuadPart;

    cout<<endl;
    delete[] numbers;
    fin.close();
}

void gen(){
    ofstream fout("Sort/_10000000.txt");
    for(int i=0;i<1000000;i++){
        for(int j=0;j<10;j++)
            fout<<rand()<<" ";
        fout<<endl;
    }
}
int main(){
    //gen();
    
    cout<<left
        <<setw(DOMAIN_WIDTH)<<"Amount"
        <<right
        <<setw(DOMAIN_WIDTH)<<"Insert"
        <<setw(DOMAIN_WIDTH)<<"Bubble"
        <<setw(DOMAIN_WIDTH)<<"Select"
        <<setw(DOMAIN_WIDTH)<<"Shell"
        <<setw(DOMAIN_WIDTH)<<"Merge"
        <<setw(DOMAIN_WIDTH)<<"Heap"
        <<setw(DOMAIN_WIDTH)<<"Quick"
        <<setw(DOMAIN_WIDTH)<<"Radix"
        <<endl;
    examine("Sort/_100.txt",100);        
    examine("Sort/_1000.txt",1000);    
    examine("Sort/_10000.txt",10000);    
    //examine("Sort/_100000.txt",100000);    
    examine("Sort/_1000000.txt",1000000);
    examine("Sort/_10000000.txt",10000000);    
    
}

