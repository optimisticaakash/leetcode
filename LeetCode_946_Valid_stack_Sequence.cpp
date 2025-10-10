//Approach 1:
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0;
        for(int i = 0; i < pushed.size(); i++){
            st.push(pushed[i]);
            while(!st.empty() && j < popped.size() && st.top() == popped[j]){
                st.pop();
                j++;
            }
        }


        return st.empty();
    }
};
//T.C : O(n)
//S.C :O(N)


//Alternative code :
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();

        stack<int> st;

        int i = 0;
        int j = 0;

        while(i < n && j < n){
            st.push(pushed[i]);
            while(!st.empty() && st.top() == popped[j]){
                st.pop();
                j++;
            }
            i++;
        }

        return st.empty();
    }
};
//T.C :O(N)
//S.C :O(N) 
