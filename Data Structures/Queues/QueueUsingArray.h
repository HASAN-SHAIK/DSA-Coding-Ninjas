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
        this->size=0;
    }
    int enqueue(int element){
        if(size==capacity)
        return 0;
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
