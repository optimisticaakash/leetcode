//Approach1 : bruteforce
//Code1:
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxlen = 0;

        for(int i = 0; i < n; i++){
            unordered_map<char , int> st;
            int maxfreq = 0;
            int changes = 0;
            for(int j = i; j < n; j++){

                st[s[j]]++;
                maxfreq = max(maxfreq , st[s[j]]);
                changes = (j-i+1) - maxfreq;
                if(changes <=  k){
                    int len = j - i+1;
                    maxlen = max(maxlen , len);
                }else{
                    break;
                }
            }
        }

        return maxlen;
    }
};

//code2: using vector to store frequency
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxlen = 0;

        for(int i = 0; i < n; i++){
            vector<int> st(26,0);
            int maxfreq = 0;
            int changes = 0;
            for(int j = i; j < n; j++){

                st[s[j] - 'A']++;
                maxfreq = max(maxfreq , st[s[j]-'A']);
                changes = (j-i+1) - maxfreq;
                if(changes <=  k){
                    int len = j - i+1;
                    maxlen = max(maxlen , len);
                }else{
                    break;
                }
            }
        }

        return maxlen;
    }
};

//T.C :O(N^2)
//S.C : O(1)

//Approach2 : slidingwindow/twopointer
//Alternative code - 
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0 , r = 0 , maxlen = 0 , maxfreq = 0;

        vector<int> mpp(26,0);

        while(r < n){
            mpp[s[r]-'A']++;
            maxfreq = max(maxfreq , mpp[s[r]-'A']);
            while((r - l + 1)-maxfreq > k){
                mpp[s[l]-'A']--;
                maxfreq = 0;
                for(int i = 0; i < 26; i++) 
                    maxfreq = max(maxfreq , mpp[i]);

                l++;
            }
            if((r - l + 1)-maxfreq <= k){
                maxlen = max(maxlen , r-l+1);
            }
            r++;
        }

        return maxlen;
    }
};
//T.C :O(N+N) * 26
//S.C :O(26)

//Alternative code
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0 , r = 0 , maxlen = 0 , maxfreq = 0;

        vector<int> mpp(26,0);

        while(r < n){
            mpp[s[r]-'A']++;
            maxfreq = max(maxfreq , mpp[s[r]-'A']);
            if((r - l + 1)-maxfreq > k){
                mpp[s[l]-'A']--;
                maxfreq = 0;
                l++;
            }
            if((r - l + 1)-maxfreq <= k){
                maxlen = max(maxlen , r-l+1);
            }
            r++;
        }

        return maxlen;
    }
};
//T.C :O(n)
//S.C :O(26)
