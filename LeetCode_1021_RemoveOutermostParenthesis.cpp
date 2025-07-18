//Bruteforce : 
class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;

        string ans = "";

        for(char ch : s){
            if(ch == '('){
                if(cnt > 0){
                    ans += ch;
                }
                cnt++;
            }else{
                cnt--;
                if(cnt > 0) ans += ch;
            }
        }

        return ans;
    }
};
//T.C : O(n) 
//S.C : O(n) using extra space 

//optimalWay: 
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int start = 0;
        int open_cnt = 0;
        int close_cnt = 0;

        for(int i = 0; i < s.size() ; i++){
            if(s[i] == '(') open_cnt++;
            else if(s[i] == ')') close_cnt++;

            if(open_cnt == close_cnt){
            // Primitive substring is from start to i
            // Remove outermost parentheses: (start+1 to i-1)
            ans += s.substr(start+1 ,i-start-1);
            start = i+1;//move to next primitive 
             }
        }

        
        return ans;
    }
};

//Another way of writing this code
class Solution {
public:
    string removeOuterParentheses(string s) {
        int opencnt = 0;
        string ans = "";
        int start = 0;

        for(int i = 0; i < s.size() ; i++){
            char ch = s[i];

            if(ch == '('){
                if(opencnt == 0) start = i;

                opencnt++;
            }else{
                opencnt--;
                if(opencnt == 0){
                    ans += s.substr(start+1 , i-start-1);
                }
            }
        }
         return ans;
    }
};
//T.C : O(n) 
//S.C : O(1) 

//Approach4 :using stack class Solution {
public:
    string removeOuterParentheses(string s) {
    
        stack<char> st;
        string ans;

        for(char ch : s){
            if(ch == '('){
                if(!st.empty()) ans += ch;//if not outermost , include
                st.push('(');
            }else if(ch == ')'){
                st.pop();
                if(!st.empty()) ans += ch;//if not outermost , include
                
            }
        }
        return ans;
    }
};
//T.C : O(n) 
//S.C : O(n) space for stack '
