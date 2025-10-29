//Approach1 : here we know 
//if x = have all set bits in its binary representation 
//and if we add one to it,  all the set bits become unset and a 0 comes at most left

//eg. x = 111
// x+1 = 1000

//so if x & ( x+1)  , then it become 0

//code : 
class Solution {
public:
    bool checkallsetbit(int x){
        return (x & x+1) == 0;
    }
    int smallestNumber(int n) {
        int result = n;

        while(!checkallsetbit(result)){
            result++;
        }

        return result;
    }
};



//Approach2: //we know 
//(power of 2)-1 == have all set bits

// so we run a loop  till  the no having allset bit greater than or equal to n

//code:

class Solution {
public:
    int smallestNumber(int n) {
        int result = 1;

        while(result < n){
            result = 2*result + 1;
        }

        return result;
    }
};
//T.C : O(logn)
//S.C :O(1)


//Approach3 : first we count no of set bit required 
// then make a no with having that no of setbit

//no of bits = log2(n) +1;
// and we know 1 << bits -> it gives a power of 2 or we can say a no having 1set bit and all unset bit(no of count = bits)
//so when we subtract 1 from it , then it give no with all set bit

//Code:
class Solution {
public:
    int smallestNumber(int n) {
        int bits = log2(n)+1;

        return (1 << bits) -1;
    }
};
//T.C :O(1)
//S.C :O(1)

