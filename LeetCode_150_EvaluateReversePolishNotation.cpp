//note : evaluate wale question me always think about stack

//Approach1: using stack
class Solution {
public:
    int evaluate(int a , int b , string op){
        if(op == "+"){
            return a+b;
        }
        if(op == "-"){
            return a-b;
        }
        if(op == "*"){
            return a*b;
        }
        return a/b;
    }

    bool isOperator(string s){
        return s == "+" or s == "-" or s == "*" or s == "/";
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;
        for(string token : tokens){
            if(isOperator(token)){//agar operatore hai to , top two elements ko pop krke operate krenge then push the evaluated number
                int b = operands.top();
                operands.pop();
                int a = operands.top();
                operands.pop();

                operands.push(evaluate(a,b , token));
            }else {
                operands.push(stoi(token));
            }
        }
        return operands.top();
    }
};

//T.C :O(N)
//S.C :O(N) ->in worst case me sare operands ho skte hai

//using lambda
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        unordered_map<string,function<int(int,int)>>mp
        ={
            {"+",[](int a,int b){return a+b;}},
            {"-",[](int a,int b){return a-b;}},
            {"*",[](int a,int b){return (long)a*(long)b;}},
            {"/",[](int a,int b){return a/b;}}
        };

        for(string &token: tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                //top 2 elements ko pop krke operate krlo
                //then push in stack the resutk

                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                int result = mp[token](a,b);

                st.push(result);
            }else{
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};

//T.c :O(N)
//S.C :O(N) 
