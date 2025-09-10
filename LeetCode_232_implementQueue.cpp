//Approach1 : using linkedlist
class Node{
    public:
    int data;
    Node* next;
    //constructor
    Node( int data1){
        data  = data1;
        next = nullptr;
    }
    //constructor
    Node(int data1 , Node* next1){
        data = data1;
        next = next1;
    }
};
class MyQueue {
    Node* start;
    Node* end;
    int size;

public:
    MyQueue() {
        start = NULL;
        end = NULL;
        size = 0;
    }
    
    void push(int x) {
        Node* newNode = new Node(x);
        if(size == 0){
            start = newNode;
            end = newNode;
        }
        end->next = newNode;
        end = newNode;

        size++;
    }
    
    int pop() {
        Node* temp = start;
        int el = start->data;
        start=start->next;
        delete temp;

        size--;

        return el;
    }
    
    int peek() {
        return start->data;
    }
    
    bool empty() {
        if(size == 0)return true;

        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
//T.C : O(1) every operation

//Approach2 : using stack
class MyQueue {
public:
    stack<int> s1 , s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        //empty s1 and put elements in s2
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        //push x in s1
        s1.push(x);

        //then put back all elements from s2 to s1
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int ele = s1.top();
        s1.pop();

        return ele;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        if(s1.empty()) return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

//T.C : push takes O(N) 

//Approach3 : using 2 stack
class MyQueue {
public:
    stack<int> s1 , s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(!s2.empty()){
            int ele = s2.top();
            s2.pop();
            return ele;
        }else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            int ele = s2.top();
            s2.pop();
            return ele;
        }
    }
    
    int peek() {
        if(!s2.empty()){
            return s2.top();
        }else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }
    
    bool empty() {
        if(s1.empty() && s2.empty()) return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

//T.c : O(1) amortized in case of top and pop  . worst - O(N)
//else O(1) 
