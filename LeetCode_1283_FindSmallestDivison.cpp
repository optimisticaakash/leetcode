//Approach 1 : using linear search 
class Solution {
public:
    bool checkdivisor(vector<int> & nums,int divisor, int threshold){
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += ceil((double)nums[i]/divisor);
        }

        if(sum <= threshold) return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n =nums.size();

        int maxi = *max_element(nums.begin() , nums.end());        

        for(int i = 1; i <= maxi; i++){
            if(checkdivisor(nums,i,threshold) == true) return i;
        }
        return -1;
    }
};

//Alterantive code : 
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        int maxi = *max_element(nums.begin() , nums.end());

        for(int d = 1; d <= maxi; d++){
            int sum = 0;
            for(int i = 0; i < n;i++){
                sum += ceil((double)nums[i]/d);
            }
            if(sum <= threshold)
            return d;
        }
        return -1;
    }
};

//T.C : O(max) * O(n) = O(n^2)
//Approach2 : using binary search 
class Solution {
public:
    bool checkdivisor(vector<int> & nums,int divisor, int threshold){
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += ceil((double)nums[i]/divisor);
        }

        if(sum <= threshold) return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n =nums.size();
        
        int maxi = *max_element(nums.begin() , nums.end());        

        int low = 1;
        int high = maxi;

        int ans = -1;
        while(low <= high){
            int mid = (low + high)/2;

            if(checkdivisor(nums,mid,threshold)){
                ans =  mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};
//T.C : O(logmax) * O(n) 
//T.C : O(1)

//Alternative code : return low
class Solution {
public:
    bool checkdivisor(vector<int> & nums,int divisor, int threshold){
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += ceil((double)nums[i]/divisor);
        }

        if(sum <= threshold) return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n =nums.size();
        
        int maxi = *max_element(nums.begin() , nums.end());        

        int low = 1;
        int high = maxi;

        int ans = -1;
        while(low <= high){
            int mid = (low + high)/2;

            if(checkdivisor(nums,mid,threshold)){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};
//T.C : O(logmax) * O(n) 
//T.C : O(1)
