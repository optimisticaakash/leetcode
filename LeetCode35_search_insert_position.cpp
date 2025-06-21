//Approach : using binary search lower bound 

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;

        int index = n;

        while(low <= high){
            int mid = (low+high)/2;

            //may be an answer
            if(nums[mid]>= target){
                index = mid;
                high = mid-1;//look for smaller index on left
            }else{
                low = mid+1;
            }
        }

        return index;
    }
};

//T.C : O(logn)
//S.C : O(1) 
