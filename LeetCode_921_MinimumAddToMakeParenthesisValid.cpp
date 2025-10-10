//Approach1 : using stack
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int open = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(s[i]);
            }else{
                if(!st.empty()){
                    st.pop();
                }else{
                    open++;
                }
            }
        }


        return st.size()+open;
    }
};

//T.C :O(N)
//S.C :O(N)

//Approach 2 : without stack
class Solution {
public:
    int minAddToMakeValid(string s) {
        int n =s.size();

        int size = 0;
        int open = 0;

        for(int i = 0;i < n; i++){
            if(s[i] == '('){
                size++;
            }else if(size > 0){
                size--;
            }else{
                open++;
            }
        }

        return size + open;
    }
};

//T.C :O(N)
//S.C :O(1)
