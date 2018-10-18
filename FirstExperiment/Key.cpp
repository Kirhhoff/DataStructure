#include"Key.h"

ostream& operator<<(ostream& out,const Key& key){return out<<key.hash;}
ifstream& operator>>(ifstream& fin,Key& key){fin>>key.hash;return fin;}

