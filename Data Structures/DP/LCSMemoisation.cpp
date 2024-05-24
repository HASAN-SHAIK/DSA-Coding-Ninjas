#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int LeastCommonSubSequence(string s1, string s2){
    int x = s1.length(), y = s2.length();
    if(dp[x][y]!=-1)
        return dp[x][y];
    if(s1.length()==0||s2.length()==0)
        return 0;
    if(s1[0]==s2[0]){
        dp[x][y] = 1+LeastCommonSubSequence(s1.substr(1),s2.substr(1));
        return dp[x][y];
    }
    else{
    int a = LeastCommonSubSequence(s1.substr(1),s2);
    int b = LeastCommonSubSequence(s1,s2.substr(1));
    dp[x][y] = max(a,b);
    return dp[x][y];
    }
}


void LCS_dp(string s1, string s2){
    cout<<"TestCase Started...\n";
    int m = s1.length(), n= s2.length();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
            dp[i][0] = 0;
    }
    for(int i=0;i<=n;i++){
            dp[0][i] =0;
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i]==s2[j])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i][j-1],max(dp[i-1][j],dp[i-1][j-1]));
        }
    }
    cout<<dp[m][n]<<endl;
}

int main(){
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++)
            dp[i][j] = -1;
    }
    //cout<<LeastCommonSubSequence("hasan","sushanth");
    //cout<<LeastCommonSubSequence("hasan","punnaakash");
    LCS_dp("prem","hasan");
    LCS_dp("aasi","has");
}
