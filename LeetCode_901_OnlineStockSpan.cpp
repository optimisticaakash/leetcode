//Approach1 : Bruteforce
class StockSpanner {
public:
    vector<int> arr;
    StockSpanner() {

    }
    
    int next(int price) {
        arr.push_back(price);
        int cnt = 1;

        for(int i = arr.size()-2; i >= 0; i--){
            if(arr[i]<= price) cnt++;
            else break;
        }
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

//T.C : Every next function takes O(number of days) 
//call 1 ->  loop runs 0 -> O(1)
//call 2 ->  loop runs 1 -> O(1)
//call 3 ->  loop runs 2 -> O(2)

//call n ->  loop runs n-1 -> O(n-1)

//T.C :O(N^2)
//S.C :O(1) 

//Approach2 : 

class StockSpanner {
public:
    stack<pair<int,int>> st;
    int ind = -1;
    StockSpanner() {
        
    }
    
    int next(int price) {
        ind = ind+1;
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }
        int ans = ind - (st.empty()?-1 : st.top().second);
        st.push({price , ind});

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

//T.C : O(2N)
//every price is push and pop obce 
///S.c : O(N) 

//WE cannot compute T.C for individual call ,in every call we dont need to pop so it can be O(1) sometimes 

