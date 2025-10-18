//Approach1 : Bruteforce
//Code: using maps 
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maxlen = 0;

        for(int i = 0; i < n; i++){
            unordered_map<int , int> mpp;
            for(int j = i; j < n; j++){
                mpp[fruits[j]];
                if(mpp.size() <= 2){
                    int len = j-i+1;
                    maxlen = max(maxlen , len);
                }
                
            }
        }

        return maxlen;
    }
};


//Code2: using set
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maxlen = 0;

        for(int i = 0; i < n; i++){
            unordered_set<int> mpp;
            for(int j = i; j < n; j++){
                mpp.insert(fruits[j]);  
                if(mpp.size() <= 2){
                    int len = j - i + 1;
                    maxlen = max(maxlen, len);
                } else {
                    break;
                }
            }
        }
        return maxlen;
    }
};

//T.C : O(n^2)
//S.C : O(1)

//Approach2 : sliding/window
//alternative code : 
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0, r = 0, maxlen = 0;

        unordered_map<int, int> mpp;

        while(r < n){
            mpp[fruits[r]]++;
            if(mpp.size() > 2){
                while(mpp.size() > 2){
                    mpp[fruits[l]]--;
                    if(mpp[fruits[l]] == 0) mpp.erase(fruits[l]);
                    l++;
                }
            }
            if(mpp.size() <= 2){
                int len = r - l + 1;
                maxlen = max(maxlen , len);
            }
            r++;
        }

        return maxlen;
    }
};
//T.C :O(2N)
//S.C :O(1)

//Alternative code : single pass
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0, r = 0, maxlen = 0;

        unordered_map<int, int> mpp;

        while(r < n){
            mpp[fruits[r]]++;
            if(mpp.size() > 2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]] == 0) mpp.erase(fruits[l]);
                l++;
            }else{//if(mpp.size() <= 2)
                int len = r - l + 1;
                maxlen = max(maxlen , len);
            }
            r++;
        }

        return maxlen ;
    }
};
//T.C :O(N)
//S.C :O(1)
