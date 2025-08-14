//Approach 1 : using backtracking 
class Solution {
public:
    vector<vector<int>> result;
    void solve(vector<int>& nums , int i , vector<int>&temp){

        //base case
        if(i >= nums.size()){
            result.push_back(temp);
            return;
        }

        temp.push_back(nums[i]); //take ith element
        solve(nums,i+1 , temp);

        temp.pop_back();//not take ith element
        solve(nums , i+1 , temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;//to store subset
        solve(nums, 0 , temp);

        return result;
    }
};

//T.C : O(2^n * n)
//S.C : O(n) 
