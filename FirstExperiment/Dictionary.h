

#include"LList.h"
#include"KVpair.h"
template<class Key,class Value>
class LLDictionary{
    LList<KVpair<Key,Value>> pairList;
    bool find(Key key,Value& value){
        pairList.moveToStart();
        while(!pairList.atEnd()){
            if(pairList.getKey()==key){
                value=pairList.getValue();
                return true;
            }
            pairList.next();
        }
    }

    void insert(Value& value){
        pairList.sortedInsert(value);
    }
};