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
class MyStack {

    Node*  topp;
    int size;
public:
    MyStack() {
        topp = nullptr;
        size = 0;
    }
    
    void push(int x) {
        Node* temp = new Node(x);
        temp ->next = topp;
        topp = temp;
        size+= 1;
    }
    
    int pop() {
        Node* temp = topp;
        int el = temp->data;
        topp = topp->next;
        delete temp;
        size -=1;
        return el;
    }
    
    int top() {
        int el = topp->data;
        return el;
    }
    
    bool empty() {
        if(size == 0) return true;

        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

//T.C : push , pop , top , empty - every function takeing O(1) 
//S.C : O(n)- no of element 

//Approach 2 : using queue
class MyStack {
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int n = q.size();
        for(int i = 0; i < n-1; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int ele = q.front();
        q.pop();

        return ele;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        if(q.size() == 0) return true;

        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

//T.C : Push operation takes O(n) 
//every other operation taked O(1) 


//Appraoch3 : using two queues
class MyStack {
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1 , q2);
    }
    
    int pop() {
        int ele = q1.front();
        q1.pop();

        return ele;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        if(q1.size() == 0) return true;

        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

//T.C : only push  takes- O(n) 
//S.C : O(n) 
