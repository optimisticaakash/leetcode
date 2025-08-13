//Approach1 : using unordered_map + unordered_set
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char , int> mpp;

        for(char ch : s){
            mpp[ch]++;
        }


        unordered_set<int> st;

        for(auto &it : mpp){
            st.insert(it.second);
        }

        return st.size()==1;
    }
};

//T.C : O(N) 
//S.C : O(N) 

//Approach2 : USING MAP 

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char , int> mpp;

        for(char ch : s){
            mpp[ch]++;
        }

        int freq = mpp.begin()->second;
        unordered_set<int> st;

        for(auto &it : mpp){
            if(it.second != freq) return false;
        }

        return true;
    }
};
//T.C  : O(N) 
//S.C : O(N) 

//Approach3 : using  freq array of 26 size
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int freq[26] = {0};

        for(char ch : s){
            freq[ch-'a']++;
        }
        int target = 0;
        for(int it : freq){
           
            if(it!= 0){
                if(target == 0) target = it;
                else if(target  != it)return false;
            }
        }

        return true;
    }
};

//T.C : O(n) 
//S.C : O(1)
