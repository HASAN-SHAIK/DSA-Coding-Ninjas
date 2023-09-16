template <typename T>
class QueueUsingArray{
    T *queue;
    int firstIdx;
    int nextIdx ;
    int size;
    int capacity;
    public:
    QueueUsingArray(int x){
        capacity=x;
        queue = new T[x];
        firstIdx=-1;
        nextIdx =0;
        size=0;
    }
    void enqueue(int element){
        if(firstIdx==-1){
            queue[++firstIdx]=element;
            nextIdx++;
        }
        else if(nextIdx==firstIdx){
        cout<<"Queue is Full"<<endl;
        return;
        }
        else{
            queue[nextIdx++]=element;
        }
        if(nextIdx==capacity)
        nextIdx=0;
        size++;
    }
    T dequeue(){
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
        cout<<"Queue is Empty"<<endl;
        else{
            firstIdx=0;
        }
    }
    int front(){
        return queue[firstIdx];
    }
    int getSize(){
        return size;
    }
    int isEmpty(){
        return size;
    }
};