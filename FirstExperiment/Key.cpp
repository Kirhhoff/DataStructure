#include"Key.h"

ostream& operator<<(ostream& out,const Key& key){return out<<key.hash;}
//ofstream& operator<<(ofstream& fout,const Key& key){fout<<key.hash;return fout;}
ifstream& operator>>(ifstream& fin,Key& key){fin>>key.hash;return fin;}

