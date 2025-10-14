//Approach1 : bruteforce generating all subarray
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        

        int maxlen = 0;

        for(int i = 0; i < n; i++){
            vector<int>mpp(256,0);
            for(int j = i; j<n; j++){
                if(mpp[s[j]] == 1)break;
                int len = j-i+1;

                maxlen = max(maxlen , len);
                mpp[s[j]]++;
            }
        }

        return maxlen;
    }
};
//T.C :O(N^2)
//S.C :O(1)

//Approach2 : better approach

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        vector<int> hash(256,-1);

        int l = 0;
        int r = 0;
        int maxlen = 0;

        while(r< n){
            if(hash[s[r]] != -1){
                if(hash[s[r]] >= l){
                    l = hash[s[r]]+1;
                }
            }

            int len = r-l+1;
            maxlen = max(maxlen , len);

            hash[s[r]] = r;
            r++;
        }

        return maxlen;
    }
};

//T.C : O(1)
//S.C : O(1)

//alternative code : using unordered_map

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        unordered_map<char,int> hash;

        int l = 0;
        int r = 0;
        int maxlen = 0;

        while(r< n){
            if(hash.find(s[r]) != hash.end()){
                if(hash[s[r]] >= l){
                    l = hash[s[r]]+1;
                }
            }

            int len = r-l+1;
            maxlen = max(maxlen , len);

            hash[s[r]] = r;
            r++;
        }

        return maxlen;
    }
};
//T.C :O(n)
//S.C :O(min(n, m)) ≈ O(1)
//m = character set size (e.g., 128 for ASCII)
