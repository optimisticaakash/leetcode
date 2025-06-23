//Approach1: using bruteforce 

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        if(n==1) return 0;
        for(int i = 0; i < n; i++){
            if(i == 0){
                if(nums[i] > nums[i+1]) return i;
            }else if(i == n-1){
                if(nums[i] > nums[i-1]) return i;
            }else{
                if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) return i;
            }
        }
        return -1;
    }
};

//alternate better code of same complexity
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        for(int  i = 0; i < n; i++){
            if((i == 0 || nums[i] > nums[i-1]) && (i == n-1 || nums[i] > nums[i+1])) return i;
        }
        return -1;
    }
};
//T.C : O(n)

//Approach 2 :optimal binary search
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        int low = 1; int high = n-2;

        if(n==1) return 0;

        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
        
        while(low <= high){
            int mid = (low+high)/2;

            if(nums[mid]>nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
            else if(nums[mid] > nums[mid+1]){
                //descending slope , peak left me hai
                high = mid-1;
            }else{
                low = mid+1;
            }

        }

        return -1;
    }
};

//T.C : O(logn)
