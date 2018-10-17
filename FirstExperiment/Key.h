#ifndef KEY_H
#define KEY_H

#include<string>
#include<iostream>
#include<fstream>
#include"config.h"
#include"Hash.h"
using std::string;
using std::ostream;
using std::ofstream;
using std::ifstream;
class Key{
    private:
        string hash;
    public:
        Key(int hashLength=HASH_LENGTH)
        :hash(Hash::generate(hashLength)){}
        Key(string hashCode):hash(hashCode){}
    
	public:
		explicit operator string()const{
			return hash;
		}
	friend ostream& operator<<(ostream& out,const Key& key);
  //  friend ofstream& operator<<(ofstream& fout,const Key& key);
    friend ifstream& operator>>(ifstream& fin,Key& key);
        bool operator==(const Key& key){return hash==key.hash;}
};

#endif
