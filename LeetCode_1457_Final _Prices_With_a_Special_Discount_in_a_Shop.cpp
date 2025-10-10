//IN This problem we have given an array where of prices , and we need to find discount price for each prices
//for finding discount price we need to find next smaller element on the right and then subtract from the original price

//Bruteforce :
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int>answer(n,0);

        for(int i = 0; i < n;i++){
            answer[i] = prices[i];//if next smaller in right not exist 
            for(int j = i+1; j < n;j++){
                if(prices[j] <= prices[i]){
                    answer[i] = prices[i]- prices[j];
                    break;
                }
            }
        }

        return answer;
    }
};

//T.C :O(N^2)
//S.C :O(1)

//Approach2 Using stack 
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> st;
        vector<int>answer(n , 0);

        for(int i = n-1; i >=  0; i--){
            while(!st.empty() && prices[st.top()] > prices[i]){
                st.pop();
            }

            if(st.empty()){
                answer[i] = prices[i];
            }else{
                answer[i] = prices[i]-prices[st.top()];
            }

            st.push(i);
        }

        return answer;
    }
};

//T.C :O(N)//every element push and pop once 
//S.C :(O(N)
