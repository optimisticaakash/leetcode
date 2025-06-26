//Approach1: using loops 

//code : 
class Solution {
public:
    int calTotaltime(vector<int>& piles,int n ,int hourly){
        int totalhrs = 0;
        for(int i = 0; i< n; i++){
            totalhrs += ceil((double)(piles[i]/hourly));
        }
        return totalhrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxi = 0;
        for(int i = 0; i < n; i++){
            maxi = max(piles[i] , maxi);
        }

        for(int k = 1; k <= maxi ; k++){
            int reqTime = calTotaltime(piles,n,k);
            if(reqTime <= h)return k;
        }

        return -1;
    }
};

//T.C : O(max(piles) * n) gives tle for large values 
