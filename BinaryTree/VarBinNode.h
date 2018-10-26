#ifndef VARBINNODE_H
#define VARBINNODE_H
template<class E>
class VarBinNode{
    virtual ~VarBinNode(){}
    virtual bool isLeaf() const=0;
    virtual void traverse() const=0;
};

#endif
