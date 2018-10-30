#ifndef HUFFTREE_H
#define HUFFTREE_H
#include"HuffNode.h"
#include"Comp.cpp"
#include"Heap.cpp"
#include<iostream>
template<class E>
class HuffTree{
    private:
        HuffNode<E>* root;
    
    public:
        HuffTree():root(0){}
        HuffTree(const E& element,int weight)
            :root(new LeafNode<E>(element,weight)){}
        HuffTree(HuffTree& leftTree,HuffTree& rightTree) 
            :root(new IntlNode<E>(leftTree.getRoot(),rightTree.getRoot())){}
        HuffTree(Heap<HuffTree<E>*,MinHeapComp>& source);//Generate a hufftree from a Minheap
        ~HuffTree(){if(root) delete root;}

    private:
        //Recursively generate the Huffman code of the element,though it is reversed.
        bool huffCodeHelper(HuffNode<E>* subroot,const E& element,std::string& reverse) const;
    public:
        //Get the weight of the tree's root node.
        int weight()const{return root->weight();}
        
        //Plunder the root of this HuffTree
        HuffNode<E>* removeRoot(){
            HuffNode<E>* tmp=root;
            root=0;
            return tmp;
        }
        void setRoot(HuffNode<E>* _root){root=_root;}//Set the root

        //Get the huff Code of a specified element
        std::string huffCode(const E& element)const;/*  This function first create two string variables to 
                                                    accommodate the result,one of which is named "reverse",
                                                    the other of which is named "result". First call a recursive
                                                    function to get the "element" 's huffman code,however is 
                                                    reversed.And "reverse" is used to adopt it.(This is where its
                                                    name come from.)And it will be reversed in character to set
                                                    the "result".After that return "result".
                                                    */

        //Merge a HuffTree to generate a new HuffTree
        //This will destroy the HuffTree argument transmitted to the function.
        HuffTree* merge(HuffTree* huffTree){
            root=new IntlNode<E>(root,huffTree->removeRoot());
            delete huffTree;
            return this;
        }
        void printWeights(){printHelper(root);}
        void printHelper(HuffNode<E>* subroot){
            if(subroot->isLeaf())
                std::cout<<static_cast<LeafNode<E>*>(subroot)->value()<<":"<<static_cast<LeafNode<E>*>(subroot)->weight()<<std::endl;
            else{
                std::cout<<static_cast<IntlNode<E>*>(subroot)->weight()<<std::endl;
                printHelper(static_cast<IntlNode<E>*>(subroot)->left());
                printHelper(static_cast<IntlNode<E>*>(subroot)->right());
            }
        }
};
#endif