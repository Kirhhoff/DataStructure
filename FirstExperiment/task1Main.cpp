#include"AList.h"
#include"LList.h"
#include<stdio.h>
#include<iostream>
using std::cout;
template<class E>
void print(AList<E>& alist){
    for(alist.moveToStart();!alist.atEnd();alist.next())
        cout<<alist.getValue()<<" ";
    cout<<"\n";
}

template<class E>
void print(LList<E>& llist){
    for(llist.moveToStart();!llist.atEnd();llist.next())
        cout<<llist.getValue()<<" ";
    cout<<"\n";
}
int main(){
    
    LList<char> llist;
    llist.insert('a');
    llist.moveToEnd();
    llist.insert('b');
    llist.moveToEnd();
    llist.insert('c');
    llist.moveToEnd();
    llist.insert('d');
    llist.moveToEnd();
    llist.insert('e');   
    print(llist);
    cout<<"length: "<<llist.length()<<"\n";
    cout<<"empty: "<<llist.isEmpty()<<"\n";
    for(llist.moveToStart();llist.getPos()!=3;llist.next());
    cout<<"third: "<<llist.getValue()<<"\n";
    for(llist.moveToStart();llist.getValue()!='a';llist.next());
    cout<<"pos of a: "<<llist.getPos()<<"\n";
    for(llist.moveToStart();llist.getPos()!=4;llist.next());
    llist.insert('f');
    print(llist);
    for(llist.moveToStart();llist.getPos()!=3;llist.next());
    llist.remove();
    print(llist);
    
    AList<char> alist;
    alist.insert('a');
    alist.moveToEnd();
    alist.insert('b');
    alist.moveToEnd();
    alist.insert('c');
    alist.moveToEnd();
    alist.insert('d');
    alist.moveToEnd();
    alist.insert('e');   
    print(alist);
    cout<<"length: "<<alist.length()<<"\n";
    cout<<"empty: "<<alist.isEmpty()<<"\n";
    for(alist.moveToStart();alist.getPos()!=3;alist.next());
    cout<<"third: "<<alist.getValue()<<"\n";
    for(alist.moveToStart();alist.getValue()!='a';alist.next());
    cout<<"pos of a: "<<alist.getPos()<<"\n";
    for(alist.moveToStart();alist.getPos()!=4;alist.next());
    alist.insert('f');
    print(alist);
    for(alist.moveToStart();alist.getPos()!=3;alist.next());
    alist.remove();
    print(alist);

}