//Approach2 : bruteforce 
class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";

        //store alpnum character only in lowercase
        for(char ch : s){
            if(isalnum(ch)){
                temp += tolower(ch);
            }
        }

        //reverse the string
        string reversed = temp;
        reverse(reversed.begin() , reversed.end());

        return reversed == temp;//return true if both are equal otherwise false
    }
};

//T.C : O(n) 
//S.C : O(d) // d = no of alphanumeric character in string

//Approach 1 : use two pointer approach 
class Solution {
public:
    bool isAlphaNum(char ch){
        if((ch >= '0' && ch <= '9') || 
            (tolower(ch) >= 'a' && tolower(ch) <= 'z')){
                return true;
            }

            return false;
    }
    bool isPalindrome(string s) {
        int n = s.size();
        int st = 0, end = n-1;

        while(st < end){
            if(!isAlphaNum(s[st])){
                st++;
                continue;//if not alphanumeric skip all operation and 
                //move to next iteration after incrementing
            }
             if(!isAlphaNum(s[end])){
                end--;
                continue;
            }
            //checking lowercase and uppercase letter of s if palindrome or not 
            if(tolower(s[st]) != tolower(s[end])){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
};

//alternative code 
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;

        while(i < j){
            char left = s[i];
            char right = s[j];

            if(!isalpha(left) && !isdigit(left)){
                i++;
                continue;
            }

            if(!isalpha(right) && !isdigit(right)){
                j--;
                continue;
            }


            if(tolower(left) != tolower(right)){
                return false;
            }
            i++;
            j--;
        }

        return true;
        
    }
};

//T.C : O(n) 
//S.C : O(1)

//Approach 2 : recursive approach 
class Solution {
public:
    bool isAlphaNum(char ch){
        // if((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && (tolower(ch)) <= 'z')){
        //     return true;
        // }
        // return false;
        return isalnum(ch);//Checks if character is alpha numeric 
                            //isalnum(ch) is a C++ standard function that returns true for [0-9], [a-z], [A-Z].
    }
    bool isPalindromeHelper(int i ,int j, string &s){
        if(i >= j) return true;

        if(!isAlphaNum(s[i]))
            return isPalindromeHelper(i+1 , j , s);

        if(!isAlphaNum(s[j]))
            return isPalindromeHelper(i , j-1 , s);
        
        if(tolower(s[i]) != tolower(s[j])) return false;
        
        return isPalindromeHelper(i+1 , j-1, s);
    }
    bool isPalindrome(string s) {
        int n = s.size();
        return isPalindromeHelper(0 , n-1 ,s);
    }
};
//T.C : O(n)
//S.C : O(n) //bcz each recursive call use stack space 
