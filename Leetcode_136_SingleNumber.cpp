//Approach1: using bruteforce 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int num = 0;
        
        for(int i = 0; i < n; i++){
            num = nums[i];
            int cnt = 0;//har num ke liye reset kro 
            for(int j = 0; j < n; j++){
                if(nums[j] == num){
                    cnt++;
                }
            }
            if(cnt == 1){
                return num;

            }
        }
        return -1;//never reach here

    }
};

//T.C : O(N^2)
//S.C: O(1)

//Approach2: better hashing (unordered_map)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;

        int ans = 0;

        for(int i = 0; i < n; i++){//unordered map insertion takes O(1) in average case
          //so O(n) for insertion of n elements 
            mpp[nums[i]]++;
        }

        for( auto it : mpp){
            if(it.second == 1){
                ans = it.first;
            }
        }

        return ans;
    }
};

//T.C : O(N)
//S.C : O(N)

//Approach 3: using XOR property
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int XOR = 0;

        for(int i = 0; i < n; i++){
            XOR ^= nums[i];
        }

        return XOR;
    }
};

//T.C : O(N)
//S.C : O(1)
