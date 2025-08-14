//Appraoch1 : using backtracking

class Solution {
public:
    void solve(vector<int> &nums , int i , vector<int> &temp , vector<vector<int>> &answer){
        //base case
        if(i >= nums.size()){
            answer.push_back(temp);
            return ;
        }

        //inclusion wali choice
        temp.push_back(nums[i]);
        solve(nums , i+1, temp , answer);
        temp.pop_back();

        //for exclusion choice - skip duplicates
        int idx = i+1;
        while( idx < nums.size() && nums[idx] == nums[idx-1]){
            idx++;
        }
        solve(nums,idx , temp , answer);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin() , nums.end());//sort taki sare duplicates element ek sath aa jaye
        vector<vector<int>> answer;//to store all generated subsets
        vector<int> temp;//to store subsets

        solve(nums, 0 , temp , answer);

        return answer;
    }
};

//T.C : O(2^n * n + nlogn)
//S.C  : O(n) 
