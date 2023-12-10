bool isMaxHeap(int arr[], int n) {
    // Write your code here
    for(int i=0;i<=(n-2)/2;i++){
        int parenIdx = i;
        int child1 = 2*parenIdx+1;
        int child2 = 2*parenIdx+2;
        if(child2<n){
            if(arr[parenIdx]<arr[child2]||arr[parenIdx]<arr[child2])
            return false;
        }
        else{
            if(arr[parenIdx]<arr[child2])
            return false;
        }
    }
    return true;
}