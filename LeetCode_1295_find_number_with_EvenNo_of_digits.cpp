//Approach1 : class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            int noofDigit = 0;
            while(nums[i]>0){
                noofDigit++;
                nums[i]/=10;
            }

            if(noofDigit%2 == 0) cnt++;
        }

        return cnt;
    }
};
//T.C : O(n*d) where d = log10(nums[i]) 
//S.C : O(1)

//Approach2 : using maths 
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i : nums){
            int Digit = log10(i)+1;
            if(Digit%2 == 0) cnt++;
        }
        return cnt;
    }
};
//T.C : O(n)

//Approach3: convert each no to string
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(int i : nums){
            string s = to_string(i);
            if(s.size()%2 == 0) count++;
        }
        return count;
    }
};
//T.C : O(n*D)  wherer  D = floor(log10(i)) + 1

//Approach4: playing with constraing
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(int i:nums){
            if((i>=10 && i <100) || (i>=1000 && i<10000) || i == 100000) count++;
        }
        return count;
    }
};
//T.C : O(n)
