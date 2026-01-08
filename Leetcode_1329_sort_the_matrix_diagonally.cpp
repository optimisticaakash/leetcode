//Approach 1 : using [i-j] to traverse 
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();//row
        int m = mat[0].size(); //col

        unordered_map<int,vector<int>> mp;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                mp[i-j].push_back(mat[i][j]);
            }
        }

        //sort krenge map me jo elements hai unhe 
        for(auto &it : mp){
            sort(it.second.begin() , it.second.end());
        }

        //now put them back in sorted fashion in backward order

        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                mat[i][j] = mp[i-j].back();

                mp[i-j].pop_back();
            }
        }

        return mat;


    }
};

//T.C : O(n*m)
//S.C : O(n*m)
