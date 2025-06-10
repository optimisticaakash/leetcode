//Approach 1 : Brute force 
//Code: 
class Solution {
public:
    void Markrow(vector<vector<int>>& matrix , int n , int m , int i){
        //Set all the non zero element to -1 in row i 
        for(int j = 0; j < m; j++){
            if(matrix[i][j] != 0){
                matrix[i][j] = -1;
            }
        }
    }
    void Markcol(vector<vector<int>>& matrix , int n , int m , int j){
        //Set all the non zero element to -1 in col j 
        for(int i = 0; i < n; i++){
            if(matrix[i][j] != 0){
                matrix[i][j] = -1;
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(); //row
        int m = matrix[0].size();//col

        //iterating through matrix and make 0's to -1
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    Markrow( matrix , n , m , i);
                    Markcol( matrix , n , m , j);
                }
            }
        }

        //iterating through matrix and make -1's to 0s again
        for(int i = 0; i  < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == -1){
                    matrix[i][j] = 0;
                }
            }
        }


    }
};

//T.C = O(m*n) * (m+n) + O(m*n) = o(n^3)
//S.C = O(1)

//Approach 2: Better approach 

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();//row
        int m = matrix[0].size();//col

        vector<int> row(n,0);
        vector<int> col(m,0);

        //mark row and col
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        //marked row and col ko zero banana 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(row[i] == 1 || col[j] == 1){
                    matrix[i][j] = 0;
                }
            }
        }


    }
};

//T.C = O(n*m)= O(n^2)
//S.c = O(n+m)
