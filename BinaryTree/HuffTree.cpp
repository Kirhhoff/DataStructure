#include"HuffTree.h"
#include<assert.h>
using namespace std;
template<class E>
HuffTree<E>::HuffTree(Heap<HuffTree<E>> source){
    assert(!source.isEmpty());
    while(source.size()>1)
        source.insert(source.removeFirst().merge(source.removeFirst()));
    root=source.removeFirst().getRoot();
}

template<class E>
bool HuffTree<E>::huffCodeHelper(HuffNode<E>* subroot,const E& element,string& result) throw(Exception){
    if(subroot->isLeaf())
        return (static_cast<LeafNode<E>*>(subroot)->weight())==element;;
    IntlNode<E>* internal=static_cast<IntlNode<E>*>(subroot);
    if(huffCodeHelper(internal->left(),element,result))
        result+='0';
    else if(huffCodeHelper(internal->right(),element,result))
        result+='1';
    else return false;
    return true;
}


