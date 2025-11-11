//Approach1 : bruteforce
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int temp = 0;
        for(int i = 0; i < n; i++){
            temp = nums[i];
            nums[i]= temp*temp;
        }


        sort(nums.begin() , nums.end());

        return nums;
    }
};


//T.C : O(NLOGN)
//S.C :O(1) auxilary space




//Approach2: usint two pointer
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> ans(n);
        int i = 0;
        int j = n-1;

        //elements ko fill krne ke liye
        int k = n-1;

        while(i <= j){

            if(abs(nums[i]) > abs(nums[j])){
                ans[k] = nums[i] * nums[i];
                i++;
            }else{
                ans[k] = nums[j] * nums[j];
                j--;
            }
            k--;
        }

        return ans;
    }
};
//T.C : O(N)
//S.C : O(1) auxillary space
      //O(N) input space
