//Approach1 : using brute force 
//iterate through all the possible subarray and track of their sum , return the maximum sum 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n= nums.size();
        int currSum = 0;
        int final_ans = INT_MIN;
        for(int i = 0; i < n; i++){
            currSum += nums[i];

            final_ans = max(currSum , final_ans);

            if(currSum<0){
                currSum = 0;
            }
        }

        return final_ans;
    }
};

//T.C : O(n^3)
//S.C : O(1)

//Approach 2 : dont need to iterate through subarray again and again
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int maxi = INT_MIN;
        //iterate through all the subarray and find maximum sum
        for(int i = 0; i < n;i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                
            sum += nums[j];

            maxi =max(sum , maxi);
            
            }
        }
        return maxi;
    }
};

//T.C = O(n2)
//S.C = O(1)


//Approach 3 : optimal approach kadens algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0 , maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            sum += nums[i];

            //maxi = max(sum , maxi); - can also be used instead of below if block
            if(sum > maxi){
                maxi = sum;
            }
            if(sum < 0){
                sum = 0;
            }
        }
        return maxi;
    }
};
//T.C : O(n)
//S.C : O(1)

//Follow up question : can u print the array with maximum sum 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0 , maxi = INT_MIN;
        int ansStart = -1;
        int ansEnd = -1;
        int start =-1;
        for(int i = 0; i < n; i++){
            if(sum == 0){
                start = i;
            }
            sum += nums[i];

            //maxi = max(sum , maxi); - can also be used instead of below if block
            if(sum > maxi){
                maxi = sum;
                ansStart = start;
                ansEnd = i;
            }
            if(sum < 0){
                sum = 0;
            }
        }

        for(int j = ansStart; j <= ansEnd; j++){
            cout<<nums[j]<<" ";
        }
    return maxi;
    }
};
