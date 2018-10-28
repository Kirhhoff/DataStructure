#ifndef HUFFTREE_H
#define HUFFTREE_H
#include"HuffNode.h"
#include"Heap.h"
template<class E>
class HuffTree{
    private:
        HuffNode<E>* root;
    
    public:
        HuffTree():root(0){}
        HuffTree(const E& element,int weight)
            :root(new LeafNode<E>(element,weight)){}
        HuffTree(HuffTree leftTree,HuffTree rightTree) 
            :root(new IntlNode<E>(leftTree.getRoot(),rightTree.getRoot())){}
        HuffTree(Heap<HuffTree<E>> source);
        ~HuffTree(){delete root;}

    private:
        bool huffCodeHelper(HuffNode<E>* subroot,const E& element,std::string& result) throw(Exception);
    public:
        HuffNode<E>* removeRoot(){
            HuffNode<E>* tmp=root;
            root=0;
            return tmp;
        }
        void setRoot(HuffNode<E>* _root){root=_root;}
        std::string huffCode(const E& element) const{
            std::string result;
            huffCodeHelper(root,element,result);
            return result;
        };
        void merge(HuffTree huffTree){root=new IntlNode<E>(root,huffTree.getRoot());}
};
#endif