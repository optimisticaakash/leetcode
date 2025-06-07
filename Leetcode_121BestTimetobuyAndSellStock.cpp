//Approach1: Bruteforce
/*
NOTES: 
1)we have to buy first and then sell
2) buy and sell can only be done once
3) We have to return profit has to maximum 

so we need track of every possibility of making profit , maintain a variable to maintain max profit
*/
//Code : 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        //buy phle hi krna hai , sell baad me 
        int n = prices.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n;j++){
                maxprofit = max(maxprofit , prices[j]-prices[i]);
            }
        }

        return maxprofit;
    }
};
//T.C : O(n^2)
//S.C = O(1) but wont work due to constraint

//Approach2: optimal approach 
//for maximizing profit , we need to track of minimum price for every 
// and we need to make track of profit for every price 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int mini = prices[0];
        int profit = 0;

        for(int i = 1; i < n; i++){
            int cost = prices[i]- mini;
            profit = max(profit , cost);
            mini = min(mini , prices[i]);
        }

        return profit; 
    }
};

//Alternative code :
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int  n = prices.size();
        int minbuy = INT_MAX;
        int profitsell = 0;
        for(int i = 0; i < n; i++){
            if(minbuy > prices[i]){
                minbuy=prices[i];
            }else{
                profitsell = max(profitsell , prices[i] - minbuy);
            }
        }

        return profitsell;
    }
};

//T.C = O(n)
//S.C = O(1)
