//Approach1: Brute force approach - har possible solution ko check krna 
/*
1.har l(left) index se start lenge
2.har r(right) index tk subarray le jyenge
3.subarray me count krenge num_of_zeors 
4.agar zeros nhi hai to length nikal kr subarray ki update kr denge

  */
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();

        
        int finalans = 0;
        //starting point  of subarray (left index)
        for(int l = 0; l < n; l++){
            int Num_of_zeros = 0;//reset in every l loop 

            //ending point of subarray(right index)
            for(int r = l; r < n; r++){
                if(nums[r] == 0){
                    Num_of_zeros++;
                }

                if(Num_of_zeros == 0){
                    finalans = max(finalans,r-l+1);
                }
            }
        }

        return finalans;
    }
};
//T.C : O(N^2)
//S.C : O(1)

//Approach 2 : optimal solution 

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int max1 = 0;
        int count = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                count++;
                max1 = max(max1, count);
            }else{
                count = 0;
            }
        }

        return max1;
    }
};

//T.C : O(n)
//S.C : O(1)
