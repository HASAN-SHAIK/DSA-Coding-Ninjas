#include<queue>
#include<vector>
using namespace std;
vector<int> kSmallest(int arr[], int n, int k) {
    // Write your code here
    vector<int> ans;
    priority_queue<int> pq;
    for(int i=0;i<k;i++)
    pq.push(arr[i]);
    for(int i=k;i<n;i++){
        if(arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    for(int i=0;i<k;i++){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}