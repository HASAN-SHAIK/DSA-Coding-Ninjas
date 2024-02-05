/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 2}, then output should contain 
	{{0}, 		// Length of this subset is 0
	{1, 2},		// Length of this subset is 1
	{1, 1},		// Length of this subset is also 1
	{2, 1, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/
#include<vector>
using namespace std;
void getSubsets(int input[],int n, vector<vector<int>> &ans,vector<int> sub,int index=0){
	if(index==n){
	return;
	}
	sub.push_back(input[index]);
	ans.push_back(sub);
	getSubsets(input,n,ans,sub,index+1);
	sub.pop_back();
	getSubsets(input,n,ans,sub,index+1);
}

int subset(int input[], int n, int output[][20]) {
    // Write your code here
	vector<vector<int>> subsets;
	getSubsets(input,n,subsets,{});
	for(int i=0;i<subsets.size();i++){
		for(int j=0;j<subsets[i].size();j++){
			output[i][j] = subsets[i][j];
			cout<<output[i][j]<<" ";
		}
		cout<<endl;
		// if(subsets[i].size()!=0)
		// cout<<"\n";
	}

	return subsets.size();

}
