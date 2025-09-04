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
    ListNode* deleteMiddle(ListNode* head) {
        //edge case
        if(head == NULL || head->next == NULL) return NULL;

        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL){
            cnt++;
            temp=temp->next;
        }
        int res = (cnt/2);
        temp = head;
        while(temp != NULL){
            res = res -1;
            if(res == 0){
                ListNode* middle= temp->next;
                temp->next = temp->next->next;
                delete middle;
                break;
            }
            temp=temp->next;
        }
    
        return head;

    }
};
//T.C :O(N + N/2)
//S.C :O(1) 

//Appraoch2 :/**
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
    ListNode* deleteMiddle(ListNode* head) {
        //edge case
        if(head == NULL || head->next == NULL) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;

        fast = fast->next->next;
        while(fast!= NULL && fast->next!= NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* middle = slow->next;
        slow->next = slow->next->next;
        delete middle;

        return head;
    }
};

//T.C :O(N/2)
//S.C :O(1) 
