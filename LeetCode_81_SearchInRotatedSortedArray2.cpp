//Bruteforce :
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums[i] == target) return true;
        }
        return false;
    }
};
//T.C : O(n)
//S.C : O(1)


//optimal : binary search 
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] == target) return true;

            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++;
                high--;
                continue;
            }
            //left half sorted
            if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target <= nums[mid]) high = mid-1;
                else low = mid+1;
            }
            //right half sorted
            else{
                if(nums[mid]<= target && target <= nums[high]) low = mid+1;
                else high = mid-1;
            }
        }
        return false;
    }
};
//T.C : O(logn) if unique elements
//S.C : O(n/2+1) if duplicate 
