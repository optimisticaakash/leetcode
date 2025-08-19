//Approach1 : using khandani template
class Solution {
public:
    void solve(int start , int n , int k , vector<int>&temp , vector<vector<int>> &result){
        //base case
        if(k == 0){
            result.push_back(temp);
            return;
        }

        if(start > n) return;//bcz range is [1 , n]

        temp.push_back(start);
        solve(start+1 , n , k-1 , temp , result);

        temp.pop_back();
        solve(start+1 , n, k , temp , result);
    }
    vector<vector<int>> combine(int n, int k) {
      vector<vector<int>> result;
      vector<int> temp;

      solve(1 , n , k , temp , result);
      return result;  
    }
};

//Approach2 : using loop way 
class Solution {
public:
    void solve(int start , int n , vector<int> temp, vector<vector<int>>&answer , int k){
        //base case 
        if(k == 0){
            answer.push_back(temp);
            return;
        }

        for(int  i = start;i <= n ; i++){
            temp.push_back(i);
            solve(i+1 ,n , temp , answer , k-1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> answer;
        vector<int> temp;
        int size = 0;
        solve(1 , n , temp , answer , k );
        return answer;
    }
};

//T.C : O(nCk)
//s.C : O(k) + O(nCk * k) 
