//Code1 
class Solution {
public:
    vector<vector<int>>answer;
    void solve(vector<int> &candidates , int target ,vector<int>& arr , int i, int sum){
        //base case
        //condition not satisfied 
        if(sum > target || i == candidates.size()) return;
        //condition satisfied
        if(sum == target){
            answer.push_back(arr);
            return;
        }
      
        //include case
        arr.push_back(candidates[i]);
        sum += candidates[i];
        //include krne wale caes me i+1 nhi krenge , bcz ek element ko multiple times lekr subsequence bana skte hai 
        solve(candidates , target , arr , i, sum);

        arr.pop_back();
        sum -= candidates[i];

        solve(candidates , target , arr , i+1, sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int>arr;

        int sum = 0;
        int i = 0;
        solve(candidates , target ,arr , i , sum);

        return answer;
    }
};

//code2:

class Solution {
public:
    vector<vector<int>>answer;
    void findcombination( int i , vector<int> &candidates , int target ,vector<int>& arr ){
        //base case
        if(i == candidates.size()){
            if(target==0) answer.push_back(arr);
            return ;
        }
      
        //include case - pick up element
        if(candidates[i] <= target){
            arr.push_back(candidates[i]);
            //include krne wale caes me i+1 nhi krenge , bcz ek element ko multiple times lekr
            //subsequence bana skte hai 
            findcombination(i , candidates , target-candidates[i], arr);
            arr.pop_back();
        }
      
        findcombination(i+1 ,candidates , target , arr );
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int>arr;
        int i = 0;
        findcombination(i ,candidates , target ,arr );

        return answer;
    }
};

//T.C : O(2^t * k) 
//where k = avg length of every subset is k 
//Depth of recursion = t;
//t = target/min(candidates)

//S.C : O(t) +  O(k * x)  where x i no of combination
