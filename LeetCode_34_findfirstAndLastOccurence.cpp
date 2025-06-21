//Appraoch 1:linear search

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int first = -1; 
        int last = -1;

        for(int i = 0; i < n; i++){
            if(nums[i] == target){
                if(first == -1) first = i;
                
                last = i;
            }
        }
        return {first,last};
    }
};

//T.C : O(n)
//S.C : O(1)

//Appraoch 2 : using binary search (lowerboound and upperbound)
//Code :  using  raw binary search code 
class Solution {
public:
    int upperbound(vector<int> &nums,int n, int target){
        int low = 0;
        int high = n-1;
        int ans = n;

        while(low<= high){
            int mid = (low+high)/2;

            if(nums[mid]> target){
                ans = mid;
                high = mid-1;//search for smallest in left
            }else{
                low = mid+1;
            }
        }
        return ans;
    }

    int lowerbound(vector<int> &nums,int n, int target){
        int low = 0;
        int high = n-1;
        int ans = n;

        while(low<= high){
            int mid = (low+high)/2;

            if(nums[mid]>= target){
                ans = mid;
                high = mid-1;//search for smallest in left
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int lb = lowerbound(nums,n,target);
        int ub = upperbound(nums,n,target);

        if(lb == n || nums[lb] != target) return {-1,-1};
        else return {lb , ub-1};
    }
};


//Alternative code : using c++ st;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int lb = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int ub = upper_bound(nums.begin() , nums.end(),target)-nums.begin();

        if(lb == n || nums[lb] != target) return {-1,-1};
        else return {lb,ub-1};
    }
};

//T.C : O(logn)
//S.C : O(1)


