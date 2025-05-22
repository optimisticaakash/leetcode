//Approach 1 : using loops 
class Solution {
public:
    int fib(int n) {
        int a = 0 , b = 1 , c;
        int count = 2;
        if(n<=1) return n;
        while(count <= n){
            c = a+b;
            a = b;
            b = c;
            count++;
        }
        return c;
    }
};

//T.C = o(N)
//S.c = O(1)


//Approach 2: using recursion

class Solution {
public:
    int fib(int n) {
        if(n<= 1) return n;
        int last = fib(n-1);
        int slast = fib(n-2);

        return last+slast;
    }
};

//time complexity = O(2^n) //more than n recursion call 
//each recursion call calls function 2 time

//space complexity = O(n) deepest recursion stack => f(n) -> f(n-1) -> .....-> f(1) -> f(0)

//This can also be solved by recursion + memorized . do that later
