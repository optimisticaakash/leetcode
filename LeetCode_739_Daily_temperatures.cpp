//Approach1 : Bruteforce
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>answer(n,0);
        
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(temperatures[j]>temperatures[i]){
                    answer[i] = j-i;
                    break;
                }
            }

        }

        return answer;
    }
};

//T.C : O(n^2)
//S.C :O(1) 

//Approach2 : using stack 
//Code 1 : using frontal traversal
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>answer(n,0);
        
        stack<pair<int,int>> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && st.top().first < temperatures[i]){
                answer[st.top().second]= i-st.top().second;
                st.pop();
            }
            st.push({temperatures[i] , i});
        }

        return answer;
    }
};
//T.C : O(n) 
//S.C :O(n) 

//code 2: end se traversal 
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>answer(n,0);
        
        stack<pair<int,int>> st;

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && temperatures[i] >= st.top().first){
                st.pop();
            }

            if(!st.empty()){
                answer[i] = st.top().second - i;
            }

            st.push({temperatures[i] , i});
        }

        return answer;
    }
};
//T.C : O(n) 
//S.C :O(2n) 

//Code3: end se traversal but strore only index
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>answer(n);
        
        stack<int> st;

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && temperatures[i] >= temperatures[st.top()]){
                st.pop();
            }

            if(st.empty()){
                answer[i] = 0;
            }else{
                answer[i] = st.top() - i;
            }

            st.push(i);
        }

        return answer;
    }
};

//T.C : O(n) 
//S.C :O(n) 
