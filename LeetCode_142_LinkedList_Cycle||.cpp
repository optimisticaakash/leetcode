//Approach1 : using hashing
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
    ListNode *detectCycle(ListNode *head) {
        map<ListNode* , int> mpp;
        ListNode* temp = head;
        while(temp != NULL){
            if(mpp.find(temp) != mpp.end()){
                return temp;
            }
            mpp.insert({temp,1});//mpp[temp]=1;
            temp = temp->next;
        }

        return NULL;

    }
};

//T.C : O(NLogN) //map me insertion and lookup take  logN
//S.C : O(N) 

//Approach2 : tortoise and hare
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow=slow->next;
            fast=fast->next->next;

            if(slow ==fast){
                slow = head;
                while(slow != fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;//or we can return fast , both at starting node of LL cycle
            }
        }

        return NULL;
    }
};

//T.C : O(2n)
//S.C : O(1) 
