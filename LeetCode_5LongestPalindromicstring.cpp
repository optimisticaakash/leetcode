//Approach1 : using brute force 
//genearating all the substring calculate length and update if length is greater than previous substing
//Code:
class Solution {
public:
//  function for checking if current string is palindrome or not
    bool checkPal(string &s , int low , int high){
        while(low < high){

            if(s[low] != s[high]) return false;

            low++;
            high--;
        }
        return true;
    }
    string longestPalindrome(string &s) {
        int n = s.size();
        //all substring of length of 1 is palindrome
        int maxlen = 1 , start = 0;

        //for start and end index 
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){

                //check if current substring is palindrome 
                if(checkPal(s,i,j) && (j-i+1) > maxlen){
                    start = i;
                    maxlen = j-i+1;
                }
            }
        }

        return s.substr(start , maxlen);
    }
};
//T.C : O(n^3)
//S.C : O(n) for returning output only no extra space used

//Approach2 : using 2 pointer expansion from center
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        if(n <= 1) return s;
        string lps = "";
        for(int i = 0; i < n; i++){
            //for odd length
            int low = i;
            int high = i;

            while( (low >= 0 && high < n) && s[low] == s[high]){
                low--;
                high++;
            }

            string palindrome = s.substr(low+1 , high - low -1);
            if(palindrome.size() > lps.size()){
                lps=palindrome;
            }

            //for even length
            low = i;
            high = i+1;
            while((low >= 0 && high < n) && s[low] == s[high]){
                low--;
                high++;
            }

            palindrome = s.substr(low +1, high-low-1);
            if(palindrome.size() > lps.size()){
                lps = palindrome;
            }

        }

        return lps;
    }
};

//Alternative code :
class Solution {
public:
//using two pointer expanding but different code

    string longestPalindrome(string s) {
        int n = s.size();
        if(n <= 1) return s;

        int start = 0;
        int maxlen = 1;//1 length bhi palindromic hoti hai 

        //traverse krenge through each character for odd and even 
        for(int i =0 ; i < n ; i++){

            //for both odd and even length string hum loop chlenge 0 to 1 
            //ye loop bas 2 bar chlege or odd (j= 0 ) and even(j = 1)
            for(int j = 0; j <= 1; j++){
                int low = i;
                int high = i+j;

                while((low >= 0 && high < n ) && s[low] == s[high]){
                    //jo bhi string hai uski length nikalenge

                    int currlen = high - low +1;
                    if(currlen > maxlen){
                        start = low;
                        maxlen = currlen;
                    }
                    low--;
                    high++;
                }
            }
        }

        return s.substr(start , maxlen);
    }
};
//T.C : O(n^2)
//S.C : O(1)  auxiallary space + O(n) input space for returning answer
