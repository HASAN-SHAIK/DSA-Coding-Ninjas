/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
	{{2, 1, 4},	// Length of this subset is 2
	{2, 3, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/
#include<vector>
#include<iostream>
using namespace std;
void getSubsets(int input[], int n, int k,vector<int> subset, vector<vector<int>> &ans,int index){
	if(k<0){
	return;
	}
	if(k==0){
		// cout<<"Came\n";
		ans.push_back(subset);
		for(int i=0;i<subset.size();i++)
		// cout<<subset[i]<<" ";
		return;
	}
	if(index==n){
	return;
	}
	subset.push_back(input[index]);
	// cout<<input[index]<<" "<<k-input[index]<<"\n";
	getSubsets(input, n, k-input[index], subset, ans, index+1);
	subset.pop_back();
	getSubsets(input,n,k,subset,ans,index+1);
	
	return;
}

int subsetSumToK(int input[], int n, int output[][50], int k) {
    // Write your code here
	vector<vector<int>> ans;
	vector<int> subset;
	getSubsets(input, n, k, subset,ans,0);
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			cout<<ans[i][j]<<" ";
			// output[i][j] = ans[i][j];
		}
		cout<<endl;
	}
	return ans.size();
}
