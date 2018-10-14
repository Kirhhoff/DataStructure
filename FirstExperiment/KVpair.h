

template<class Key,class Value>
class KVpair{
    private:
        Key key;
        Value value;
    
    public:
        Value getValue(){return value;}
        friend bool operator<(const KVpair& kvpair1,const KVpair& kvpair2);
};