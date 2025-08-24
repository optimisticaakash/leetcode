//Approach1 : using recursion
class Solution {
public:
    bool isPowerOfTwo(int n) {
        //using recursion
        if(n == 1)return true;
        if(n%2 != 0 || n == 0)return false;

        return isPowerOfTwo(n/2);
    }
};
//T.C : O(logn)
//S/C : O(logn)


//Appraoch2 : using bit 
class Solution {
public:
    bool isPowerOfTwo(int n) {
        string s;
        while(n>0){
            s += (n%2)?'1':'0';
            n/=2;
        }
        int cnt = 0;
        for(char it : s){
            if(it =='1')cnt++;
        }

        return (cnt ==1);
    }
};

//T.C : O(logn)
//S/C : O(logn)

//Approach 3 : using bitclass Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)return false;
        return ((n&n-1)==0);
    }
};

//T.C : O(1)
//S.C : O(1) 
