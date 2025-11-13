//Bruteforce:
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size();
        int cnt = 0;

        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                if(nums[i] + nums[j] < target) cnt++;
            }
        }

        return cnt;
    }
};
//T.C : O(N^2)

//Approach : using two pointer
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(begin(nums) ,end(nums));
        int i = 0;
        int j = nums.size()-1;

        int cnt = 0;
        while(i < j){
            if(nums[i] + nums[j] < target){
                cnt += (j-i);
                i++;
            }else{
                j--;
            }
        }

        return cnt;
    }
};
//T.C : O(N) 
