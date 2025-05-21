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
