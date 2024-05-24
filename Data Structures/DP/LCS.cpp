#include<bits/stdc++.h>
using namespace std;

int LeastCommonSubSequence(string s1, string s2){
    if(s1.length()==0||s2.length()==0)
        return 0;
    if(s1[0]==s2[0])
        return 1+LeastCommonSubSequence(s1.substr(1),s2.substr(1));
    int a = LeastCommonSubSequence(s1.substr(1),s2);
    int b = LeastCommonSubSequence(s1,s2.substr(1));
    return max(a,b);
}

int main(){
    cout<<LeastCommonSubSequence("hasan","sushanth");
    cout<<LeastCommonSubSequence("hasan","punnaakash");
}
