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

//Approach 3 : optimal 

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();// no of row
        int m = matrix[0].size();// no of col

        //col marker = matrix[..][j]   
        //row marker = matrix[i][0]
        int col0 = 1;
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    //mark the ith row
                    matrix[i][0] = 0;
                    //mark the jth col
                    if(j != 0)
                        matrix[0][j] = 0;
                    else
                        col0 = 0;

                }
            }
        }

        //now mark the nonzero elements 
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(matrix[i][j] != 0){
                    //check for row and col
                    if(matrix[i][0] == 0 || matrix[0][j] == 0){
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        if(matrix[0][0] == 0){
            for(int j = 0; j < m; j++) matrix[0][j] = 0;
        }
        if(col0 == 0){
            for(int i = 0; i < n; i++){
                matrix[i][0] = 0;
            }
        }
    }    
};

//T.C = O(2*m*n)
//S.C = O(1)
