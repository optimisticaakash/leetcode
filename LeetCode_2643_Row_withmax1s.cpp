//Approach1: bruteforce
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size(); //rows
        int n = mat[0].size();//col
        
        int rowInd = -1;
        int maxCnt = -1;
        for(int i = 0 ; i < m; i++){
            int cntrow = 0;
            for(int j = 0; j < n; j++){
                cntrow += mat[i][j];
            }

            if(cntrow > maxCnt){
                maxCnt = cntrow;
                rowInd = i;
            }
        }

        return {rowInd , maxCnt};
    }
};
//T.C : O(m*n)

//if the rows are sorted we can optimise this solution further using binary search 
