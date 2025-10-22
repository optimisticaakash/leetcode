//Approach1 : using bruteforce
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int minlen  = INT_MAX;
        int Sindex = -1;

        for(int i = 0; i < n; i++){
            vector<int>hash(256,0);
            int cnt = 0;
            for(int j = 0; j < m;j++) hash[t[j]]++;;
            for(int j = i; j < n; j++){
                if(hash[s[j]] > 0){
                    cnt++;
                    hash[s[j]]--;
                }

                if (cnt == m) {
                    if (j - i + 1 < minlen) {
                        minlen = j - i + 1;
                        Sindex = i;
                    }
                    break; // stop expanding this window
                }
            }
        }

        if(Sindex == -1) return "";

        
        string ans = s.substr(Sindex , minlen);
        return ans;
        
    }
};

//T.C : O(n^2)
//S.C : O(256)

//Approach2 : using slding window
class Solution {
public:
    string minWindow(string s, string t) {
        int m = t.size();
        int n = s.size();

        int l = 0 , r = 0 ;
        int sindex = -1;
        int minlen = INT_MAX;
        int cnt = 0;

        vector<int>hash(256,0);

        for(int i = 0; i < m; i++){
            hash[t[i]]++;
        }


        while(r < n){

            if(hash[s[r]] > 0){
                cnt=cnt+1; 
            }
            hash[s[r]]--;
            while( cnt == m){
                if(r-l+1 < minlen){
                    minlen = r-l+1;
                    sindex = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }

        return sindex == -1?"":s.substr(sindex , minlen);

    }
};

//T.C :O(2N)
//S.C :O(256)
