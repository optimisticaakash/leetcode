//Approach1: using brute force: 
//nestedloop
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);

        for(int i = 0; i < n; i++) {
            bool found = false;
            //ito n
            for(int j = i+1; j < n; j++) {  // ek round mein max n-1 steps
                if(nums[j] > nums[i]) {
                    result[i] = nums[j];
                    found = true;
                    break;
                }
            }
            //0 to i
            if(!found) {
                for(int j = 0; j < i; j++) {
                    if(nums[j] > nums[i]) {
                        result[i] = nums[j];
                        break;
                    }
                }
            }

        }

        return result;

    }
};

//T.C : O(N2) 
//S.C :O(N) 
