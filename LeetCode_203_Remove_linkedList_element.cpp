//Approach 1 :

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
    ListNode* removeElements(ListNode* head, int val) {
        //if node null , mtlb no linkedlist
        if(head == NULL) return head;

        //if value is at head , jbtk value same mile delete krte rho
        while(head != NULL && head->val == val){
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        //jb bich me values given value ke barabar ho 
        ListNode* temp = head;
        while(temp != NULL && temp->next != NULL){
            if(temp->next->val==val){
                ListNode* del = temp->next;
                temp->next = temp->next->next;
                delete del;
            }else{
                temp=temp->next;
            }
        }
        return head;
    }
};
//T.C  : O(n) 
//S.C: O(1 ) 
