#include "PriorityQueue.h"
#include<iostream>
using namespace std;
int main(){


     priorityQueue pq;

    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insertMin(element);
                break;
            case 2:  // getMin
                cout << pq.getMin() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMin() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return 0;
        }

        cin >> choice;
    }
    // priorityQueue p;
    // int data;
    // cout<<"Enter the data\n";
    // cin>>data;
    // while(data!=-1){
    //     p.insertMin(data);
    //     cout<<"Enter the data\n";
    //     cin>>data;
    // }
    // p.removeMin();
    // cout<<p.getMin()<<endl;
    // cout<<p.getSize()<<endl;
    // p.removeMin();
    // cout<<p.getMin()<<endl;
    // cout<<p.getSize()<<endl;
}


