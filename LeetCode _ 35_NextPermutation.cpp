//Approach 1 : Brute force 
/*
1. find all the possible permutation 
2.arrange them in sorted order
3. find the next permutation in the list 


//we will study this approach in more depth in recursion 


*/
//T.C : O(n! * n)

//Approach 2 : use next_permutation c++ st;
//Code : 
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin() , nums.end());
        
    }
};

//T.C : O(n)
//S.C : O(n) 

//Approach3 : implementation of next_permutation 
//Code : 
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        int n = nums.size();

        for(int i = n-2; i >= 0;i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }

        if(index == -1){//no dip found i.e already last permutation so , just reverse the nums , we will get first permutation 
            reverse(nums.begin() , nums.end());
            return;
        }
        //find just greater element than element at index
        for(int i = n-1; i > index; i--){
            if(nums[i]>nums[index]){
                swap(nums[i] , nums[index]);
                break;
            }
        } 

        reverse(nums.begin()+index+1 , nums.end());
        
    }
};

//T.C : O(n)
//S.C : O(1)
