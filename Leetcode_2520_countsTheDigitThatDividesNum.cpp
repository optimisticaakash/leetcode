//Approach : simple 
/* 
1.Extract krenge last digit  check krenge if digit != 0 && original num % ld == 0
2. agar aisa aa rha to count increse kr denge 

*/
//Code ; 
class Solution {
public:
    int countDigits(int num) {
        int  original = num;
        int cnt = 0;
        while(num > 0){
            int ld = num % 10;
            num/=10;

            if(original % ld == 0){
                cnt++;
            }
        }

        return cnt;
    }
};

//T.C = O(log10N)
//S.C = O(1)
//NOTE: in the question it is mentioned that number does not contain any 0 
//so when we are extracting last digit(ld) it cant be zero . so we can remove that condition
