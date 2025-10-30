class Solution {
public:
    bool check(vector<int>&nums,int count , int i , int dir){
        vector<int>temp = nums;
        int idx = i;


        while(idx >= 0 && idx <= nums.size()-1 && count >0){
            if(temp[idx] > 0){
                temp[idx]--;
                dir *= -1;
                if(temp[idx] == 0){
                    count--;
                }
            }
            idx += dir;
        }
        return count == 0;
    }
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();

        int count = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] != 0)count++;
        }

        int result = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                //for left
                if(check(nums,count , i , -1)){
                    result++;
                }

                //for right
                if(check(nums,count , i , 1)){
                    result++;
                }
            }
        }

        return result;
    }
};

//Approach 2 : optimal way 
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        int curr = 0;
        int sum = accumulate(nums.begin() , nums.end() , 0);//sbka sum mil jyega -> O(N)
        

        for(int i = 0; i < n; i++){
            curr += nums[i];

            int left = curr;
            int right = sum - curr;

            if(nums[i] != 0) continue;//skip krdo
            
            if(left == right){
                result += 2;
            }else if(abs(left - right) == 1){
                result += 1;
            }
        }

        return result;

    }
};

//T.C :O(N)
//S.C :O(1)
//T.C : O(n*n) in worst case 
//S.C : O(n) 
