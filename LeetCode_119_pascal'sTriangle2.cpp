//rowindex given hai 0based indexing ka row deni hai 
//Approach 1 : 
class Solution {
public:
    int NcR(int n , int r){
        long long  res = 1;
        for(int i = 0; i < r ;i++){
            res = res*(n-i);
            res = res/(i+1);
        }
        return res;
    }
    vector<int> getRow(int rowIndex) {
        int n = rowIndex;
        vector<int> rowEle;

        for(int c = 0; c <= n; c++){
            //row-1Ccol-1 but here already 0 idexed hai to simple we can 
            rowEle.push_back(NcR(n , c));
        }

        return rowEle;
    }
};
//T.C : O(n^2)

//Approach2: row nikalenge sidha or dalenge vector me 
//Current element = prevElement * (rowNumber - colIndex) / colIndex

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        //0 based indexing hai to rowno = rowindex + 1

        int n= rowIndex+1;
        vector<int> row;
        long long ans = 1;
        row.push_back(ans);//we know 0th col element is 1

        for(int i = 1; i <n; i++){
            ans = ans*(n-i);
            ans = ans/i;
            row.push_back(ans);
        }

        return row;
    }
};
//T.C + O(n) 

//Approach3: pura generate kreke pascle jo row mangi hai woh dedo 
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> result(rowIndex+1);

        //0 based indexing hai or hum rowIndex wala row chahiye 
        for(int i = 0; i < rowIndex +1 ; i++){
            result[i] = vector<int>(i+1 , 1);
            for(int j = 1; j<i; j++){
                result[i][j] = result[i-1][j]+result[i-1][j-1];
            }
        }
        return result[rowIndex];
    }
};
//T.C : O(n^2)
//S.C : O(n^2)

//Approach 4 : hum koi bhi row nikalne ke liye bas uske prev row ki need hai to bas wohi generate krenge or prev row update krte jyegen curr row se 
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev;

        //0 based indexing hai or hum rowIndex wala row chahiye 
        for(int i = 0; i < rowIndex +1 ; i++){
            vector<int>curr(i+1,1);
            for(int j = 1; j<i; j++){
                curr[j] = prev[j]+prev[j-1];
            }
            prev = curr;
        }
        return prev;
    }
};
//T.c  + O(n^2)
