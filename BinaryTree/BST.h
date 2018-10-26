#ifndef BST_H
#define BST_H
#include"Exception.h"
#include"BSTNode.h"
#include"AStack.h"
template<class Key,class E>
class BST{
    //define traversal order
    public:
        enum TraversalOrder{
            PRE,//preorder traversal
            IN,//inorder traversal
            POST//postorder traversal
        };
    
    
    //define the alias of the node
    private:
        typedef BSTNode<Key,E> Node;
    
    //private members
    private:
        Node* root;
        int nodeCount;
    
    public:
        BST():root(0),nodeCount(0){}
        virtual ~BST(){}

    //private helpers
    //At the beginning I am confused why I need these helpers.
    //But late I realize these helpers seperate the recursion part
    //from the one whole operation, which makes logic more clear
    //and decreases the degree of coupling.
    private:
        Node* insertHelper(Node* subroot,const Key& k,const E& element);
        Node* findHelper(Node* subroot,const Key& k)const;
        Node* removeHelper(Node* subroot,const Key& k);
        Node* getMin(Node* subroot)const;
        void preorderPush(Node* itr,AStack<Node*>& realStack,AStack<Node*>& tmpStack);
        void inorderPush(Node* itr,AStack<Node*>& realStack,AStack<Node*>& tmpStack);
        void postorderPush(Node* itr,AStack<Node*>& realStack,AStack<Node*>& tmpStack);

    //public methods
    public:
        void insert(const Key& k,const E& element);
        E remove(const Key& k)throw(Exception);
        void traverse(TraversalOrder order);
};
#endif