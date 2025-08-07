//Approach 0 : bruteforce 

class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int n = s.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(s[i] == t[j]) sum += abs(i - j);

            }
        }

        return sum;
    }
};

//T.C : O (n^2)
//S.C : O(1) 



//Approach1: using character hashing using 2vector
class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vector<int> sindex(26,0);
        vector<int> tindex(26,0);

        for(int i = 0; i < s.size(); i++){
            sindex[s[i]-'a'] = i;
        }

        for(int i = 0; i < s.size(); i++){
            tindex[t[i]-'a'] = i;
        }

        int sum = 0;
        for(char ch : s){
            sum += abs(sindex[ch-'a'] - tindex[ch-'a']);
        }


        return sum;
    } 
};
//T.C : O(n)
//S.C : O(1) 

//approach 2 : using only 1 vector
class Solution {
public:
    int findPermutationDifference(string s, string t) {
        //Approach 2 : using single array
        vector<int> index(26,0);

        for(int i = 0; i < s.size(); i++){
            index[s[i]-'a'] = i;
        }

        int sum = 0;
        for(int i = 0; i < t.size(); i++){
            sum += abs(i - index[t[i]-'a']);
        }


        return sum;
    } 
};
//T.C : O(n)
//S.C : O(1)

//Approach 3 : using map using for all character 
class Solution {
public:
    int findPermutationDifference(string s, string t) {
        //Approach 2 : using map
        unordered_map<char , int> sindex;

        for(int i = 0; i < s.size(); i++){
            sindex[s[i]] = i;
        }

        int sum = 0;
        for(int i = 0; i < t.size(); i++){
            sum += abs(i - sindex[t[i]]);
        }


        return sum;
    } 
};
//T.C : O(n)
//S.C : O(1) 

//if there are character more than lowercaase character then it would have worst case space complexity is O(N)

