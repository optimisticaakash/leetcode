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


//Approach 2 : using bit manipulation class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>answer;
       
        int n = nums.size();
        int subsets = (1<<n);

        for(int num = 0; num < subsets ; num++){
            vector<int>temp;
            for(int i = 0; i < n; i++){
                if(num &(1<<i)) temp.push_back(nums[i]);
            }
            answer.push_back(temp);
        }

        return answer;
    }
};
//T.C : :O(2^n * n)
//S.c : O(2^n * n) 
