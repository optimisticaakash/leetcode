//Approach1 Using recursion
class Solution {
public:
    int n;
    unordered_set<string>st;
    bool solve(int idx , string&s){
        if(idx >= n){
            return true;
        }

        if(st.find(s) != st.end())
            return true;

        for(int l = 1; l <= n; l++){
            string temp = s.substr(idx,l);
            if((st.find(temp) != st.end()) && solve(idx+l , s)){
                return true;
            }
        }  
        return false;  
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();

        for(auto word : wordDict){
            st.insert(word);
        }

        return solve(0 , s);
    }
};

//T.C : O(2^n * Nn^h)
//S.C : O(n) + O(n) + O(m*k) 

//THIS CODE GIVES TLE , WE WILL STUDY THIS LATER (USING MEMOIZATION) IN DP 
