//Approach 1 ; using map 
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode* , int> mpp;
        ListNode* temp = headA;
        while(temp != NULL){
            mpp[temp] = 1;
            temp=temp->next;
        }

        temp = headB;
        while(temp != NULL){
            if(mpp.find(temp) != mpp.end()) return temp;
            temp = temp->next;
        }

        return NULL;

    }
};
//Time Complexity (with map): O((n + m) log n)

//Space Complexity: O(n)

//Approach 2 : 
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
    ListNode* collisionNode(ListNode *headA, ListNode *headB , int d){
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        while(d){
            d--;
            t2=t2->next;
        }

        while(t1 != t2){
            t1 = t1->next;
            t2 = t2->next;
        }
        return t1;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* t1 = headA;
        int N1 = 0;

        while(t1 != NULL){
            N1++;
            t1=t1->next;
        }

        ListNode* t2 = headB;
        int N2 = 0;

        while(t2 != NULL){
            N2++;
            t2=t2->next;
        }

        if(N1<N2){
            return collisionNode(headA , headB , N2-N1);
        }else{
            return collisionNode(headB , headA , N1-N2);
        }

    }
};
//Time Complexity: O(N1 + N2)

//Space Complexity: O(1)

//Approach3: using two pointer
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;

        ListNode* t1 =headA;
        ListNode* t2 =headB;

        while(t1 != t2){
            t1=t1->next;
            t2=t2->next;

            if(t1 == t2) return t1;

            if(t1 == NULL) t1 = headB;
            if(t2 == NULL) t2 = headA;
        }
        return t1;
    }
};
//Time Complexity: O(lenA + lenB)

//Space Complexity: O(1)
