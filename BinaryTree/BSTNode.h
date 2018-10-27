#ifndef BSTNODE_H
#define BSTNODE_H
#include"BinNode.h"

template<class Key,class E>
class BSTNode:public BinNode<E>{
    private:
        Key k;
        E it;
        BSTNode* leftChild;
        BSTNode* rightChild;

    public:
        BSTNode(){left=right=0;}
        BSTNode(Key _k,E _it,BSTNode* _leftChild=0,BSTNode* _rightChild=0)
            :k(_k),it(_it),leftChild(_leftChild),rightChild(_rightChild){}
        ~BSTNode(){}

    public:
        //Get the element within the BinNode
        virtual E& element(){return it;}
         
        //Set the element within the BinNode
        virtual void setElement(const E& element){it=element;}

        //Set the left child of the BinNode
        virtual void setLeft(BinNode<E>* _leftChild){leftChild=dynamic_cast<BSTNode*>(_leftChild);}

        //Get the left child of the BinNode
        virtual BSTNode* left() const{return leftChild;}

        //Set the right child of the BinNode
        virtual void setRight(BinNode<E>* _rightChild){rightChild=dynamic_cast<BSTNode*>(_rightChild);}

        //Get the right child of the BinNode
        virtual BSTNode* right() const{return rightChild;}

        //Judge if the BinNode is a leaf
        virtual bool isLeaf() const{return !leftChild*!rightChild;}

        //Get the key of the node
        virtual Key& key(){return k;}

        //Set the key of the node
        virtual void setKey(const Key& _k){k=_k;}

};
#endif