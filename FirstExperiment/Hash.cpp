#include"Hash.h"

string Hash::hashLirary="qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM0123456789";
string Hash::generate(int hashLength){
    string generatedString="";
    
    //In case the static hashLibrary hasn't been initialized.
    hashLirary="qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM0123456789";

    //Generate hash code of specified length 
    for(int i=0;i<hashLength;i++)
        generatedString+=hashLirary.at(rand()%hashLirary.length());
    return generatedString;
}