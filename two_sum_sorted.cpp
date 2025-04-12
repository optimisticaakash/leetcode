//TWO SUM 2(leetcode 167)  link:https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
//Constraints:


//Optimised Code: 1.two pointer approach


//c++ me zero based indexing hi hoti hai but answer me 
//1-based indexing me answer chahiye

//two pointer approach use krenge

/* 
Reason 1: jab bhi question me bole ki array sorted hai to 
ishara krta hai 
(1) . two pointer approach pr
(2) . binary search pr 

NOTE : array ke sorted hone ka kuch to fyda uthyenge naa 

Reason 2: and more thing 
Constraints mein array size > 10^4 likha ho
Brute force (nested loop) fail karega

Trick : 
 n(size of array )           safe time complexity
 10                          O(n^2) is fine
 100                         O(n^2) still okay
 1000                        O(nlog n) max
 10000 - 30000               O(n) preferred
 10^5 or more                O(n) ya O(log n ) only 

// 
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        //two pointer approach

        int left = 0;
        int right = n-1;

        while(left < right){
            int sum = numbers[left] + numbers[right];

            if(sum == target) return {left+1 , right+1};// 1-based indexing me answer chahiye
            else if (sum < target) left++;
            else right--;
        }
    return { };//answer uper hi mil jyega kyonki exist krta hai yhan tk ayega hi nhi 
    }
};


//we will try it again with binary search 
//**************************************************************************************************************************************


