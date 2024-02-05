#include<iostream>
using namespace std;
#include <string>
#include <string.h>
#include<unordered_map>
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
int getCodes(string input, string str ="") {
    // cout<<str<<endl;
    if(input.length()==0)
    {
        cout<<str<<endl;
        return count;
    }
    string s = string(1,input[0]);
    // cout<<input[0]<<" "<<s<<" : "<<m[s]<<endl;
    getCodes(input.substr(1), str +""+ m[s]);
    s = input.substr(0,2); 
    if(m.count(s)>0&&input.length()>=2)
    getCodes(input.substr(2), str+""+ m[s]);
    return count;
}
void printAllPossibleCodes(string input) {
    getCodes(input);
}

