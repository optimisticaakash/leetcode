//optimised approach

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            int n = nums.size();
    
            map<int , int> mp;
    
            for(int i = 0; i < n; i++){
                int remEle = target - nums[i];
                if(mp.count(remEle)){//element hai 
                    return {mp[remEle] , i};
                }
                //agar nhi hai to map me dal denge current element ko 
                mp[nums[i]] = i;//map me element or index dono save kr rhe hai
            }
    
            return {};//yhan tk nhi pahuchega kyonki answer exist krta hia
        }
    };