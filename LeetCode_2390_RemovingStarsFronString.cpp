//Approach 1: using string
class Solution {
public:
    string removeStars(string s) {
        string result;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '*'){
                result.pop_back();
            }else{
                result.push_back(s[i]);
            }
        }
        return result;
    }
};
//T.C :O(n)
//S.C :O(1)

//Approach2;using stack
class Solution {
public:
    string removeStars(string s) {
        stack<char> st;

        for(char ch : s){
            if(ch == '*'){
                if(!st.empty()) st.pop();
            } else {
                st.push(ch);
            }
        }

        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());//O(N)
        return ans;
    }
};

//T.C :O(N)
//S.C :O(N)

//Approach3 : using two pointer
class Solution {
public:
    string removeStars(string s) {
        int n = s.size();
        vector<int> temp(n);

        int j = 0;
        for(int i = 0; i < n;i++){
            if(s[i] == '*'){
                j--;
            }else{
                temp[j] = s[i];
                j++;
            }
        }

        string ans = "";
        for(int k = 0; k <= j-1; k++){
            ans += temp[k];
        }

        return ans;
    }
};
//T.C :O(n)
//S.C :O(N+N) = O(2N)
