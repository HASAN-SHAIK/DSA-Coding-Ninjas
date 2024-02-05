#include<iostream>
#include<string>
using namespace std;
int getSubsequences(string str,string output[]){
    if(str.size()==0){
    output[0] ="";
    return 1;
    }
    int size = getSubsequences(str.substr(1),output);
    for(int i=0;i<size;i++){
        output[i+size] = str[0] + output[i];
    }
    return 2*size;
}
int main(){
    string str="abc";
    string *output = new string[1000];
    int size = getSubsequences(str,output);
    for(int i=0;i<size;i++)
    cout<<output[i]<<endl;
}
