//Approach1 : bruteforce 
//using for loops
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();

        int repeating = -1 , missing = -1;

        for(int i = 1; i <= n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(nums[j] == i) cnt++;
            }
            if(cnt == 2) repeating = i;
            else if(cnt == 0) missing = i;


            if(repeating != -1 && missing != -1) break;
        }

        return {repeating , missing};
    }
};

//T.C : O(n^2)
//S.C : O(1)

//approach2: using hashing (use array for hashing) bcz 1 to n range
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n+1,0);

        for(int i = 0; i< n; i++){
            hash[nums[i]]++;
        }
        int repeating = -1 , missing = -1;
        for(int j = 1; j <= n; j++){
            if(hash[j] == 2) repeating = j;
            else if(hash[j] == 0) missing = j;
            
            if(repeating != -1 && missing != -1){
                break;
            }
        }

        return {repeating , missing};
    }
};
//T.C : O(2N) = O(n) 
//S.C : O(n) 

//Approach3 : optimal using maths 
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long n = nums.size();
        //S - SN == x-y
        //S2 - S2N
        long long SN = (n*(n+1))/2;
        long long S2N = ( n* (n+1) * (2*n+1) )/6;
        long long S = 0 , S2 = 0;
        for(int i = 0; i < n; i++){
            S += nums[i];
            S2 += (long long)nums[i] * (long long)nums[i];
        }

        //S-SN = x-y = val1
        long long val1 = S-SN;
        
        //S2 - S2N
        long long val2 = S2 - S2N;
        val2 = val2/val1;

        long long x = (val1 + val2)/2;
        long long y = x-val1;
        return {(int)x , (int)y};
    }
};

//T.C = O(n)
//S.C = O(1)

//Approach4 : optimal using Xor

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;
        for(int i = 0; i < n; i++){
            xr = xr ^ nums[i];
            xr = xr ^(i+1);
        }
        int bitIndex = 0;
        while(1){
            if((xr & (1<<bitIndex)) != 0){
                break;
            }
            bitIndex++;
        }

        int zero = 0;
        int one = 0;

        //array ke no ko zero and one club me divide krna 
        for(int i = 0; i < n; i++){
            //part of one club
            if((nums[i] & (1<<bitIndex)) != 0){
                one = one ^ nums[i];
            }
            //part of zero club
            else{
                zero = zero^nums[i];
            }
        }

        //1 to n wale no ko zero and one club me divide krna
        for(int i = 1; i<= n; i++){
            //part of one club
            if((i & (1<<bitIndex)) != 0){
                one = one ^ i;
            }
            //part of zero club
            else{
                zero = zero^i;
            }
        }

        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == zero) cnt++;
        }
        if(cnt == 2) return {zero , one};
        else return {one , zero};
    }
};
//T.C = O(4N)
//S.C = O(1)

//Alternate code ;
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;
        for(int i = 0; i < n; i++){
            xr = xr ^ nums[i];
            xr = xr ^(i+1);
        }
        int number = xr & ~(xr-1);

        int zero = 0;
        int one = 0;

        //array ke no ko zero and one club me divide krna 
        for(int i = 0; i < n; i++){
            //part of one club
            if((nums[i] & number) != 0){
                one = one ^ nums[i];
            }
            //part of zero club
            else{
                zero = zero^nums[i];
            }
        }

        //1 to n wale no ko zero and one club me divide krna
        for(int i = 1; i<= n; i++){
            //part of one club
            if((i & number) != 0){
                one = one ^ i;
            }
            //part of zero club
            else{
                zero = zero^i;
            }
        }

        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == zero) cnt++;
        }
        if(cnt == 2) return {zero , one};
        else return {one , zero};
    }
};
//T.C : O(N)
//S.C : O(1)
