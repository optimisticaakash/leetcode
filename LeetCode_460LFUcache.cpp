//To implement a Node in doubly linked list that store data items
class Node{
    public:
    int key , val , cnt;
    Node* next;
    Node* prev;

    //constructor
    Node(int key1 , int val1 ){
        key = key1;
        val = val1;
        cnt = 1;
    }
};

//To implement doubly linked list 
class List{
    public:
    int size;
    Node* head;
    Node* tail;

    //constructor
    List(){
        head = new Node(0,0);
        tail = new Node(0,0);

        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node* node){
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }

    void removeNode(Node* delnode){
        Node* delprev = delnode->prev;
        Node* delnext = delnode ->next;

        delprev ->next = delnext;
        delnext->prev = delprev;
        size--;
    }
};
class LFUCache {
    map<int,Node*> keyNode;
    map<int ,List*> freqListMap;
    int maxSizeCache;
    int minFreq;
    int curSize;
public:
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;
    }
    void updateFreqListMap(Node* node){
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);
        if(node->cnt == minFreq && freqListMap[node->cnt]->size == 0){
            minFreq++;
        }

        List* nextHigherFreqList = new List();
        if(freqListMap.find(node->cnt+1) != freqListMap.end()){
            nextHigherFreqList = freqListMap[node->cnt+1];
        }
        node->cnt +=1;
        nextHigherFreqList -> addFront(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key]=node;
    }
    
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            int value = node->val;
            updateFreqListMap(node);
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxSizeCache == 0){
            return;//cannot enter any element
        }

        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node->val = value;
            updateFreqListMap(node);
        }else{
            if(curSize == maxSizeCache){
                List* list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);//remove LRU
                freqListMap[minFreq]->removeNode(list->tail->prev);
                curSize--;
            }
            curSize++;
            //new value has to be added who is not there previously
            minFreq = 1;
            List * listFreq = new List();
            if(freqListMap.find(minFreq) != freqListMap.end()){
                listFreq = freqListMap[minFreq];
            }
            Node* node = new Node(key , value);
            listFreq->addFront(node);
            keyNode[key] = node;
            freqListMap[minFreq] = listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

//T.c : O(1) in unordered_map insertion deletion takes O(1)
//S.C :O(2N) map and doubly linkedlist
