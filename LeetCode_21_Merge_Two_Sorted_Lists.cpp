//Approach1 
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
//T.C :O(n1) + O(n2) + O(nlogn) + O(n)  ,n = n1+n2
//S.C :O(n) + O(n) 

//Appraoch 2 : /**
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
//T.C :O(n1 + n2)
//S.C : O(1) 
