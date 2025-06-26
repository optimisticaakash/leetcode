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
//optimalApproach : 

int Findmax(vector<int> v){
    int n = v.size();
    int maxi = 0;
    for(int i = 0; i < n; i++){
        maxi = max(v[i] , maxi);
    }
    return maxi;
}
long long calTotaltime(vector<int> & v,int mid){
    int n = v.size();
    long long totalhr = 0;
    for(int i = 0; i < n;i++){
        totalhr += ceil((double)v[i]/(double)mid);
    }
    return totalhr;
}
int minimumRateToEatBananas(vector<int> &v, int h) {
    // Write Your Code Here
    int low = 1; 
    int high = Findmax(v);

    while(low <= high){
        int mid = (low + high)/2;

        long long totalH = calTotaltime(v,mid);
        if(totalH <= h){
            high = mid-1;
        }else{
            low = low+1;
        }
    }
    return low;
}

//alternate using stl : 
class Solution {
public:
   
    long long calTotaltime(vector<int>& piles,int hourly){
        
        long long totalhrs = 0;
        int n = piles.size();
        for(int i = 0; i < n; i++){
            totalhrs += ceil((double)piles[i]/(double)hourly);
        }
        return totalhrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        

        int low = 1;
        int high = *max_element(piles.begin() , piles.end());
        int ans = 0;
        while(low<= high){
            int mid = low + (high-low)/2;
            long long totalhrs = calTotaltime(piles , mid);
            
            if(totalhrs<= h){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return ans;
    }
};

//T.C : O(maxele * logn)
