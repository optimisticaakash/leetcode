//Approach 1 : bruteforce
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

//Approach2:  better solution
class Solution {
public:
    bool BinarySearch(vector<int> &arr , int target){
        int m = arr.size();
        int low = 0;
        int high = m-1 ;
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

        for(int  i = 0; i < n; i++){
            if(BinarySearch(matrix[i] , target)) return true;
        }
        return false;
    }
};

//T.C : O(n*log2m)

//Approach3: optimal solution
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();//row
        int m = matrix[0].size();//col

        int row = 0;
        int col = m-1;

        while(row < n && col >= 0){
            if(matrix[row][col] == target) return true;
            if(matrix[row][col] < target) row++;
            else col--;
        }
        return false;
    }
};
//T.C : O(m+n)
