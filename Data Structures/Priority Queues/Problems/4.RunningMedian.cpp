#include<queue>
void findMedian(int *arr, int n)
{
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    if(n==0)
    return;
    cout<<arr[0]<<" ";
    maxHeap.push(arr[0]);
    for (int i = 1; i < n; i++) {
        if(arr[i]<maxHeap.top())
        maxHeap.push(arr[i]);
        else
        minHeap.push(arr[i]);
        if(minHeap.size()>maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        else if(maxHeap.size()>minHeap.size()+1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if(minHeap.size()!=maxHeap.size())
        cout<<maxHeap.top()<<" ";
        else {
        int max = maxHeap.top();
        int min = minHeap.top();
        cout<<(min+max)/2<<" ";
        }
    }
}