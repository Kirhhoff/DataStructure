#include"BST.h"
#include"AStack.h"
#include<iostream>
using namespace std;
template<class Key,class E>
typename BST<Key,E>::Node* BST<Key,E>::insertHelper(Node* subroot,const Key& k,const E& element){
    //Actually this statement is the only valid insertion, while later statements are in fact
    //executing recursion.
    if(!subroot) return subroot=new Node(k,element);

    //Here when the inserted element equals the value of the subroot, we actually do nothing,
    //as here is no redundancy.
    if(k<subroot->key())
        subroot->setLeft(insertHelper(subroot->left(),k,element));
    else if(k>subroot->key())
        subroot->setRight(insertHelper(subroot->right(),k,element));
    return subroot;
}

template<class Key,class E>
void BST<Key,E>::insert(const Key& k,const E& element){
    //Though the assignment is significant only when the first element is inserted,it is necessary.
    root=insertHelper(root,k,element);
    nodeCount++;
}

template<class Key,class E>
typename BST<Key,E>::Node* BST<Key,E>::findHelper(Node* subroot,const Key& k)const{
    if(!subroot) return 0;
    if(subroot->key()==k) return subroot;
    Node *result=findHelper(subroot->left(),k);
    if(result) return result;
    else findHelper(subroot->right(),k);
}

template<class Key,class E>
typename BST<Key,E>::Node* BST<Key,E>::getMin(Node* subroot)const{
    if(subroot->left()) return getMin(subroot->left());
    else return subroot;
}

template<class Key,class E>
typename BST<Key,E>::Node* BST<Key,E>::removeHelper(Node* subroot,const Key& k){
    //If this is an empty subtree,directly return 0
    if(!subroot) return 0;
    
    //If the key of this subroot doesn't equal k,find among its left and right
    //child node,after which updata them.
    if(subroot->key()!=k){
        subroot->setLeft(removeHelper(subroot->left(),k));
        subroot->setRight(removeHelper(subroot->right(),k));
        return subroot;
    }

    /*If the key of this subroot equals k, let's manage to remove it. */
    
    //Directly delete it if it is a leaf
    if(subroot->isLeaf()) {
        delete subroot;
        return 0;
    }

    //If right child node doesn't exist,we can directly replace this
    //node with it left child node.
    if(!subroot->right()){
        Node* leftOfRemovedNode=subroot->left();
        delete subroot;
        return leftOfRemovedNode;
    }else{
        //If right child node exists,replace this node with the minimum node
        //of its right subtree.
        Key newSubrootKey;
        Node* minOfRightSubtree=getMin(subroot->right());//get the minimum node of left subtree
        subroot->setKey(newSubrootKey=minOfRightSubtree->key());//replace the key
        subroot->setElement(minOfRightSubtree->element());//replace the element
        subroot->setRight(removeHelper(subroot->right(),newSubrootKey));//reset the right child node
        return subroot;
    }
}

template<class Key,class E>
E BST<Key,E>::remove(const Key& k)throw(Exception){
    Node* result;
    if(result=findHelper(root,k)){
        E removedElement=result->element();
        root=removeHelper(root,k);
        nodeCount--;
        return removedElement;
    }else throw Exception("Fail to find.");
}

template<class Key,class E>
void BST<Key,E>::preorderPush(Node* itr,AStack<Node*>& realStack,AStack<Node*>& tmpStack){
    while(itr){
        while(itr){
            tmpStack.push(itr);
            realStack.push(itr);
            itr=itr->left();
        }
        while(!realStack.isEmpty()&&!((itr=realStack.pop())->right()));
        itr=itr->right();
    }
}

template<class Key,class E>
void BST<Key,E>::inorderPush(Node* itr,AStack<Node*>& realStack,AStack<Node*>& tmpStack){
    while(itr||!realStack.isEmpty()){
        while(itr){
            realStack.push(itr);
            itr=itr->left();
        }
        tmpStack.push(itr=realStack.pop());
        while(!itr->right()&&!realStack.isEmpty())
            tmpStack.push(itr=realStack.pop());
        itr=itr->right();  
    }
}

template<class Key,class E>
void BST<Key,E>::postorderPush(Node* itr,AStack<Node*>& realStack,AStack<Node*>& tmpStack){
     while(itr){
        while(itr){
            realStack.push(itr);
            itr=itr->left();
        }
        while(!realStack.isEmpty()&&!((itr=realStack.topValue())->right())){
            tmpStack.push(realStack.pop());
            while(!realStack.isEmpty()&&((realStack.topValue()->right())==itr))
                tmpStack.push(itr=realStack.pop());
        }
        if(realStack.isEmpty())
            break;
        itr=itr->right();
    }
}
template<class Key,class E>
void BST<Key,E>::traverse(TraversalOrder order){
    AStack<Node*> realStack(20);
    AStack<Node*> tmpStack(20);
    BSTNode<Key,E>* itr=root;
    switch(order){
        case PRE:   preorderPush(itr,realStack,tmpStack);
            break;
        case IN:    inorderPush(itr,realStack,tmpStack);
            break;
        case POST:  postorderPush(itr,realStack,tmpStack);
            break;
    }
    while(!tmpStack.isEmpty())
        realStack.push(tmpStack.pop());
    while(!realStack.isEmpty()){ 
        itr=realStack.pop();
        cout<<itr->key()<<" : "<<itr->element()<<endl;
    }
}