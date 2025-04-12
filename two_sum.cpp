//Two Sum
// 1. non sorted hai 

// method 1 : brute force 
//Time Complexity : O(n^2) 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;

        for(int i = 0; i < n; i++){
            for(int j = i+1; j <n;j++){
                if(nums[i]+nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
                //break; my mistake kyonki agar humne break bahar likha  if ke  bahar hai to phle iteration ke baad hi  bahar aajyega loop ke answer mile ya nhi mile
            }
        }
        return ans;// solution exist krta hai to answer phle hi mil jyega yhan tk kbhi nhi ayega

    }
};


//optimised approach : using hashMap 
//Time complexity : O(n) 

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            int n = nums.size();
    
            map<int , int> mp;
    
            for(int i = 0; i < n; i++){
                int remEle = target - nums[i];
                //if(mp.find(remEle) != mp.end()) //iska mtlb exist krta hai array me remEle
                if(mp.count(remEle)){//element hai 
                    return {mp[remEle] , i};
                }
                //agar nhi hai to map me dal denge current element ko 
                mp[nums[i]] = i;//map me element or index dono save kr rhe hai
            }
    
            return {};//yhan tk nhi pahuchega kyonki answer exist krta hia
        }
    };
