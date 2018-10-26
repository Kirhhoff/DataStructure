#ifndef BSTNODE_H
#define BSTNODE_H
#include"BinNode.h"

template<class Key,class E>
class BSTNode:virtual public BinNode<E>{
    private:
        Key key;
        E it;
        BSTNode* left;
        BSTNode* right;

    public:
        BSTNode(){left=right=0;}
        BSTNode(Key _key,E _it,BSTNode* _left,BSTNode* _right):key(_key),it(_it),left(_left),right(_right){}
        ~BSTNode(){}

    public:
        //Get the element within the BinNode
        virtual E& element(){return it;}
         
        //Set the element within the BinNode
        virtual void setElement(const E& element){it=element;}

        //Set the left child of the BinNode
        virtual void setLeft(BinNode<E>* leftChild){left=leftChild;}

        //Get the left child of the BinNode
        virtual BinNode<E>* left() const{return left;}

        //Set the right child of the BinNode
        virtual void setRight(BinNode<E>* rightChild){right=rightChild;}

        //Get the right child of the BinNode
        virtual BinNode<E>* right() const{return right;}

        //Judge if the BinNode is a leaf
        virtual bool isLeaf() const{return !left*!right;}

        //Get the key of the node
        virtual Key& key(){return key;}

        //Set the key of the node
        virtual void setKey(const Key& _key){key=_key;}
};
#endif