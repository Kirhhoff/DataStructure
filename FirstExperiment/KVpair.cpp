#include"KVpair.h"
#include"Car.h"
#include"config.h"

//bool opearator<(const KVpair<key,Car>& kvpair1,const KVpair<key,Car>& kvpair2){return kvpair1.getValue(). }

bool operator<(const KVpair<key,Car>& kvpair1,const KVpair<key,Car>& kvpair2){return kvpair1.getValue()<kvpair2.getValue();}