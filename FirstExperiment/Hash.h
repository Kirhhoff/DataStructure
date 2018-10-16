#ifndef HASH_H
#define HASH_H

#include<string>
#include<stdlib.h>
using std::string;


class Hash{
    private:
        static string hashLirary;//all characters that may turn up in generated hash code
    public:
        static string generate(int hashLength);
};

#endif