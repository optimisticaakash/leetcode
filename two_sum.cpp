//Two Sum

//Approach 1 
// 1. non sorted hai 

// method 1 : brute force (my code )
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

//Alternative code :  without using extra space
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {//O(N^2)
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int diff = target - nums[i];
            for(int j = i + 1; j < n; j++) {
                if(nums[j] == diff) {
                    return {i, j};
                }
            }
        }
        return {}; // no pair found
    }
};





// approach 2 (better approach ): using hashMap 
//Time complexity : O(nlogn) 
//Space complexity : O(n)
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
//Approach 3 : if hashing and not allowed ,better than brute
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //if we dont  cannot use map then better approach then O(n^2)

        vector<pair<int,int>> v;//{value,index}//On)
        for(int i = 0; i < nums.size(); i++){//O(n)
            v.push_back({nums[i],i});
        }

        sort(v.begin() , v.end());
        int left = 0; int right = nums.size()-1;
        while(left < right){//O(n)
            int sum = v[left].first + v[right].first;
            if(sum == target){
                return {v[left].second , v[right].second};
            }
            else if(sum > target) right--;
            else left++;
        }
        return {-1,-1};
    }

    
};

//T.C = O(nLogN)
//s.c = O(n) 
