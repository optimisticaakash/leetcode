//Approach1:
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();

        vector<int> indexx;
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words[i].size(); j++){
                if(words[i][j] == x) {
                    indexx.push_back(i);
                    break;
                }
                
            }            
        }
        return indexx;
    }
};

//Approach2:
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();

        vector<int> result;

        auto lambda = [&x](char ch){
            return ch==x;
        };
        for(int i = 0; i < n ; i++){
            if(any_of(words[i].begin() , words[i].end() , lambda)){
                result.push_back(i);
            }
        }
        return result;
    }
};

//T.C :O(n*m)
//S.C : O(m)
