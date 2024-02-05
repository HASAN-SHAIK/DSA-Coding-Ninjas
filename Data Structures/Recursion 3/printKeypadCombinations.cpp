#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
unordered_map<int, string> m= {
  {2 , "abc"},
  {3 , "def"},
  {4 , "ghi"},
  {5 , "jkl"},
  {6 , "mno"},
  {7 , "pqrs"},
  {8 , "tuv"},
  {9 , "wxyz"}
};
void printStrings(int num,string output){
    if(num==0){
        cout<<output<<endl;
        return;
    }
    int x = num%10;
    for(int i=0;i<m[x].length();i++){
        printStrings(num/10, m[x][i]+output);
    }
}

void printKeypad(int num){
    string output="";
    printStrings(num,output);
}
