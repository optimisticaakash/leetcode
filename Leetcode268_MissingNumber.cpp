//Approach 1 : using brute force 
//0 to n har number ke liye array me search krenge nhi hai to return kr denge missing numbers

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        for(int i = 0; i <= n; i++){
            int flag = 0;
            for(int j = 0; j <n; j++){
                if(nums[j] == i){
                    flag = 1;
                    break;
                } 
            }
            if(flag == 0){
                    return i;
             }
        }

        return -1;//it will never run 
    }
};
//T.C:O(n^n)
//S.C:O(1)

//Approach2: better using hasing 

//Vector hashing
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> map(n+1,0);
        for(int i = 0; i <n; i++){//nums me se dekh kr mark kr rhe hai , exist krta hai ya nhi
            map[nums[i]] = 1;
        }

        for(int i = 0; i <=n; i++){// check kr rhe ki 0 to n no map me hai ya nhi 
            if(map[i] == 0){
                return i;
            }
        }
        return -1;// yhan tk ayega hi nhi code solution phle hi mil jyega


    }
};

//map hashing
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(int i = 0; i <n; i++){//nums me se dekh kr mark kr rhe hai , exist krta hai ya nhi
            mpp[nums[i]] = 1;
        }

        for(int i = 0; i <=n; i++){// check kr rhe ki 0 to n no map me hai ya nhi 
            if(mpp[i] == 0){
                return i;
            }
        }
        return -1;// yhan tk ayega hi nhi code solution phle hi mil jyega


    }
};
//bcz array size is less than 10^10 . we can use boths 

//T.C : O(2n)
//S.C: O(n) using vector or map

//Approach3 : using maths optimal approach 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        // sum from 0 to n number 
        int TotalSum = n*(n+1)/2;


        //sum of numbers present in range[0 , n]
        int ActualSum = 0;
        for(int i : nums){
            ActualSum += i;
        }

        //return the missing number 
        return TotalSum - ActualSum;
    }
};
//T.C : O(n)
//S.C: O(1)

//Approach 4 : optimal approach using XOR
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int XOR1 = 0;
        //XOR of all number 0 till N
        for(int i = 0; i <= n; i++){
            XOR1 ^= i;
        }

        //XOR of all the number present in nums
        int XOR2 = 0;
        for(int i : nums){
            XOR2 ^= i;
        }

        return XOR1 ^ XOR2;
    }
};
//T.C:O(2N)
//S.C:O(1)

//Alternative XOR Code using 1 loop only 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //XOR method using only 1 loop
        int n = nums.size();
        int XOR1 = 0;
        int XOR2 = 0;

        for(int i = 0; i < n; i++){
            XOR1 ^= i+1;
            XOR2 ^= nums[i];

        }

        XOR1 ;

        return XOR1 ^ XOR2;
    }
};

//T.C : O(n)
//S.C : O(1)
