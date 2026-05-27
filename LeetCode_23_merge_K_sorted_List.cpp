//Approach 1 : using brute force and another data structure
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> arr;

        for(int i = 0; i< lists.size(); i++){//O(n*m)
            ListNode* head = lists[i];
            while(head != NULL){
                arr.push_back(head->val);
                head = head->next;
            }
        }

        sort(arr.begin() , arr.end());//nlogn

        ListNode* dummyNode = new ListNode(-1);//O(m*n)
        ListNode* temp = dummyNode;
        for(int i : arr){
            ListNode* node = new ListNode(i);
            temp->next = node;
            temp = temp->next;
        }

        return dummyNode->next;
    }
};

//T.c : O(m*n) + m*N(log(m*n)) 
//S.C : O(m*n)

//optimised approach : 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoList(ListNode* headA , ListNode* headB){
        ListNode* dummyNode = new ListNode(-1);

        ListNode* t1 = headA;
        ListNode* t2 = headB;
        ListNode* temp = dummyNode;

        while(t1 != NULL && t2!= NULL){
            if(t1->val < t2->val){
                temp->next = t1;
                t1=t1->next;
            }else{
                temp->next = t2;
                t2=t2->next;
            }
            temp=temp->next;
        }
        if(t1) temp->next = t1;
        else temp->next = t2;

        return dummyNode->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res= NULL;

        for(ListNode* Node : lists){
            res = mergeTwoList(res , Node);
        }

        return res;
    }
};

//T.C : O(k * N) k is the no of list 
// N is the no of node in each list

//S.C : :O(k*N)


//Apporach 3 : using minheap 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class compare{
    public:
    bool operator()(ListNode* a , ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue< ListNode* , vector<ListNode*> , compare> pq;

        int k = lists.size();

        if(k == 0) return NULL;

        //step1 . put heads in minheap

        for(int i = 0;i < k;i++){
            if(lists[i] != NULL){
                pq.push(lists[i]);
            }
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(!pq.empty()){
            ListNode* top = pq.top();
            pq.pop();

            if(top->next != NULL){
                pq.push(top->next);
            }

            if(head == NULL){
                //answer is empty
                head = tail = top;
            }else{
                //insert at linked list
                tail->next = top;
                tail = top;
            }
        }

        return head;
    }
};


//code2 : 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class compare{
    public:
    bool operator()(ListNode* a , ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue< ListNode* , vector<ListNode*> , compare> pq;

        int k = lists.size();

        if(k == 0) return NULL;

        //step1 . put heads in minheap

        for(int i = 0;i < k;i++){
            if(lists[i] != NULL){
                pq.push(lists[i]);
            }
        }

        ListNode* dNode = new ListNode(-1);
        ListNode* temp = dNode;

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            if(top->next){
                pq.push(top->next);
            }

            temp->next = top;
            temp = temp->next;
        }
        return dNode->next;
    }
};

//T.C : O(Nlogk)
//where N : no of total Nodes
// K : no of linked list

//S.C : O(K)
