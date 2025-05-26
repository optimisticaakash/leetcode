//Appraoch 1 : bruteforce -> har element ko target bana kr dekhenge ki usse phle wale elements target element ke barabar ho jayenge k operation me 
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());  // Optional for easier handling

        int result = 0;

        for (int i = 0; i < n; ++i) {
            int target = nums[i];
            vector<int> temp = nums;//Copy banayi temp, taaki original array kharab na ho.

            // Sort so that smallest elements come first (to convert them to target)
            sort(temp.begin(), temp.begin() + i + 1);

            int ops = k;
            int count = 1;  // target itself counts taki frquency correct count ho ske 

            for (int j = i - 1; j >= 0; --j) {
                int diff = target - temp[j];//Har element temp[j] ko target banane me target - temp[j] ops lagenge.
                if (ops >= diff) {
                    ops -= diff;//Ye total k operations ka remaining balance hai.
                    count++;
                } else {
                    break;
                }
            }

            result = max(result, count);
        }

        return result;
    }
};

//TimeComplexity: O(n^2)
//SpaceComplexity : O(n) due to using temp array of size n

//Approach 2 : Binary search 
class Solution {
public:

    int bSearch(int target_idx ,int k , vector<int> &nums , vector<long> &prefixSum){
        int target = nums[target_idx];
        int l = 0;
        int r = target_idx;

        int best_idx = target_idx;

        while(l <= r){
            int mid = l + (r-l)/2;

            long count = (target_idx-mid+1);
            long windowSum = count*target;

            long currSum = prefixSum[target_idx]-prefixSum[mid]+nums[mid];

            int ops = windowSum - currSum;

            if(ops > k){
                l = mid+1;
            }else{
                best_idx = mid;
                r = mid-1;
            }
        }

        return target_idx - best_idx +1;
    }
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();

        sort(begin(nums),end(nums));//O(nlogn)
        vector<long> prefixSum(n);
        prefixSum[0] = nums[0];
        for(int i = 1; i < n; i++){//O(n)
            prefixSum[i] = prefixSum[i-1]+nums[i];
        }

        int result = 0;

        for(int target_idx = 0; target_idx < n; target_idx++){//n calls ho rhi hai 0 to n-1
            result = max(result,bSearch(target_idx , k , nums , prefixSum));//and bSeach - O(long)
        }
        //O(nlogn)
        return result;
    }
};

//TimeComplexity: O(nlogn + n + nlogn) = O(nlogn)
//SpcaeComplexity : O(n) prefix array


//Approach 3 : sliding window 
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(begin(nums) , end(nums));

        int n = nums.size();
        int result = 0;

        int l = 0; 
        long currSum = 0;

        for(int r = 0; r < n; r++){
            long target = nums[r];
            currSum += nums[r];

            int ops = (r-l+1)*target - currSum;
            while((r-l+1)*target - currSum > k){ // window shrink
                currSum -= nums[l];
                l++;
            }
            result = max(result , r-l+1);
        }

        return result;
    }
};

//Timecomplexity: O(2N)= O(n) dono loop  milar ek element ko 2 bar hi iterate kr rhe hai 
//spaceComplexity : O(1) except sorting 
//And this same code can be submit by using if instead of while 
