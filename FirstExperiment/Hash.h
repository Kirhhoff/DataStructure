#include<string>
using std::string;


class Hash{
    private:
        static string hashLirary;//all characters that may turn up in generated hash code
    public:
        static string generate(int hashLength){
            string generatedString="";
            
            //Generate specified length hash code
            for(int i=0;i<hashLength;i++)
                generatedString+=hashLirary.at(rand()%hashLirary.length());
        }

};
string Hash::hashLirary="qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM0123456789";