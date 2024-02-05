#include <string.h>
#include<unordered_map>
#include<iostream>
using namespace std;
unordered_map<string,char> m ={
    {"1",'a'},
    {"2",'b'},
    {"3",'c'},
    {"4",'d'},
    {"5",'e'},
    {"6",'f'},
    {"7",'g'},
    {"8",'h'},{"9",'i'},{"10",'j'},{"11",'k'},{"12",'l'},{"13",'m'},{"14",'n'},
    {"15",'o'},{"16",'p'},{"17",'q'},{"18",'r'},{"19",'s'},{"20",'t'},{"21",'u'},
    {"22",'v'},{"23",'w'},{"24",'x'},{"25",'y'},{"26",'z'}
};
int count  =0;
int getCodes(string input, string output[10000],string str ="") {
    if(input.length()==0)
    {
        output[count++] = str;
        return count;
    }
    string s = string(1,input[0]);
    getCodes(input.substr(1),output, str +""+ m[s]);
    s = input.substr(0,2); 
    if(m.count(s)>0&&input.length()>=2)
    getCodes(input.substr(2),output, str+""+ m[s]);
    return count;
}

