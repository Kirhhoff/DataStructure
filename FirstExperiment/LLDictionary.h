#ifndef LLDICTIONARY_H
#define LLDICTIONARY_H

#include"LList.h"
#include"KVpair.h"
template<class Key,class Value>
class LLDictionary{ 
    private:
        LList<KVpair<Key,Value>> pairList;
    
    public:
        LLDictionary(){}
        ~LLDictionary(){}
    
    public:
        bool find(Key key,Value& value){
            pairList.moveToStart();
            while(!pairList.atEnd()){
                if(pairList.getValue().getKey()==key){
                    value=pairList.getValue().getValue();
                    return true;
                }
                pairList.next();
            }
        }

        void insert(Value& value){
            pairList.sortedInsert(KVpair<Key,Value>(value));
        }

        void insert(KVpair<Key,Value> kvpair){
            pairList.sortedInsert(kvpair);
        }
        
        bool remove(Key key){
            Value uselessObject;
            if(find(key,uselessObject)){
                pairList.remove();
                return true;
            }
            return false;
        }

        void remove(){pairList.remove();}
        LList<KVpair<Key,Value>>& getPairList(){return pairList;}
};

#endif