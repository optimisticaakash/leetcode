//Approach1 : Bruteforce 

//in this approach we are generating element for every row and col and then storing 
//Code:
class Solution {
public:
    int nCr(int n , int r){//O(n)
        long long res = 1;
        for(int i = 0; i < r; i++){
            res = res * (n-i);
            res = res/(i+1);
        }
        return res;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        int n = numRows;
        for(int row = 1; row <= n;row++){//O(n^2)
            vector<int> temp;
            for(int col = 1; col <= row; col++){
                temp.push_back(nCr(row-1 , col-1));//->O(n)
                
            }
            ans.push_back(temp);
        }

        return ans;
    }
};

//T.C : O(n*r) = O(n^3)

//Approach2: optimal
//using this formula : Current element = prevElement * (rowNumber - colIndex) / colIndex

//in this approach we will generate row which taked O(n)
//and there are n rows so T.C : O(n2)

class Solution {
public:
    vector<int> generateRow(int row){
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1);
        for(int col = 1; col < row; col++){
            ans = ans *(row-col);
            ans = ans/col;
            ansRow.push_back(ans);
        }
        return ansRow;

    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 1; i<= numRows ; i++){
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};
//Approach3: jo bola whi krdiya 
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);//numRows size of vector

        for(int i = 0; i < numRows; i++){
            result[i] = vector<int>(i+1 , 1); //i+1 size ka banaya kyonki col ka size nthrow index + 1 , sbko 1 kr diya 


                //col me 1st col(0th ) and last col(numRow-1)th index col me 1 chahiye 
                //already hai to whan nhi change krenge
                //isliye loop 1 se i-1 tk jaa rha 
          
            for(int j = 1; j < i; j++){
                result[i][j] = result[i-1][j] + result[i-1][j-1];
            }
        }
        return result;
    }
};

//T.C : O(n2)
