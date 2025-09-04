//Approach 1 : using stack
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
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;
        while(temp != NULL){
            st.push(temp->val);
            temp=temp->next;
        }

        temp = head;
        while(temp != NULL){
            if(temp->val != st.top()) return false;

            temp=temp->next;
            st.pop();
        }
    return true;
    }
};

//T.C : O(2N)
//S.C :O(N)


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
    ListNode* reverseLL(ListNode* head){
        if(head == NULL || head->next == NULL) return head;

        ListNode* newHead = reverseLL(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;

        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)return true;//ek node to bhi palindrome
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast= fast->next->next;
        }
        ListNode* newHead = reverseLL(slow->next);

        ListNode* first = head;
        ListNode* second = newHead;
        while(second!= NULL){
            if(first->val != second->val){
                reverseLL(newHead);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        reverseLL(newHead);
        return true;
    }
};
//T.C : O(2N)
//S.C : O(N) recursive stack space - reverse function recursive approach pr hai isliye

//Approach3 : using array and 2 pointer /**
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
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        while(temp != NULL){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        
        int i = 0; 
        int j = arr.size()-1;
        while(i < j){
            if(arr[i] != arr[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};

//T.C :O(N)
//S.C :O(N)
