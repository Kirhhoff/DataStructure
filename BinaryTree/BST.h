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
        int heightHelper(Node* subroot)const;
        Node* getMin(Node* subroot)const;
        void sequentialHelper(Node* subroot)const;
        void recursiveTraveral();

        void preorderPush(Node* itr,AStack<Node*>& realStack,AStack<Node*>& tmpStack);//Generate a Stack in which Nodes are pushed in preorder
        void inorderPush(Node* itr,AStack<Node*>& realStack,AStack<Node*>& tmpStack);//Generate a Stack in which Nodes are pushed in inorder
        void postorderPush(Node* itr,AStack<Node*>& realStack,AStack<Node*>& tmpStack);//Generate a Stack in which Nodes are pushed in postorder

    //public methods
    public:
        void insert(const Key& k,const E& element);
        E remove(const Key& k)throw(Exception);
        void traverse(TraversalOrder order);/*  Here implement traversal by two stacks without
                                            recursion as I think if I want to implement three orders
                                            of traveral at the same time, it is better to implement it
                                            in BST rather than in BSTNode.
                                            */
        void sequential() const; 
        int height() const{return heightHelper(root);}    
        void printFive();                              
};
#endif