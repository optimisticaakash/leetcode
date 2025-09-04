//Approach1: /**
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode* temp = head;
        while(temp != NULL){
            cnt++;
            temp=temp->next;
        }

        if(cnt == n){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        int res = cnt- n;
        temp = head;
        while(--res){
            temp=temp->next;
        }

        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;

        return head;
    }
};
//T.C :O(length)
//S.C : O(1) 

//Approach2: /**
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        int cnt = 0;
        for(int i = 1; i <= n;i++) fast= fast->next;

        if(fast == NULL){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        ListNode* slow = head;
        while(fast->next != NULL){
            slow=slow->next;
            fast=fast->next;
        }

        ListNode* delNode = slow->next;
        slow->next= slow->next->next;
        delete delNode;

        return head;
    }
};
//T.C : O(Length)
//S.C :O(1)
