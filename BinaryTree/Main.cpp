#include"BST.cpp"
#include<stdio.h>
#include<fstream>
using namespace std;

int main(){
    //BSTNode<int,char>* t=new BSTNode<int,char>;
    BST<int,char> btree;
    ifstream fin("BinaryTree/BST.txt");
    int key;
    char element;
    if(!fin.is_open())
        exit(0);
    while(fin>>key>>element)
        btree.insert(key,element);
    btree.traverse(BST<int,char>::PRE);
    cout<<endl;
    btree.traverse(BST<int,char>::IN);
    cout<<endl;
    btree.traverse(BST<int,char>::POST);
}