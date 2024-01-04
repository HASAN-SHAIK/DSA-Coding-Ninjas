#include<iostream>
using namespace std;
void swap(int *arr,int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void Insert(int *arr,int childIdx){
     if(childIdx==0)
    return;
    int parentIdx = (childIdx-1)/2;
    if(arr[parentIdx]<arr[childIdx])
    return;
    swap(arr,parentIdx,childIdx);
    Insert(arr, parentIdx);
}

void DownHeap(int *arr,int parentIdx,int size){
    int child1 = 2*parentIdx+1;
    int child2 = child1+1;
    if(child1>=size)
    return;
     int minIdx;
    if(child2<size){
        if(arr[parentIdx]<arr[child2]&&arr[parentIdx]<arr[child1])
        return;
        minIdx = arr[child1]>arr[child2]?child2:child1;
        swap(arr, minIdx, parentIdx);
    }
    else if(arr[parentIdx]>arr[child1]){
        minIdx = child1;
        swap(arr, child1, parentIdx);
    }
    DownHeap(arr, minIdx, size);
}



void heapSort(int arr[], int n) {
    //Insert Elements from index 1 and check cbt and Heap property
    for(int i=1;i<n;i++){
        Insert(arr,i);
    }
    //Swap the first and last index and check Heap property from top to lastindex-i
    for(int i=0;i<n-1;i++){
        swap(arr,0,n-i-1);
        DownHeap(arr,0,n-i-1);
    }
}

