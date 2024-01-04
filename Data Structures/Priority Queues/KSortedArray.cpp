#include<iostream>
using namespace std;
#include<queue>

void KSortedArray(int *arr,int k,int n){
    priority_queue<int> pq;
    int idx=0;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    int max = pq.top();
    arr[idx++] = max;
    pq.pop();
    for(int i=k;i<n;i++){
        pq.push(arr[i]);
        arr[idx++]=pq.top();
        pq.pop();
    }
    while(!pq.empty()){
        arr[idx++]=pq.top();
        pq.pop();
    }
}

int main(){
    int arr[]  = {1,2,3,4,5,6},k=3;
    KSortedArray(arr,3,6);
    for(int i=0;i<6;i++)
    cout<<arr[i]<<" ";
}
