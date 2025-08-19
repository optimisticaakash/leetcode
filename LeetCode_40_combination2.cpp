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

//Approach 2 :using sorting and filtering  duplicate subset cases
class Solution {
public:
    vector<vector<int>> answer;
    void solve(vector<int> &candidates , int target ,vector<int>& arr , int i){
        //base case
        if(target == 0){
            answer.push_back(arr);
            return;
        }

        if(i >= candidates.size() || target < 0)return;

        //include case
        arr.push_back(candidates[i]);
        solve(candidates , target-candidates[i], arr , i+1);
        arr.pop_back();

        int idx = i+1;
        //exclude wale case me duplicate skip krne ke liye
        while(idx < candidates.size() && candidates[idx] == candidates[idx-1]){
            idx++;
        }
        solve(candidates , target , arr , idx);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>arr;
        int i = 0;
        sort(candidates.begin() , candidates.end());
        solve(candidates , target ,arr , i );

        return answer;
    }
};
//T.C : O(2^n * k)
//k subsets each length n 
//insert in set taked logarithmic time

//S.C : O(2^n * n) set me store krne ka sare combination hi unique bne 
//Approach2 : using 2nd type using loop 
class Solution {
public:
    void solve(int ind ,vector<int> candidates,vector<int>&arr,int target , vector<vector<int>> &answer){
        //base case
        if(target == 0){
            answer.push_back(arr);
            return ;
        }

        //picking up sequence
        for(int i = ind ; i < candidates.size(); i++){
            if(i > ind && candidates[i] == candidates[i-1]){
                continue;
            }
            if(candidates[i]> target) break;
            arr.push_back(candidates[i]);
            solve(i+1,candidates , arr , target-candidates[i] , answer);
            arr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> arr;

        sort(begin(candidates) , end(candidates));
        solve(0 ,candidates, arr , target , answer);

        return answer;
    }
};
//T.C : O(2^n * k)
//S.C : O(k * x) + O(target) 
