//Approach1 : using unordered map
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //Approach1 : using map
        vector<int> ans;

        unordered_map<int,int> mpp;

        for(int num : nums){
            mpp[num]++;
        }

        for(auto it : mpp){
            if(it.second == 1) ans.push_back(it.first);
        }

        return ans;
    }
};
//T.C : O(n) - avg
//    : O(n^2) - worst ( hashing collison) 
//S.C : O(n) 

//Approach2 : using bitwise 
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //Approach 2 : using bitwise operator

        long XOR = 0;
        for(int num : nums) XOR ^= num;

        int rightmost  = (XOR & (XOR-1))^XOR;

        int b1 = 0; // rightmost bit turned to be 1
        int b2 = 0; // rightmost bit turned to be 0

        //now differentiating numbers into buckets
        for(int num : nums){
            if(num & rightmost) b1 ^= num;
            else b2 ^= num;
        }

        return{b1,b2};
    }
};
//T.C : O(2n)
//S.C ; O(1) 
