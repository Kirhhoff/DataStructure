#include"BST.cpp"
#include<stdio.h>
#include<fstream>
using namespace std;

int main(){
    BST<int,char> btree1;
    int key;
    char element;
    ifstream fin("BinaryTree/BST1.txt");
    if(!fin.is_open())
        exit(0);
    while(fin>>key>>element)
        btree1.insert(key,element);
    fin.clear();
    fin.close(); 

    cout<<"前序遍历："<<endl;
    btree1.traverse(BST<int,char>::PRE);
    cout<<"中序遍历："<<endl;
    btree1.traverse(BST<int,char>::IN);
    cout<<"后序遍历："<<endl;
    btree1.traverse(BST<int,char>::POST);
    cout<<" "<<btree1.height()<<endl;
}