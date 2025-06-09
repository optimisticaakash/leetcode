
//Approach1 :Bruteforce 

class Solution {
public:
    int reverse(int x) {
        int flag = x < 0;
        long long tempNum =abs((long long)x);// long long me isliye conver kiya kyonki
        //INT_MIN= -2147483648 positive hokr 2147483648 bn jyega jo ki INT_MAX se ek bada hai to int me nhi ayega

        //convert kro string me
        string s = to_string(tempNum);

        //reverse kro string ko 
        std::reverse(s.begin() , s.end());

        long long ansNum = stoll(s);//reverse hone pr khin range se bahar na ho isliye to tackle overflow

        if(flag) ansNum *= -1;

        //check krenge khin range se bahar to nhi ho gaya

        if(ansNum < INT_MIN || ansNum > INT_MAX) return 0;

        return Num;
    }
};
//T.C = O(1)
//S.C = O(1) 

//Approach 2 : by checking overflow before multiply by 10 
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while(x != 0){
            int digit = x%10;
            x/=10;

            //check for overflow before multiply by 10 
             if(rev > INT_MAX/10 || (rev == INT_MAX/10 && digit > 7)) return 0;
            if(rev < INT_MIN/10 || (rev == INT_MIN/10 && digit < -8)) return 0;

            /*Let's say rev == 214748364, which is INT_MAX / 10.
                If you multiply rev * 10, you get 2147483640.
                Now you want to add digit.
                If digit > 7, the total becomes more than 2,147,483,647 — that’s overflow!
                So you must prevent that.
            */

            rev = rev *10 + digit;

        }
        return rev;
    }
};

//T.C = O(N)
//S.C = O(1) 

