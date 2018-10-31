
//#include"HuffTree.h"
#include"HuffTree.cpp"
#include<stdio.h>
#include<map>
#include<fstream>
#define MAX_CHARARCTER_AMOUNT 20
using namespace std;
int main(){  
    ifstream fin("BinaryTree/Frequency.txt");
    Heap<HuffTree<char>*,MinHeapComp> trees;
    map<char,string> codes;
    int charAmount=0;
    char character[MAX_CHARARCTER_AMOUNT];
    int frequency;
    while(fin>>character[charAmount]>>frequency)
        trees.insert(new HuffTree<char>(character[charAmount++],frequency));
    HuffTree<char> completedTree(trees);
    for(int i=0;i<charAmount;i++)
        codes[character[i]]=completedTree.huffCode(character[i]);
        
    fin.clear();
    fin.close();
    for(auto itr=codes.begin();itr!=codes.end();itr++)
        cout<<itr->first<<":"<<itr->second<<endl;
    fin.open("BinaryTree/Datagram.txt");
    ofstream fout("BinaryTree/Codedgram.txt");
    if(!fout.is_open())
        exit(78);
    char p;
    while((p=fin.get())&&(p!='\n')&&(p!=EOF))
        fout<<codes[p];
}