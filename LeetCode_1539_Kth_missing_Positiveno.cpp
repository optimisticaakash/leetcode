//Approach1 : brute force linear search

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();

        for(int i = 0; i < n; i++){
            if(arr[i] <= k) k++;
            else break;
        }
        return k;
    }
};
//T.C : O(n)

//Approach2: Binary Search
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();

        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = (low + high)/2;

            int missingNos = arr[mid]-(mid+1);
            if(missingNos < k) low = mid+1;
            else high = mid-1;
        }
        return k+high+1;
      //return k+low;
    }
};

//T.C : O(logN)
