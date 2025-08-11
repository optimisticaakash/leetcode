//Approach : using recursive appraoch 

class Solution {
public:
    const int M = 1e9 + 7;
    long long findPower(long long a , long long b){
        //Base case
        if(b == 0) return 1;

        //recursive call 
        long long half = findPower(a , b/2);
        long long result = (half * half)%M;

        if(b%2 == 1){
            result =  (result * a) % M;
        }

        return result;
    }
    int countGoodNumbers(long long n) {
        return (long long)findPower(5 , (n+1)/2) * findPower(4 , n/2) % M;
    }
};

//T.C : O(log2n)
//S.C : O(log2n) 
