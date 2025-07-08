//Approach1: using bruteforce 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();//row
        int m = matrix[0].size();//col

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == target) return true;
            }
        }

        return false;
    }
};

//T.C : O(m*n)

//Approach2: 
class Solution {
public:
    bool BinarySearch(vector<int> &arr , int target){
        int n = arr.size();
        int low = 0;
        int high = n-1 ;
        int ans = INT_MIN;
        while(low <= high){
            int mid = (low+high)/2;

            if(arr[mid] == target){
                return true;
            }else if(arr[mid]>target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }   
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i = 0; i < n; i++){
            if(matrix[i][0] <= target && matrix[i][m-1] >= target){
                return BinarySearch(matrix[i] , target);
            }
        }

        return false;
    }
};
//T.C : O(n+logm)

//Approach3: using binary search class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0 , high = (n*m)-1;

        while(low <= high){
            int mid = (low + high)/2;
            
            int row = mid/m;
            int col = mid%m;

            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
};
//T.C : O(log(m*n))
