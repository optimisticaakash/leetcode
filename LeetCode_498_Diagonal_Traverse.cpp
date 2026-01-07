//solve leetcode 1329 for better logic understanding
//Approach1 : using [i+j] for traversing

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        map<int, vector<int>> mp;

        vector<int>result;


        //fill the map using [i+j]

        for(int i = 0; i < n; i++){ //O(m*n)
            for(int j = 0; j < m; j++){
                mp[i+j].push_back(mat[i][j]); //map(ek balanced bst) me insertion - O(log(n+m)) 
            }
        }

        bool flip = true;
        for(auto &it : mp){
            if(flip){
                //it.second ko reverse kardo
                reverse(it.second.begin() , it.second.end());
            }

            for(int &num: it.second){
                result.push_back(num);
            }

            flip = !flip;
        }

        return result;
    }
};

//T.C - O(nm · log(n + m))
//S.C - O(n × m)
