//Approach 1 : Bruteforce 
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> ans(n , vector<int> (n));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ans[j][n-1-i] = matrix[i][j];
            }
        }


        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                matrix[i][j] = ans[i][j];
            }
        }
    }
};

//T.C : O(n*n)
//S.c ; O(n*n)

//Approach2 : optimal (in place)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        //matrix ka transpose krna
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                swap(matrix[i][j] , matrix[j][i]);
            }
        }

        //uske baad trasposed matrix ke har row ko reverse krna
        for(int i  = 0; i < n; i++){
            // row is matrix[i] 
            //col i matrix[i][j]
            reverse(matrix[i].begin() , matrix[i].end());
        }
    }
};

//T.C = o(n*n)
