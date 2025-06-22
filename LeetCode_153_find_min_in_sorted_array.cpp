//Bruteforce : liner search 
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;

        for(int i = 0; i < n; i++){
            if(nums[i] < mini) mini = nums[i];
        }
        return mini;
    }
};

//T.C = O(n)
//S.C = O(1)

//optimal way: binary search 
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int mini = INT_MAX;

        while(low <= high){
            int mid = (low + high)/2;

            //search space is already sorted so smallest  element is 
            //nums[low]

            if(nums[low] <= nums[high]){
                mini = min(nums[low], mini);
                break;
            }

            if(nums[low] <= nums[mid]){
                mini = min(mini,nums[low]);
                low = mid+1;
            }else{
                mini = min(nums[mid] , mini);
                high = mid-1;
            }
        }
        return mini;
    }
};
//T.C : O(logn)
//S.C : O(1)
