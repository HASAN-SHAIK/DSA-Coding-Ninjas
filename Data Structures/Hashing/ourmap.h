#include<string>
using namespace std;
template <typename V>
class mapNode{
    public:
    string key;
    V val;
    mapNode<V>* next;

    mapNode(string key,V val){
        this->key = key;
        this->val = val;
        next = NULL;
    }
    ~mapNode(){
        delete next;
    }
};
template <typename V>
class ourmap{
   public:
    int count;
    int numBuckets;
    mapNode<V>** buckets;
    double loadFactor=0;
    ourmap(){
        count=0;
        numBuckets = 5;
        buckets = new mapNode<V>*[numBuckets];
        for(int i=0;i<numBuckets;i++)
        buckets[i]=NULL;
    }
    ~ourmap(){
        for(int i=0;i<numBuckets;i++)
        delete buckets[i];
        delete [] buckets;
    }
    private:
    void rehash(){
        mapNode<V>** temp = buckets;
        int oldBucketCount = numBuckets;
        numBuckets = 2*numBuckets;
        buckets = new mapNode<V>*[numBuckets];
        for(int i=0;i<numBuckets;i++)
        buckets[i]=NULL;
        count=0;
        for(int i=0;i<oldBucketCount;i++){
            mapNode<V>* head = temp[i];
            while(head!=NULL){
                insert(head->key,head->val);
                head=head->next;
            }
        }
        for(int i=0;i<oldBucketCount ;i++){
            delete temp[i];
        }
        delete [] temp;
    }
    int getBucketIndex(string key){
        int hashCode = 0;
        int coeff =1;
        for(int i=key.length()-1;i>=0;i--){
            hashCode+= key[i] * coeff;
            hashCode=hashCode%numBuckets;
            coeff*=37;
            coeff = coeff%numBuckets;
        }
        return hashCode%numBuckets;
    }
    public:
    int getSize(){
        return count;
    }
    double getLoadFactor(){
    return loadFactor;
    }
    void insert(string key,V val){
        int bucketIndex = getBucketIndex(key);
        mapNode<V>* head = buckets[bucketIndex];
        while (head!=NULL)
        {
            if(head->key == key){
                head->val = val;
                return;
            }
            head= head->next;
        }
        head = buckets[bucketIndex];
        mapNode<V>* node =  new mapNode<V>(key,val);
        node->next = head;
        buckets[bucketIndex] = node;
        count++;
        loadFactor = (0.1*count)/numBuckets;
        if(loadFactor>0.7)
        rehash();
    }
    V remove(string key){
        int bucketIndex = getBucketIndex(key);
        mapNode<V>* head = buckets[bucketIndex];
        if(head->key==key){
            buckets[bucketIndex] = head->next;
            count --;
            return head->val;
        }
        mapNode<V>* prev=head;
        while (head!=NULL)
        {
            if(head->key == key){
                prev->next = head->next;
                count--;
                return head->val;
            }
            prev = head;
            head= head->next;
        }
    }
    V getValue(string key){
        int bucketIndex = getBucketIndex(key);
        mapNode<V>* head = buckets[bucketIndex];
        while (head!=NULL)
        {
            if(head->key == key){
                return head->val;
            }
            head= head->next;
        }
        return -1;
    }
};
