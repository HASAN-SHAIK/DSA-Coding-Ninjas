template <typename T>
class QueueUsingDynamicArray{
    T *queue;
    int firstIdx;
    int nextIdx ;
    int size;
    int capacity;
    public:
    QueueUsingDynamicArray(int size){
        capacity=size;
        queue = new T[size];
        firstIdx=-1;
        nextIdx =0;
        this->size=0;
    }
    int enqueue(int element){
        if(size==capacity){
        T *newQueue = new T[2*capacity];
        capacity=capacity*2;
        for(int i=firstIdx,count=0;count<size;count++){
        newQueue[count]=queue[i];
        i=(i+1)%size;
        }
        queue=newQueue;
        firstIdx=0;
        nextIdx=size+1;
        queue[nextIdx++]=element;
        }
        else if(size==0){
            nextIdx++;
            firstIdx++;
            queue[firstIdx]=element;
        }
        else
        queue[nextIdx++]=element;
        nextIdx=nextIdx%capacity;
        size++;
        return 1;

    }
    int dequeue(){
        if(firstIdx==-1)
        return 0;
        firstIdx+=1;
        firstIdx=firstIdx%capacity;
        size--;
        return 1;
    }
    T getFront(){
        if(firstIdx!=-1)
        return queue[firstIdx];
        return -1;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size==0;
    }
};
