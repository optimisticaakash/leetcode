//Approac1 : generate all possible rotation of string s
//code2:
class Solution {
public:
    bool rotateString(string s, string goal) {
        //generateing all possible string
        int n = s.size();

        while(n >= 0){

            if(s == goal) return true;
            char last = s.back();
            s.pop_back();

            s = last + s;
            n--;
        }
        return false;
    }
};
//T.C : O(n^2)
//S.C : O(n)

//Code2:
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        int m = goal.size();

        if(n != m) return false;

        for(int cnt =1; cnt <= n; cnt++){
            rotate(s.begin() , s.begin()+1,s.end());
             //after rotation of s by one shift
            if(s == goal) return true;
        }

        return false;
    }
};
//T.C : O(n^2)
//S.C : O(1) 

//Approach2: by concatenate s to itself , when we concatenate a string to itself then resulting string contains all the rotation of s as substring
class Solution {
public:
    bool rotateString(string s, string goal) {
        //using built-in function 
        if(s.size() != goal.size()) return false;
        s += s;

        if(s.find(goal) != string::npos) return true;
        return false;
    }
};
//T.C : O(n)
//S.C : O(2n)
