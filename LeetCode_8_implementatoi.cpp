//Approach1: 
class Solution {
public:
    bool is_Digit(char ch){
        return (ch >= '0' && ch <= '9');
    }
    int myAtoi(string s) {
        int i = 0; //at index 0
        int n = s.size();
        int num = 0;
        int sign = 1;

        // 1. skip leading spaces 
        while(i  < n && s[i]==' ') i++;

        //2.handle + and -
        if(i < n && (s[i] == '+' || s[i] == '-')){
            sign = (s[i] == '-') ? -1:1;
            i++;
        }

        //3.check if character is digit or not
        while(i < n && is_Digit(s[i])){
            
            //check if num is withing the range
            if(num > INT_MAX/10 || num == INT_MAX/10 && (s[i]-'0') >7 ){
                if(sign == 1) return INT_MAX;
                else return INT_MIN;
            }

            num = num * 10 + (s[i]-'0');

            i++;
        }

        return sign*num;
    }
};

//alternative code;
class Solution {
public:
    int myAtoi(string s) {
        int i = 0; //at index 0
        int n = s.size();
        long long num = 0;
        int sign = 1;

        // 1. skip leading spaces 
        while(i  < n && s[i]==' ') i++;

        //2.handle + and -
        if(i < n && (s[i] == '+' || s[i] == '-')){
            sign = (s[i] == '-') ? -1:1;
            i++;
        }

        //3.check if character is digit or not
        while(i < n && isdigit(s[i])){
            num = num * 10 + (s[i]-'0');

            
            i++;
        }

        if(sign == 1 && num > INT_MAX) return INT_MAX;
        else if(sign == -1 && -num < INT_MIN) return INT_MIN;


        return sign*num;
    }
};

//T.C : O(n)
//S.C: O(1)
