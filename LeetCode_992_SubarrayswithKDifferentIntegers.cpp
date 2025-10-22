//Approach1 : bruteforce
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;


        for(int i = 0; i < n; i++){
            unordered_map<int,int> hash;
            for(int j = i; j < n; j++){
                hash[nums[j]]++;

                if(hash.size() == k){
                    cnt++;
                }
                if(hash.size() > k){
                    break;
                }
            }
        }

        return cnt;
    }
};

//T.C :O(n^2)
//S.C :O(n)

//Approach2: sliing window 
class Solution {
public:
    int countSubarray(vector<int>& nums, int k){
        int n = nums.size();
        int l = 0 , r = 0 , cnt = 0;

        unordered_map<int,int> mpp;

        while(r < n){
            mpp[nums[r]]++;

            while(mpp.size() > k){
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0) mpp.erase(nums[l]);

                l++;
            }
            cnt += (r-l+1);
            r++;
        }

        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int count = 0;

        count = countSubarray(nums,k) - countSubarray(nums,k-1);

        return count;
    }
};

//T.C : O(2N)
//S.C :O(N)

//Approach3 : mik one pass
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> mpp;
        int result = 0;
        
        int i = 0 , j = 0 , i_bada = 0;

        while( j < n){
            mpp[nums[j]]++;

            //Handle invalid window case
            while(mpp.size() > k){
                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0) mpp.erase(nums[i]);
                i++;
                i_bada = i;
            }

            //finding smallest valid subarray ending at j
            while(mpp[nums[i]] > 1){
                mpp[nums[i]]--;
                i++;
            }

            if(mpp.size() == k){
                result += 1 + (i - i_bada);
            }
            j++;
        }

        return result;

    }
};
//T.C  : O(3N)
//S.C :O(N)
