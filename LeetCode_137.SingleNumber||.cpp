//Appraoch1 : bruteforce (using map)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mpp;

        for(int num : nums){
            mpp[num]++;
        }

        for(auto it : mpp){
            if(it.second == 1) return it.first;
        }


        return -1;
    }
};

//T.C : O(n)-avg
 //   : O(n^2) worst (hashing collision)
//S.C : O(n) 

//Approach2 :using bitwise
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int bitindex = 0; bitindex <32; bitindex++){
            int cnt = 0;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] & (1<<bitindex)) cnt++;
            }
            if(cnt %3 == 1){
                ans = ans | (1 << bitindex);
            }
        }

        return ans;
    }
};

//T.c : O(n * 32)
//S.C : O(1)

//Approach3 : //iterating midding element and checking conditions
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //approach3 
        sort(nums.begin() , nums.end());
        int n = nums.size();
        for(int i = 1; i < n; i=i+3){
            if(nums[i] != nums[i-1]) return nums[i-1];
        }
        return nums[n-1];
    }
};
//T.C : O(nlogn) + O(n/3)
//S.c : O(1)

//Approach 4 : using bitwise operator
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //approach4 :
        int ones = 0 , twos = 0;
        for(int i = 0; i < nums.size(); i++){
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }

        return ones;
    }
};

//T.c : O(n)
//S.C : O(1) 
