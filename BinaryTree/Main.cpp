#include"BST.cpp"
#include"HuffTree.h"
#include<stdio.h>
#include<fstream>
using namespace std;
int main(){  
    BST<int,int> btree1;
    int key;
    char element;
    ifstream fin("BinaryTree/BST1.txt");
    if(!fin.is_open())
        exit(0);
    while(fin>>key>>element)
        btree1.insert(key,element);
    fin.clear();
    fin.close(); 
    /*
    cout<<"前序遍历："<<endl;
    btree1.traverse(BST<int,char>::PRE);
    cout<<"中序遍历："<<endl;
    btree1.traverse(BST<int,char>::IN);
    cout<<"后序遍历："<<endl;
    btree1.traverse(BST<int,char>::POST);
    cout<<" "<<btree1.height()<<endl;

    btree1.traverse(BST<int,int>::PRE);
    cout<<endl;
    btree1.traverse(BST<int,int>::IN);
    cout<<endl;
    btree1.traverse(BST<int,int>::POST);
    */
    char character;
    int weight;
    HuffTree<char> keep;
    Heap<HuffTree<int> > _source;
    Heap<HuffTree<char>> source;
    while(fin>>character>>weight){
        keep.setRoot(HuffTree<char>(character,weight).removeRoot());
        source.insert(keep);
    }
    HuffTree<char> hufftree(source); 
    system("pause");
    
}