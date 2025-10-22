//Approach 1: Bruteforce
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;

        for(int i = 0; i < n; i++){
            int oddCount = 0;
            for(int j = i; j < n; j++){
                if(nums[j]%2 == 1){
                    oddCount += 1;
                }

                if(oddCount == k){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
//T.C : O(n^2)
//S.C :O(1)

//Approach2 : using sliding window
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> mpp;//to store Oddcount to see if it seen in past 
        int nicecount = 0 , oddCount = 0;


        mpp[oddCount] = 1;//oddCount = 0 seen when no subarray seen

        for(int i = 0; i < n; i++){
            oddCount += (nums[i]%2);

            if(mpp.count(oddCount-k)){
                nicecount += mpp[oddCount - k];
            }
            mpp[oddCount]++;
        }

        return nicecount;
    }
};
//T.C :O(n)
//S.C :O(n)

//Approach3 :
class Solution {
public:
    int niceCount(vector<int>& nums, int k){
        int n = nums.size();
        int l = 0 , r = 0 , cnt = 0 , sum = 0;

        while(r < n){
            sum += (nums[r]%2);
            while(sum > k){
                sum -= (nums[l]%2);
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int niceCnt = 0;

        niceCnt = niceCount(nums,k)-niceCount(nums,k-1);

        return niceCnt;
    }
};
//T.C :O(n)
//S.C :O(n)

//Approach4 : mik
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int oddCount = 0;
        int prevCount = 0;
        int result = 0;

        int i = 0 , j = 0;

        while( j < n){
            if(nums[j] % 2 != 0){//odd hai
                oddCount += 1;
                prevCount = 0;
            }

            while(oddCount == k){
                prevCount++;
                if(nums[i]%2 == 1){
                    oddCount--;
                }
                i++;
            }
            result += prevCount;
            j++;
        }
        return result;
    }
    
};

//T.C :O(2n)
//S.C : O(1)
