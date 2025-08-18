//Approach1 : bruteforce backtraking + sorting+set
class Solution {
public:
    void solve(vector<int>& candidates , int target , vector<int>&arr , int i , set<vector<int>>&result){
        //base case
        if(i == candidates.size()){
            if(target==0) result.insert(arr);
            return ;
        }

        //include case - pick up element
        if(candidates[i] <= target){
            arr.push_back(candidates[i]);
            solve(candidates , target-candidates[i], arr , i+1 ,result);
            arr.pop_back();
        }
        //exclude case
        solve(candidates , target, arr , i+1 ,result);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> result;
        vector<int> arr;
        sort(begin(candidates) , end(candidates));
        solve(candidates ,target ,arr , 0 , result);
        //now hashset can be converted to vector of vector

        vector<vector<int>>answer(result.begin() , result.end());
        return answer;
    }
};

//This gives tle 
//T.C : O(2^n * k * logn) 
//k subsets each length n 
//insert in set taked logarithmic time

//S.C : O(2^n * n) set me store krne ka sare combination hi unique bne 
