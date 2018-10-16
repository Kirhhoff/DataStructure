#include"Car.h"
#include"Key.h"
#include"KVpair.h"
#include"config.h"
#include<iomanip>

bool operator<(const KVpair<Key,Car>& kvpair1,const KVpair<Key,Car>& kvpair2){return kvpair1.getValue()<kvpair2.getValue();}
ostream& operator<<(ostream& out,const KVpair<Key,Car>& kvpair){
    out <<std::right
        <<std::setw(HASH_WIDTH)<<kvpair.getKey()
        <<kvpair.getValue();
    return out;
}
ofstream& operator<<(ofstream& fout,const KVpair<Key,Car>& kvpair){
    fout<<std::right
        <<std::setw(HASH_WIDTH)<<kvpair.getKey()
        <<kvpair.getValue();
    return fout;
}
ifstream& operator>>(ifstream& fin,KVpair<Key,Car>& kvpair){
    Key key;
    Car car;
    fin>>key>>car;
    kvpair.setKey(key);
    kvpair.setValue(car);
    return fin;
}