//Approach 1 : linear approach 
class Solution {
public:
    int daysReq(vector<int> & weights, int cap){
        int day = 1; 
        int load = 0;

        for(int i = 0; i < weights.size() ; i++){
            if(load + weights[i] > cap){//agar total load cap se jyada hai to agle din ship krenge
                day++;
                load = weights[i];
            }else{
                load += weights[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n  = weights.size();
        int maxi = 0 , sum = 0;
        for(int i = 0; i < n; i++){
            if(weights[i]>maxi) maxi=weights[i];
            sum += weights[i];
        }


        for(int i = maxi; i <= sum; i++){
            int noofDays = daysReq(weights,i);
            if(noofDays <= days) return i; 
        }

        return -1;

    }
};

//T.C : O( (sum-max+1) * n) = O(n^2)
//S.C : O(1) 

//Appraoch2: optimal (binary Search)
class Solution {
public:
    int daysReq(vector<int> & weights, int cap){
        int day = 1; 
        int load = 0;

        for(int i = 0; i < weights.size() ; i++){
            if(load + weights[i] > cap){//agar total load cap se jyada hai to agle din ship krenge
                day++;
                load = weights[i];
            }else{
                load += weights[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n  = weights.size();
        int maxi = 0 , sum = 0;
        for(int i = 0; i < n; i++){
            if(weights[i]>maxi) maxi=weights[i];
            sum += weights[i];
        }
         int low = maxi;
         int high = sum;

         while(low <= high){
            int mid = low+(high-low)/2;

            if(daysReq(weights,mid) <= days){
                high= mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;

    }
};
//T.C : O(log(sum-max+1)) * O(n) 
//S.C : O(1)
