//Appraoch 1 : Bruteforce - make and array and then do XOR operation 
class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> nums;

        for(int i = 0; i < n; i++){
            int num = start + 2*(i);
            nums.push_back(num);
        }

        int XOR = 0;
        for(int i : nums){
            XOR ^= i;
        }

        return XOR;
    }
};

//T.C : O(2n)
//S.C ; O(n)

//Appraoch2 : better
class Solution {
public:
    int xorOperation(int n, int start) {
        int i = 0;
        int num = 0;
        int XOR = 0;
        while( i < n){
            num = start + 2 * i;
            XOR ^= num;
            i++;
        }

        return XOR;
    }
};
//T.C : O(n)
