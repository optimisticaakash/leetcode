//Approach1 : bruteforce
//using map 
class Solution {
public:
    bool checkAnagram(string s1 , string s2){
        unordered_map<char,int> mpp;
        
        for(int i = 0; i < s1.size(); i++){
            mpp[s1[i]]++;
        }
        
        for(int i = 0; i < s2.size(); i++){
            mpp[s2[i]]--;
        }
        
        for(auto it: mpp){
            if(it.second != 0) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size();
        int m = p.size();

        for(int i = 0; i <= n-m; i++){
            string s1 = s.substr(i,m);
            if(checkAnagram(s1,p)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

//T.C :O(M*N)
//S.C :O(M)


//Approach2 : slinding window
class Solution {
public:
    bool allZeros(vector<int>& counter){
        for(int &i : counter){
            if(i != 0)return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<int> counter(26,0);

        for(int i = 0;i < m; i++){
            char ch = p[i];
            counter[ch-'a']++;
        }

        int l = 0 , r = 0;
        vector<int> result;

        while(r < n){
            counter[s[r]-'a']--;
            if(r-l+1 == m){
                if(allZeros(counter)){
                    result.push_back(l);
                }
                counter[s[l]-'a']++;
                l++;
            }
            r++;
        }
        return result;
    }
};
//T.C :O(M+N)
//S.C :O(26)
