#include<queue>
#include<iostream>
using namespace std;
vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    // Write your code here
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<input.size();i++){
        for(int j=0;j<input[i]->size();j++)
        pq.push((*input[i])[j]);
    }
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}