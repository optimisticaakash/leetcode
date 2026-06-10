//Approach1: Bruteforce(naive approach) 
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
    ListNode* convertArrToList(vector<int> &arr){
        if(arr.empty()) return nullptr;
        
        ListNode* newHead = new ListNode(arr[0]);
        ListNode* mover = newHead;

        for(int i = 1; i < arr.size(); i++){
            ListNode* temp = new ListNode(arr[i]);
            mover->next = temp;
            mover = temp;
        }

        return newHead;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> arr;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        while(temp1 != NULL){
            arr.push_back(temp1->val);
            temp1=temp1->next;
        }

        while(temp2 != NULL){
            arr.push_back(temp2->val);
            temp2=temp2->next;
        }

        sort(arr.begin() , arr.end());

        ListNode* head = convertArrToList(arr);

        return head;
    }
};

//T.C : O(m+n * log(m+n))
//S.C : O(m+n)

//Approach2: using recursion
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //Base Case
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        if(list1->val < list2->val){
            list1->next = mergeTwoLists(list1->next , list2);
            return list1;
        }else{
            list2->next = mergeTwoLists(list1 , list2->next);
            return list2;
        }
    }
};

//T.C : O(n+m)
//S.C : O(n+m)


//Approach3: optimal using iterative merging
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* t1 = list1;
        ListNode* t2 = list2;

        ListNode* dNode = new ListNode(-1);
        ListNode* temp = dNode;
        while(t1 != NULL && t2 != NULL){
            if(t1->val < t2->val){
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            }else{
                temp->next = t2;
                temp = t2;
                t2 = t2->next;
            }
        }
        // Attach leftover nodes outside the loop
        if(t1 != NULL) temp->next = t1;
        else temp->next = t2;

        return dNode->next;
    }
};
//T.C : O(m+n)
//S.C : O(1)
