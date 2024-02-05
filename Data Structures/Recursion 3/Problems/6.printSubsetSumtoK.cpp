#include<vector>
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

void printSubsetSumToK(int input[], int n, int k) {
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
	return;
}



