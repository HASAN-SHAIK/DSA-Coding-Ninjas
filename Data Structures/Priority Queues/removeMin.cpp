#include <vector>
using namespace std;
class PriorityQueue {
    vector<int> pq;
   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }
    void swap(int parentIdx,int childIdx){
        int temp = pq[parentIdx];
        pq[parentIdx] = pq[childIdx];
        pq[childIdx]=temp;
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