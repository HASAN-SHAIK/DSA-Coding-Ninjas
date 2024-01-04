#include<queue>
#include <utility>
int buyTicket(int *arr, int n, int k) {
    priority_queue<int>  pq;
    queue<int> q;
    int time=0;

    int val = arr[k];
    for(int i=0;i<n;i++){
      pq.push(arr[i]);
      q.push(arr[i]);
    }
    while(!q.empty()){
        if(pq.top()==q.front())
        {
            if(k==0)
            return time+1;
            q.pop();
            pq.pop();
            time++;
            k--;
        }
        else{
            int temp=q.front();
            q.pop();
            q.push(temp);
            k--;
            if(k==-1)
            k=q.size()-1;
            // for(int i=0;i<q.size();i+)
        }
    }
}