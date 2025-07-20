//Approach1 :using sorting
class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(n != m)return false;

        sort(s.begin() , s.end());
        sort(t.begin() , t.end());

        //after sorting if both are equal anagram of each other
        if(s == t)return true;

        return false;
    }
};
//T.C : O(nlogn + mlogm)
//S.C : O(1)

//Approach2 : using map 
class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();

        unordered_map<char,int> mp1;

        for(char ch : s){
            mp1[ch]++;
        }

        for(char ch : t){
            mp1[ch]--;
        }

        for(auto it : mp1){
            if(it.second != 0)return false;//character mismatch
        }

        return true;
    }
};

//T.C : O(n)
//S.C : O(n)

//Approach3: using vector
class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(n != m) return false;

        vector<int> arr(26,0);

        for(char ch : s){
            arr[ch-'a']++;
        }

        for(char ch : t){
            arr[ch-'a']--;
        }

        for(int it : arr){
            if(it != 0) return false;
        }

        return true;
    }
};

//lambda function to check all character freequency 0 or not
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count(26,0);

        for(char &ch : s){
            count[ch-'a']++;
        }

        for(char &ch : t){
            count[ch-'a']--;
        }

        //check if all elements in count are zero
        //for loop

       bool allZeros = all_of(begin(count) , end(count) , [](int element) {
        return element == 0;
       });

       return allZeros;
        
    }
};
//T.C : O(n)
//S.C : O(1)
