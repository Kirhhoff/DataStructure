template<class Key,class Value>
class KVpair{
    private:
        Key key;
        Value value;
    
    public:
        Key getKey()const{return key;}
        Value getValue()const{return value;}
};