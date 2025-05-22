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
