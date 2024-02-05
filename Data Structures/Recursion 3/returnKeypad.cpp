#include <string>
#include<unordered_map>
#include<iostream>
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
#include<limits.h>
int keypad(int num, string output[]) {
  if (num % 10 == 0 || num % 10 == 1) {
    output[0]="";
    return 1;
    }
    int x= num%10;
    int size = keypad(num/10, output);
    string temp[100000];
    copy(output,output+size,temp);
    for(int i=0;i<m[x].length();i++){
        for(int j=0;j<size;j++){
            output[(i*size)+j] =  temp[j]+m[x][i] ;
        }
    }
    return size*m[x].length();
}
