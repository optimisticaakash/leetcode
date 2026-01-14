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


//Approach 3 : naive appraoch
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int num = 1;
        int i = 0;

        while(i < n && k > 0){
            if(arr[i] == num){
                i++;
            }else{
                k--;
            }
            num++;
        }

        //if case 
        //arr = [1,2,3] k = 2
        // 4 , 5  
        //so 5 is the 2nd missing number

        while(k>0){
            num++;
            k--;
        }

        return num-1; 
        //num ko har iteration ke end me increment kiya ja raha hai.
        // Jab k-th missing milta hai, num already next number par hota hai,
        // isliye correct missing number num - 1 hota hai."
    }
};

//T.C : O(N+K)
