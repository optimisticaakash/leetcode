//Approach1 : 
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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int cnt  = 0;
        while(temp != NULL){
            cnt++;
            temp=temp->next;
        }

        int middleNode = (cnt/2)+1;
        temp = head;
        while(temp != NULL){
            middleNode--;
            if(middleNode == 0) break;
            temp=temp->next;
        }

        return temp;
    }
};

//T.C : O(N) 
//S.C : O(N) 

//Alternative code : 
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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int cnt  = 0;
        while(temp != NULL){
            cnt++;//1 based indexing
            temp=temp->next;
        }

        int middleNode = (cnt/2)+1;
        temp = head;
        while(--middleNode){
            temp=temp->next;
        }

        return temp;
    }
};
//T.C : O(N) 
//S.C : O(N) 

//Approach2 : tortoise and hare method (slow and fast pointer) 
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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!= NULL && fast->next != NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;
    }
};
//T.C : O(N/2)
//S.C :O(N)
