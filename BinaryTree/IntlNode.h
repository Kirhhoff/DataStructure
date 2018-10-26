#ifndef INTLNODE_H
#define INTLNODE_H
#include"VarBinNode.h"
#include<iostream>

template<class Operator>
class IntlNode:public VarBinNode<Operator>{
    private:
        Operator opx;
        VarBinNode<Operator>* left;
        VarBinNode<Operator>* right;
    
    public:
        IntlNode(const Operator& _opx):opx(_opx){}
    
    public:
        virtual bool isLeaf(){return true;}
        Operator value(){return opx;}
        VarBinNode<Operator>* leftChild(){return left;}
        VarBinNode<Operator>* rightChild(){return right;}
        
        virtual void traverse(){
            left->traverse();
            std::cout<<value();
            right->traverse();
        }
};
#endif