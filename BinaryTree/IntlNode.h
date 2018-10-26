#ifndef INTLNODE_H
#define INTLNODE_H
#include"VarBinNode.h"
#include<iostream>

template<class Operator>
class IntlNode:public VarBinNode<Operator>{
    private:
        Operator opx;
        VarBinNode<Operator>* leftChild;
        VarBinNode<Operator>* rightChild;
    
    public:
        IntlNode(const Operator& _opx):opx(_opx){}
    
    public:
        virtual bool isLeaf(){return true;}
        Operator value(){return opx;}
        VarBinNode<Operator>* left(){return leftChild;}
        VarBinNode<Operator>* right(){return rightChild;}
        
        virtual void traverse(){
            left->traverse();
            std::cout<<value();
            right->traverse();
        }
};
#endif