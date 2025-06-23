//Approach : brute force : linear search

class Solution {
public:
    int mySqrt(int x) {
        int ans = 0;

        for(long i = 0; i <= x ; i++){
            if(i*i <= x){
                ans = i;
            }else {
                return ans;
            }
        }

        return ans;
    }
};

//alternate solution:

class Solution {
public:
    int mySqrt(int x) {
        int ans = 0;

        if(x==1) return 1;

        for(long i = 0; i <= x/2 ; i++){
            if(i*i <= x){
                ans = (int)i;
            }else {
                return ans;
            }
        }

        return ans;
    }
};

//T.C : O(n/2)

//Approach2: binary search 
int floorSqrt(int n)
{
    // Write your code here.
    if(n==0) return 0;
    int ans = 1;
    int low = 1 , high = n/2;
    
    

    while(low <= high){
        long long mid = (low+high)/2;
        long long val = mid*mid;

        if(val <= n){
            ans = mid;
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return ans;
}


//alternate
class Solution {
public:
    int mySqrt(int x) {
        int low = 1 ,  high = x/2;
        int ans = 1;

        if(x==0) return 0;

        while(low <= high){
            int mid = low+(high-low)/2;
            if((mid <= x/mid)){
                ans = mid;
                low = mid+1;
            }else
                high = mid-1;
        }
        return ans;
    }
};
//T.C : O(logn)
