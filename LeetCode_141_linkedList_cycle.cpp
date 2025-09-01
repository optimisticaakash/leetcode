//Approach1 : using map 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode* , int> mpp;

        ListNode* temp = head;

        while(temp != NULL){
            if(mpp.find(temp)!= mpp.end()) return true;

            mpp[temp]=1;

            temp = temp->next;
        }

        return false;
    }
};
//if we use unordered map (bcz insertion and lookup taked O(1) - in avg and best case) 
//T.C : O(N) || worst case : O(N^2) 
//S.C : O(N)

//if we use map 
//T.C : O(NlgoN)  -> bcz insertion and look up take  logN time
//S.C :O(N) 

//Approach2 : using tortoise and hare algorithm 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow=slow->next;
            fast=fast->next->next;

            if(slow == fast)return true;
        }

        return false;
    }
};
//T.C :O(N) 
//S.C : O(1) 
