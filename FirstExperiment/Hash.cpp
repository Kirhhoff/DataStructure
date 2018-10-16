#include"Hash.h"

string Hash::hashLirary="qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM0123456789";
string Hash::generate(int hashLength){
    string generatedString="";
    hashLirary="qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM0123456789";
    int len=hashLirary.length();
    //Generate specified length hash code
    for(int i=0;i<hashLength;i++)
        generatedString+=hashLirary.at(rand()%hashLirary.length());
    return generatedString;
}