//Bruteforce : liner search 
//Code : 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums[i] == target)return i;
        }
        return -1;
    }
};

//T.C : O(n)
//S.C : O(1)

//optimal approach : using binary search 
//code : 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = (low+high)/2;

            if(nums[mid] == target) return mid;

            //if left half sorted
            if(nums[low] <= nums[mid]){
                //check for target in sorted half
                if(nums[low] <= target && target <= nums[mid]){
                    high = mid-1;
                }
                else low=mid+1;
            }
            //right half sorted
            else{
                //check for target in sorted half
                if(nums[mid] <= target && target <= nums[high]){
                    low = mid+1;
                }
                else high = mid-1;

            }
        }

        return -1;
    }
};

//T.C : O(logn)
//S.C : O(1) 
