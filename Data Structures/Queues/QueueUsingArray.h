template <typename T>
class QueueUsingArray{
    T *queue;
    int firstIdx;
    int nextIdx ;
    int size;
    int capacity;
    public:
    QueueUsingArray(int size){
        capacity=size;
        queue = new T[size];
        firstIdx=-1;
        nextIdx =0;
        size=0;
    }
    int enqueue(int element){
        if(firstIdx==-1){
            queue[++firstIdx]=element;
            nextIdx++;
        }
        else if(nextIdx==firstIdx)
        return 0;
        else{
            queue[nextIdx++]=element;
        }
        if(nextIdx==capacity)
        nextIdx=0;
        size++;
        return 1;
    }
    int dequeue(){
        if(firstIdx<capacity-1){
        firstIdx++;
        return queue[firstIdx-1];
        }
        else if(firstIdx==capacity-1&&nextIdx==0)
        {
            firstIdx=-1;
            nextIdx=0;
        }
        else if(firstIdx==-1)
        return 0;
        else{
            firstIdx=0;
        }
        return 1;
    }
    T front(){
        return queue[firstIdx];
    }
    int getSize(){
        return size;
    }
    int isEmpty(){
        return size;
    }
};
