//Approach 1 
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        //stores all the non zero element in the temp
        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                temp.push_back(nums[i]);
            }
        }

        //step 2 move all the nonzero elements back to the array 
        for(int i = 0; i <temp.size(); i++){
            nums[i] = temp[i];
        }

        int nonzeros = temp.size();
        //now assign all the remaining elements of the element to 0 
        for(int i = nonzeros; i < n; i++){
            nums[i] = 0; 
        }
    }
};

//T.C = O(2N)
//S.C = O(n) in worst case

//Approach 2 : 2 pointer approach 

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int j = -1;
        for(int i = 0; i < n; i++){//O(x)
            if(nums[i] == 0){
                j=i;
                break;
            }
        }
        if (j== -1) return;
        
        int temp = 0;
        for(int i = j+1; i < n; i++){//(n-x)
            if(nums[i] != 0){
               swap(nums[i],nums[j]);
               j++;
            }
            
        }
    }
};

//T.C = O(n)
//S.c = O(1)
