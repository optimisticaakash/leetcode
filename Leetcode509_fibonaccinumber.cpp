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
