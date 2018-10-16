#ifndef KVPAIR_H
#define KVPAIR_H

template<class Key,class Value>
class KVpair{
    private:
        Key key;
        Value value;
    
    public:
        KVpair(){}
        KVpair(Key _key,Value& _value):key(_key),value(_value){}
        KVpair(Value& _value):value(_value){}

    public:
        Key getKey()const{return key;}
        Value getValue()const{return value;}
        void setKey(const Key& _key){key=_key;}
        void setValue(const Value& _value){value=_value;}
};

#include"Key.h"
bool operator<(const KVpair<Key,Car>& kvpair1,const KVpair<Key,Car>& kvpair2);
ostream& operator<<(ostream& out,const KVpair<Key,Car>& kvpair);
ofstream& operator<<(ofstream& fout,const KVpair<Key,Car>& kvpair);
ifstream& operator>>(ifstream& fin,KVpair<Key,Car>& kvpair);

#endif