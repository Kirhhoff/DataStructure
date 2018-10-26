#ifndef EXCEPTION_H
#define EXCEPTION_H
#include<string>
#include<iostream>
class Exception{
    protected:
        std::string msg;
    public:
        Exception(std::string errorMsg):msg(errorMsg){}
    public:
        void printMsg(){std::cerr<<msg<<std::endl;}
};
#endif