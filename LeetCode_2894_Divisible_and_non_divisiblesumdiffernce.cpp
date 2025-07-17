//Approach1: using loops 
class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1 = 0;
        int num2 = 0;

        for(int i = 1; i <= n; i++){
            if(i%m == 0){
                num2 += i;
            }else{
                num1 += i;
            }
        }

        return num1 - num2;
    }
};

//T.C: O(n) 

//Approach2: better
class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum= n*(n+1)/2;
        int num2 = 0;

        int noOfMultiple = n / m;
        int i = 1;
        while(noOfMultiple != 0){
            num2 += m*noOfMultiple;
            noOfMultiple--;
        }
        int num1 = sum-num2;

        return num1 - num2;
    }
};

//T.C ; O(n/m)

//Approach3 : using maths
class Solution {
public:
    int differenceOfSums(int n, int m) {
        int totalsum = n*(n+1)/2;
        int k = n/m;//mulitple of m

        int num2 = m* k*(k+1)/2;
        int num1 = totalsum - num2;


        return num1-num2;
    }
};
//T.C : O(1)
