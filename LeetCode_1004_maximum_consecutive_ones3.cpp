//Approach1 : brute
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int maxlen = 0;

        for(int i = 0; i < n;i++){
            int zeros = 0;
            for(int j = i; j < n; j++){
                if(nums[j] == 0) zeros++;
                if(zeros <= k){
                    int len = j-i+1;
                    maxlen = max(maxlen , len);
                }else{
                    break;
                }
            }
        }

        return maxlen;
    }
};

//T.C :O(N^2)
//S.C :O(1)

//Approach2 : using slinding window and 2 pointer
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0 , r = 0 , maxlen = 0 , zeros = 0;

        while( r < n){
            if(nums[r] == 0) zeros++;
            while(zeros > k){
                if(nums[l] == 0) zeros--;
                l++;
            }
            //agar valid window hai to find maxlen
            if(zeros <= k){
                int len = r - l + 1;
                maxlen = max(maxlen , len);
            }

            r++;
        }

        return maxlen;
    }
};
//T.C :O(2*N)
//S.C ::O(1)

//Approach 3 : optimised
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0 , r = 0 , maxlen = 0 , zeros = 0;

        while(r < n){
            if(nums[r] == 0) zeros++;
            //jbtk window valid na ho ho keep moving l
            if(zeros > k){
                if(nums[l] == 0) zeros--;
                l++;
            }

            if(zeros <= k){
                int len = r - l +1;
                maxlen = max(maxlen , len);
            }
            r++;
        }

        return maxlen;
    }
};
//T.C :O(n)
//S.C :O(1)
