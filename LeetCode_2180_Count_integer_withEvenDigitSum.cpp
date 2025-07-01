//Approach1 

class Solution {
public:
    int CountDigitSum(int i){
        int sum = 0;
        while( i > 0){
            sum += i%10;
            i /= 10;
        }
        return sum;
    }
    int countEven(int num) {
        int cnt = 0;
        for(int i = 1; i<= num; i++){
            int DigitSum = CountDigitSum(i);
            if( DigitSum % 2 == 0) cnt++;
        }
        return cnt;
    }
};
//T.C : O(n) * O(d) where d = log10(nums[i])
