#include<vector>
using namespace std;
class PriorityQueue {
    // Declare the data members here
    vector<int> pq;
   public:
    PriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        // Implement the insert() function here
        pq.push_back(element);
        int childIdx = pq.size()-1;
        while(childIdx>0){
            int parentIdx = (childIdx-1)/2;
            if(pq[parentIdx]<pq[childIdx])
            swap(parentIdx, childIdx);
            childIdx = parentIdx;
        }
    }

    int getMax() {
        // Implement the getMax() function here
        return pq[0];
    }
    void swap(int minIdx,int parentIdx){
        int temp = pq[minIdx];
        pq[minIdx] = pq[parentIdx];
        pq[parentIdx]=temp;
    }
    int removeMax() {
        // Implement the removeMax() function here
        if(pq.size()==0)
        return -1;
        int ans = pq[0];
        swap(0, pq.size()-1);
        pq.pop_back();
        int parentIdx = 0;
        while(parentIdx<pq.size()){
            int child1Idx = parentIdx*2+1;
            int child2Idx = parentIdx*2+2;
            int minIdx;
            if(child2Idx<pq.size())
            minIdx = pq[child1Idx]<pq[child2Idx]? child2Idx : child1Idx;
            else
            minIdx = child1Idx;
            if(pq[minIdx]>pq[parentIdx])
            swap(minIdx,parentIdx); 
            parentIdx = minIdx;
        } 
        return ans;
    }

    int getSize() { 
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        return pq.size()==0;
    }
};