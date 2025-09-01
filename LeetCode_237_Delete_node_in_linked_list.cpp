//Approach1 : using loop 
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
    void deleteNode(ListNode* node) {
        ListNode* prev = NULL;

        while(node != NULL && node->next != NULL){
            node->val = node->next->val;
            prev = node;//assign to previous
            node=node->next;
        }
        prev->next=nullptr;
        delete node;
    }
};

//T.C : O(n) 
//S.c :O(1) 

//Approach: O(1) 
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
    void deleteNode(ListNode* node) {
        ListNode* temp = node->next; //node ke next ko save kro 
        node->val = temp->val; // next node ka data current node dal do
        node->next = temp->next; //current ka next = next ka next
        delete temp; //next ko delete kro 
    }
};

//T.C : O(1) 
//S.C   : O(1) 
