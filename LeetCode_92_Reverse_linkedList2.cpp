//Approach 1 : /**
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //edge case
        if(head == NULL || head->next == NULL) return head;

        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;

        ListNode* prev = dummyNode;

        for(int i = 1; i < left ; i++){
            prev = prev->next;
        }

        ListNode* curr = prev->next;

        for(int i = 1; i <= right - left; i++){
            ListNode* temp = prev->next;
            prev->next=curr->next;
            curr->next = curr->next->next;
            prev->next->next=temp;
        }

        return dummyNode->next;
    }
};
//T.C : O(n) 
//s.c : O(1) 

//Approach2 : 
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
    ListNode* reverse(ListNode* head , int count){
        ListNode* temp = head;
        ListNode* prev = NULL;
    
        while(count){
            count--;
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp= front;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //dummy node for handling left = 1; wala case ke liye
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        //beforeL us node ko point krega jis position se reverse krna ha hume
        ListNode* beforeL = dummy;
        for(int i = 1; i< left; i++){
            beforeL = beforeL->next;
        }

        //starting point of reverse
        ListNode* start = beforeL->next;
        
        //AfterR point krega us node ko jisse phle tk reverse kiya hai 
        ListNode* AfterR = start;
        for(int i = 1; i <=right-left+1; i++){
            AfterR = AfterR->next;
        }

        int count = right-left+1;//jitne position ko reverse krna hai
        //given part of linked list ko reverse krke newhead return krega function
        ListNode* reversed = reverse(beforeL->next ,count);

        

        beforeL->next = reversed;
        start->next = AfterR;//reverse krne ke baad starting point  hi reversed list ka ending point hoga


        return dummy->next;
    }
};

//T.C :O(N)
//s.c : O(1) 
