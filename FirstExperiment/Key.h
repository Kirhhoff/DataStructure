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
		explicit operator string()const{return hash;}/*     As Key is in a way just a wrapper of string
                                                        only to make it automatically assigned a hash value.
                                                        So under some circumstance,may it is required to cast 
                                                        it directly to a string value.
                                                            But in case this function is wrongly called,I describe
                                                        it with a explicit key word.
                                                    */
	
    //Opearator Reloading
    friend ostream& operator<<(ostream& out,const Key& key);
    friend ifstream& operator>>(ifstream& fin,Key& key);
    bool operator==(const Key& key){return hash==key.hash;}
};

#endif
