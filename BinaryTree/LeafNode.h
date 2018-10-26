#ifndef LEAFNODE_H
#define LEAFNODE_H
#include"VarBinNode.h"
#include<iostream>

template<class Operand>
class LeafNode:public VarBinNode<Operand>{
    private:
        Operand var;
    
    public:
        LeafNode(const Operand& _var):var(_var){}
    
    public:
        virtual bool isLeaf(){return true;}
        Operand value(){return var;}
        virtual void traverse(){std::cout<<value();}
};
#endif LEAFNODE_H