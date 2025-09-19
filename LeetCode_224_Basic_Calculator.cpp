//Approach : using stack 
class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        stack<int> st;
        
        int num = 0;
        int result = 0;
        int sign = 1;

        for(int i = 0;i < n; i++){
            if(isdigit(s[i])){
                num = num * 10 + (s[i]-'0');//jbtk num mile , num bnate chlo
            }else if(s[i] == '+'){
                //number ban chuka hoga , add in result;
                result = result + (num * sign);
                num = 0;
                sign = 1;
            }else if(s[i] == '-'){
                //number ban chuka hoga , add in result
                result = result + (num * sign);
                num = 0;
                sign = -1;
            }else if(s[i] == '('){
                //bracket start , naya result bnaye , purana result and sign stack me dalenge
                st.push(result);
                st.push(sign);
                num = 0;
                result = 0;
                sign = 1;
            }else if(s[i] == ')'){
                //braket  end 
                result = result + (num * sign);
                num = 0;
                int stack_sign = st.top();
                st.pop();

                int last_result = st.top();
                st.pop();

                result *= stack_sign;
                result += last_result;
            }
        }
        //eg 1 - 2 + 3;//isme 3 ke baad koi sign nhi hai to woh num me hi rh jata result me add nhi hota 
        result += (num * sign);

        return result;
    }
};

//T.C  : O(N) 
//S.C : O(N) 
