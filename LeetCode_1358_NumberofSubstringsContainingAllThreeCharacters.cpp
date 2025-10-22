//Approach1:bruteforce
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        int cnt = 0;
        for(int i = 0; i < n; i++){
            vector<int>hash(3,0);
            for(int j = i; j < n; j++){
                char ch = s[j];
                hash[ch-'a']++;
                if(hash[0]>0 && hash[1]>0 && hash[2] >0){
                    cnt += (n-j);
                    break;
                }
            }
        }

        return cnt;
    }
};
//T.C :O(n^2)
//S.C :O(1)

//Approaoch2 : using sw
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int cnt = 0;

        int i = 0 , j = 0;
        vector<int>hash(3,0);

        while(j < n){
            char ch = s[j];
            hash[ch-'a']++;

            while(hash[0]>0 && hash[1]>0 && hash[2]>0){
                cnt += (n-j);
                hash[s[i]-'a']--;
                i++;
            }
            j++;
        }

        return cnt;
    }
};
//T.C :O(n)
//S.c : O(1)

//Approach3 : alternative o(1) solution
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        vector<int> hash(3,-1);
        int cnt = 0;

        for(int i = 0; i < n; i++){
            char ch = s[i];
            hash[ch-'a'] = i;
            if(hash[0]!= -1 && hash[1]!= -1 && hash[2]!= -1){
                cnt += 1+min(hash[0],min(hash[1],hash[2]));
            }
        }
        return cnt;
    }
};
//t.C :O(N)
//s.C :O(1)
