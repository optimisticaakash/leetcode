//Approach 1 : using while loop

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head== NULL || head->next == NULL)
            return head;


        ListNode* first = head;
        ListNode* sec = head->next;
        ListNode* prev = NULL;


        while(first != NULL && sec != NULL){
            ListNode* third = sec->next;

            sec->next = first;
            first->next = third;

            if(prev != NULL){
                prev->next = sec;
            }else{
                head = sec;
            }


            //updatation
            prev = first;
            first = third;

            if(third != NULL){
                sec = third->next;
            }else{
                sec = NULL;
            }
        }


        return head;
    }
};

//T.C : 1. do nodes ko bar apas me swap kr rhe hai
//       2. har node ko ek hi baar visit kr rhe hai toh 

//T.C : O(N)

//S.C : since no extra space is used O(1)


//Approach 2 : using recursion
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        //A -> head
        //B - head->next 
        //C - head->next->next;

        //A->B->C
        ListNode* temp = head->next;
        head->next = swapPairs(head->next->next);
        temp->next = head;

        return temp;
    }
};

//T.C : O(N) har node ko ek hi baar visit kiya hai toh
//S.C : O(N) recursive call stack 
