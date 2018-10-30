#ifndef HUFFTREE_CPP
#define HUFFTREE_CPP
#include"HuffTree.h"
#include<assert.h>
#include<iostream>
using namespace std;
template<class E>
HuffTree<E>::HuffTree(Heap<HuffTree<E>*,MinHeapComp>& source){
    //Check if the heap is empty
    assert(!source.isEmpty());

    //When there are at least two HuffTree in the heap,continue merging
    while(source.size()>1)
        source.insert(source.removeFirst()->merge(source.removeFirst()));

    //Get the final one merged Hufftree
    HuffTree* result=source.removeFirst();
    root=result->removeRoot();
    delete result;
}

template<class E>
string HuffTree<E>::huffCode(const E& element)const{
    std::string reverse,result;/*   "reverse" accommodates the string transmitted from function huffCodeHelper.
                                "result" accommodates the reversed "reverse",that the true result.
                                */
    huffCodeHelper(root,element,reverse);//recursive function
    result=reverse;
    for(int i=0;i<reverse.length();i++)//reverse "reverse"
        result[reverse.length()-i-1]=reverse[i];
    return result;
}

template<class E>
bool HuffTree<E>::huffCodeHelper(HuffNode<E>* subroot,const E& element,string& result) const{
    if(subroot->isLeaf())
        return (static_cast<LeafNode<E>*>(subroot)->value())==element;/*    At this moment,the result is still empty
                                                                        and if it equals the element,just return true,
                                                                        and begin appending '0' or '1' to the result.
                                                                        If it doesn't,this indicates this branch is not 
                                                                        where the element is located. and it will return 
                                                                        false,the result still remain empty.
                                                                    */
    //When the program runs to here,it means this subroot is a internal node.
    //So just continue recursion.
    IntlNode<E>* internal=static_cast<IntlNode<E>*>(subroot);
    if(huffCodeHelper(internal->left(),element,result))
        result+='0';
    else if(huffCodeHelper(internal->right(),element,result))
        result+='1';
    else return false;
    return true;
}
#endif

