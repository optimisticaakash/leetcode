//Approach1 : using unordered map 
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //ascii total 256 character , we can also take array 

        unordered_map<char,char> mp1;
        unordered_map<char,char> mp2;

        int n = s.size();

        for(int i = 0; i < n ; i++){
            char ch1 = s[i];
            char ch2 = t[i];

            if(mp1.find(ch1) != mp1.end() && mp1[ch1] != ch2
            || mp2.find(ch2) != mp2.end() && mp2[ch2] != ch1){
                return false;
            }

            mp1[ch1] = ch2;
            mp2[ch2] = ch1;
        }

        return true;
    }
};

//T.C : O(n) 
//S.C : O(1) 
//slightly  slower than vector method

//Approach 2 : using vector 
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //ascii total 256 character , we can also take array 

        vector<int> map1(256,-1);
        vector<int> map2(256,-1);

        int n = s.size();

        for(int i = 0; i < n ; i++){
            char ch1 = s[i];
            char ch2 = t[i];
            

            
            if(map1[ch1] != -1 && map1[ch1] != ch2
            || map2[ch2] != -1 && map2[ch2] != ch1){
                return false;
            }

            map1[ch1] = ch2;
            map2[ch2] = ch1;
        }

        return true;
    }
};

//T.C : O(n)
//S.C : O(1) 
