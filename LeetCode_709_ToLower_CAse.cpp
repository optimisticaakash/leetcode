//Appraoch 1 : using stl
class Solution {
public:
    string toLowerCase(string s) {
        for(int i = 0; i < s.size(); i++){
            s[i] = tolower(s[i]);
        }

        return s;
    }
};
//T.C : tolower() takes O(1) per character
///T.C : O(n) 

//Approach2 : using ascii value 
class Solution {
public:
    string toLowerCase(string s) {
        int n = s.size();

        for(int i = 0; i < n; i++){
            if(s[i] >= 65 && s[i] <= 90){
                s[i]=s[i]+32;
            }
        }

        return s;
    }
};
class Solution {
public:
    string toLowerCase(string s) {
        int n = s.size();

        for(int i = 0; i < n; i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){//we can also use their ascii values
                s[i]=s[i]+32;
            }
        }

        return s;
    }
};

//T.C = O(n) 
