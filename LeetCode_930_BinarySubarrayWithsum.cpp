//Approach1: using bruteforce
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int cnt = 0;

        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];

                if(sum == goal){
                    cnt++;
                }else if(sum > goal){
                    break;
                }
            }
        }

        return cnt;
    }
};

//T.C :O(N^2)
//S.C :O(1)

//Approach2 : better(using hashmap)
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int,int> mpp;//past me sum kahan kitni bar dekha hai

        int count = 0;//no of subarray with sum = goal
        int currsum = 0;//cummulative sum or presum

        mpp[0] = 1;//jb koi subarray nhi to sum = 0 rhega 
        for(int i = 0; i < n; i++){
            currsum += nums[i];
            int rem = currsum - goal;

            if(mpp.find(rem) != mpp.end()){
                count += mpp[rem];
            }
            mpp[currsum]++;
        }

        return count;
    }
};
//T.C :O(N)
//S.C : O(N)


//Approaoch3 : optimal(mik)
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int l = 0;
        int r = 0;

        int result = 0;
        int sum = 0;
        int count_zeros = 0;
        while( r < n){
            sum += nums[r];

            while(l < r && (nums[l] == 0 || sum > goal)){

                if(nums[l] == 0){
                    count_zeros++;
                }else{
                    count_zeros = 0;
                }
                sum -= nums[l];
                l++;
            }

            if(sum == goal){
                result += 1 + count_zeros;
            }
            r++;
        }

        return result;
    }

};

//Alternative: striver
class Solution {
public:
    int countSum(vector<int>& nums, int goal){
        int n = nums.size();

        int l = 0 , r = 0 , sum = 0 , cnt = 0;

        //edge case
        if(goal < 0) return 0;

        while(r < n){
            sum += nums[r];
            while(sum > goal){
                sum -= nums[l];
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int cnt = 0;
        cnt = countSum(nums,goal)-countSum(nums,goal-1);

        return cnt;
    }
};

//T.C :O(n)
//S.C :O(1)
