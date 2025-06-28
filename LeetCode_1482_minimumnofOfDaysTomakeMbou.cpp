//approach1:  using linear search
class Solution {
public:
    bool possible(vector<int>& arr,int day , int m , int k){
        int cnt = 0; 
        int noOfB = 0;

        for(int i = 0; i < arr.size(); i++){
            if(arr[i] <= day){
                cnt++;
            }
            else{
                noOfB += (cnt/k);
                cnt = 0;
            }
        }
        noOfB += (cnt/k);

        if(noOfB >= m) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if(n < (m*k)) return -1;
        int mini = *min_element(bloomDay.begin() , bloomDay.end());
        int maxi = *max_element(bloomDay.begin() , bloomDay.end());

        for(int i = mini ; i <= maxi; i++){
            if(possible(bloomDay,i,m,k) == true) return i;
        } 
        return -1;
    }
};

//T.C : O(max-min+1) * O(n) 

//Approach2 : using binary search 
class Solution {
public:
    bool possible(vector<int>& arr,int day , int m , int k){
        int cnt = 0; 
        int noOfB = 0;

        for(int i = 0; i < arr.size(); i++){
            if(arr[i] <= day){
                cnt++;
            }
            else{
                noOfB += (cnt/k);
                cnt = 0;
            }
        }
        noOfB += (cnt/k);

        if(noOfB >= m) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if(n < (long long)m*k) return -1;
        int mini = *min_element(bloomDay.begin() , bloomDay.end());
        int maxi = *max_element(bloomDay.begin() , bloomDay.end());

        int low = mini;
        int high = maxi;
        int ans = -1;

        while(low <= high){
            int mid = (low+high)/2;

            if(possible(bloomDay,mid,m,k)){
                ans = mid;
                high = mid-1; //check for smallest
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};
//T.C : O(log(max-min_1)) * O(n) 

//Alterante code : return low 
class Solution {
public:
    bool possible(vector<int>& arr,int day , int m , int k){
        int cnt = 0; 
        int noOfB = 0;

        for(int i = 0; i < arr.size(); i++){
            if(arr[i] <= day){
                cnt++;
            }
            else{
                noOfB += (cnt/k);
                cnt = 0;
            }
        }
        noOfB += (cnt/k);

        if(noOfB >= m) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if(n < (long long)m*k) return -1;
        
        int maxi = *max_element(bloomDay.begin() , bloomDay.end());
        int mini = *min_element(bloomDay.begin() , bloomDay.end());

        int low = mini;
        int high = maxi;

        while(low <= high){
            int mid = (low+high)/2;

            if(possible(bloomDay,mid,m,k)){

                high = mid-1; //check for smallest
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};
//T.C : O(log(max-min_1)) * O(n) 
