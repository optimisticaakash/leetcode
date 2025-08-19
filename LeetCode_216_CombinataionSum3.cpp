//Approach1 : using backtraking khandani template
class Solution {
public:
    void solve(int start , int n ,int k, vector<int> &temp , vector<vector<int>> &result){
        //base case0 |
        if(n<0 || k<0)return;

        if(n == 0 && k==0){
            result.push_back(temp);
            return;
        }

        if(start > 9||start > n)return;//agar current no > n se to add nhi kr skte to return
        
        temp.push_back(start);
        solve(start+1,n-start,k-1,temp , result);
        temp.pop_back();
        solve(start+1,n,k,temp,result);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> temp;
        solve(1 , n ,k , temp , result);

        return result;
    }
};

//Appraoch 2 : loop way backtracking
class Solution {
public:
    void solve(int start , int n ,int k, vector<int> &temp , vector<vector<int>> &result){
        //base case0 |
        if(n<0 || k<0)return;

        if(n == 0 && k==0){
            result.push_back(temp);
            return;
        }

        if(start > 9||start > n)return;//agar current no > n se to add nhi kr skte to return
        for(int i = start ; i <= 9 ; i++){
            temp.push_back(i);
            solve(i+1 , n-i  ,k-1, temp , result);
            temp.pop_back();
            
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> temp;
        solve(1 , n ,k , temp , result);

        return result;
    }
};

//T.C : O(9Ck * k)
//S.C : O(k) + O(9Ck*k)
