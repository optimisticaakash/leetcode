//Approach 1: brute force using O(n^2)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                if(nums[i] == nums[j]) return true;
            }
        }

        return false;
    }
};

//T.C : O(n^2)
//S.C : O(1) 

//Approach 2: using sorting 
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(begin(nums) , end(nums));

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]) return true;
        }

        return false;
    }
};

//T.C : O(nlogn)
//S.C : O(1) 

//Approach 3 : using  hashing using map 
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int , int> mpp;

        for(int num : nums){
            if(mpp.find(num) != mpp.end())return true;
            mpp[num]++;
        }

        return false;
    }
};
//alternative code: 

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int , int> mpp;

        for(int num : nums){
            mpp[num]++;
        }

        for(auto it : mpp){
            if(it.second != 1) return true;
        }
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;

        for(int num : nums){
            if(st.count(num))return true;
            st.insert(num);
        }

        return false;
    }
};
        return false;
    }
};
//T.C : O(n) 
//worst case : O(n^2)  due to collision
//S.C : O(n) 

//Approach 4 : using set 


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;

        for(int num : nums){
            if(st.count(num))return true;
            st.insert(num);
        }

        return false;
    }
};
//T.C : O(n) 
//worst case : O(n^2)  due to collision
//S.C : O(n) 
