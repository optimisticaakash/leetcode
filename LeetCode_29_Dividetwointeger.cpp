//Approach1 : bruteforce
class Solution {
public:
    int divide(int dividend, int divisor) {
        //edge case
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;

        //if agar ye true hua to ans me - sign laga kr return krenge
        bool negative = (dividend < 0) ^ (divisor<0);

        long long a = abs((long long)dividend);
        long long b = abs((long long) divisor);

        long long quotient = 0;

        while(a >= b){
            a-=b;
            quotient++;
        }

        return negative ? -quotient : quotient;
    }
};
//T.C : O(divident) = O(2^31)
//S.C : O(1)
//This approach gives tle

//Approach2 : 
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) return 1;

        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;

        bool sign = true;
        if ((dividend >= 0 && divisor < 0) || (dividend < 0 && divisor > 0))
            sign = false;

        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);

        long long quotient = 0;
        while (n >= d) {
            int cnt = 0;
            while (n >= (d << (cnt + 1))) {
                cnt++;
            }
            quotient += (1 << cnt);
            n -= (d << cnt);
        }
        
        return sign ? quotient : -quotient;
    }
};
//T.C : O((logn)^2)
//S.C : O(1) 
