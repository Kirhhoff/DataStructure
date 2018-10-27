#ifndef BINNODE_H
#define BINNODE_H
template<class E>
class BinNode{
    //Public constructors and destructors
    public:
        virtual ~BinNode(){}

    public:
        //Get the element within the BinNode
        virtual E& element()=0;
         
        //Set the element within the BinNode
        virtual void setElement(const E&)=0;

        //Set the left child of the BinNode
        virtual void setLeft(BinNode*)=0;

        //Get the left child of the BinNode
        virtual BinNode* left() const =0;

        //Set the right child of the BinNode
        virtual void setRight(BinNode*)=0;

        //Get the right child of the BinNode
        virtual BinNode* right() const =0;

        //Judge if the BinNode is a leaf
        virtual bool isLeaf() const =0;

};
#endif