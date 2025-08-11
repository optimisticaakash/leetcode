//Approach1 : iterative approach 
class Solution
public:
    double myPow(double x, int n) {
        
        double ans = 1;
        long long m = n;
        if (m < 0) {
            x = 1 / x;
            m = -m;
        }
        while( m > 0){
            if(m%2 == 1){
                ans = ans*x;
                m--;
            }else{
                x = x*x;
                m= m/2;
            }
        }
        
        return ans;
    }
};
//T.C : O(logn)
//S.C : O(1)

//Approach2 : recursive approach 
class Solution {
public:

    double solvemyPow(double x , long long n){
        //base case 
        if(n == 0) return 1.0;

        //if n is negative
        if(n < 0){
            x = 1/x;
            n = -n;
        }
        double part_ans = solvemyPow(x , n/2);
        if(n%2 == 0){//for even
            return part_ans * part_ans;
        }else{//for odd 
            return x * part_ans * part_ans;
        }
    }
    double myPow(double x, int n) {
        return solvemyPow( x , n);
    }
};

//T.C : O(logn)
//s.C : O(logn)

//alternative code : 
class Solution {
public:

    double solvemyPow(double x , long long n){
        //base case 
        if(n == 0) return 1.0;

        //if n is negative
        if(n < 0){
            return 1.0/solvemyPow(x ,-n);
        }
        double part_ans = solvemyPow(x , n/2);
        if(n%2 == 0){//for even
            return part_ans * part_ans;
        }else{//for odd 
            return x * part_ans * part_ans;
        }
    }
    double myPow(double x, int n) {
        return solvemyPow( x , n);
    }
};
//same as above
//Appraoch3 : using recursion 
class Solution {
public:
    double myPowHelper(double x, int n) {
        if( n == 0) return 1.0;
        double partial_ans = myPowHelper(x , n/2);
        if(n % 2 == 0){
            return partial_ans * partial_ans;
        }else {
            return partial_ans * partial_ans * x;
        }
        
    }
    double myPow(double x, int n) {
        if(n < 0){
            return 1/myPowHelper(x, -n);
        }else {
            return myPowHelper(x,n);
        }
    }
};

//T.C : O(logn)
//S.C : O(logn)
