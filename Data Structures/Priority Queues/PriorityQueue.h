#include<vector>
#include<limits.h>
using namespace std;
class priorityQueue{
    vector<int> pq;
    public:
    priorityQueue(){

    }
    bool isEmpty(){
        return pq.size()==0;
    }
    int getSize(){
        return pq.size();
    }
    int getMin(){
        if(isEmpty())
        return -1;
        return pq[0];
    }
    void swap(int parentIdx,int childIdx){
        int temp = pq[parentIdx];
        pq[parentIdx] = pq[childIdx];
        pq[childIdx]=temp;
    }
    void upHeapify(){
        //compare child with parent if parent is greater swap. Continue until parent is less that child
        int childIdx = pq.size()-1;
        int parentIdx = (childIdx-1)/2;
        while(parentIdx>=0&&pq[parentIdx]>pq[childIdx]){
            swap(parentIdx,childIdx);
            childIdx = parentIdx;
            parentIdx = (childIdx -1)/2;
        }
    }
    void insertMin(int data){
        //insert at last Index
        pq.push_back(data);
        //UpHeapify
        upHeapify();
    }
   void DownHeapify(int parentIdx){
        do{
        if(pq.size()<=2*parentIdx+1) return;
        int child1 = (pq.size()>2*parentIdx+1)? pq[2*parentIdx+1]:INT_MAX;
        int child2 = (pq.size()>2*parentIdx+2)? pq[2*parentIdx+2]:INT_MAX;
        int minIdx = child1>child2?2*parentIdx+2:2*parentIdx+1;
        if(pq[minIdx]<pq[parentIdx])
        swap(parentIdx,minIdx);
        else
        return;
        parentIdx = minIdx;
        }while(1);
    }

    int removeMin() {
        if(isEmpty())
        return -1;
        int ans = pq[0];
        swap(0,pq.size()-1);
        pq.pop_back();
        DownHeapify(0);
        return ans;
    }
};