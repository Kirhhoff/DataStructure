#ifndef HUFFNODE_H
#define HUFFNODE_H

template<class E>
class HuffNode{
    public:
        virtual ~HuffNode(){}
    public:
        virtual int weight()const=0;
        virtual bool isLeaf() const=0; 
};

template<class E>
class LeafNode: public HuffNode<E>{
    private:
        E it;
        int wgt;
    
    public:
        LeafNode(const E& _it,int _wgt):it(_it),wgt(_wgt){}
        virtual ~LeafNode(){}

    public:
        virtual int weight()const{return wgt;}
        E value(){return it;}
        virtual bool isLeaf() const{return true;} 
};

template<class E>
class IntlNode: public HuffNode<E>{
    private:
        HuffNode<E>* leftChild;
        HuffNode<E>* rightChild;
        int wgt;

    public:
        IntlNode(HuffNode<E>* _leftChild,HuffNode<E>* _rightChild)
            :leftChild(_leftChild),rightChild(_rightChild),wgt(leftChild->weight()+rightChild->weight()){}
        virtual ~IntlNode(){
            delete leftChild;
            delete rightChild;
        }
        
    public:
        virtual int weight()const{return wgt;}
        virtual bool isLeaf() const{return false;}
        HuffNode<E>* left(){return leftChild;}
        HuffNode<E>* right(){return rightChild;}
        void setLeft(HuffNode<E>* _leftChild){leftChild=_leftChild;}
        void setRight(HuffNode<E>* _rightChild){rightChild=_rightChild;}
        
};
#endif