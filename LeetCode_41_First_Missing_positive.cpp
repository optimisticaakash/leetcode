//Approach1 : using a unordered_set
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int>st;
        //1.putting positive element in set
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0 ){
                continue;
            }else{
                st.insert(nums[i]);
            }
        }

        //2. run a loop form 1 to n first number not present in set is answer
        for(int i = 1; i <= nums.size(); i++){
            if(!st.count(i)){
                return i;
            }
        }

        return nums.size()+1;
    }
};
//T.C : O(n) 
//S.C : O(n)

//Approach 2 : using a bool vector
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool> array(n+1,false);

        for(int i = 0; i < n; i++){
            if(nums[i] >0 && nums[i] <= n){
                int index = (nums[i]);
                array[index] = true;
            }else{
                continue;
            }
        }


        for(int i = 1; i <= n; i++){
            if(array[i] != true) return i;
        }

        //agar sare hi true , mtlb answer n+1
        return n+1;
    }
};

//T.C : O(n)
//S.C : O(n) 

//Approach 3 : using index mapping
class Solution {
public:
//Approach2 : using index marking 
//T.C : O(n) 
//S.C : O(1) 
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        bool contains1 = false;
        for(int i = 0; i < n; i++){
            if(nums[i]==1){
                contains1 =  true;
            }
            if(nums[i] <= 0 || nums[i] >n){//we only need to deal with [1 , n]
                nums[i] = 1;
            }
        }


        if(contains1 == false) return 1;

        for(int i = 0; i < n; i++){
           int num = abs(nums[i]);
           int idx = num-1;

           if(nums[idx] < 0) continue;

           nums[idx] *= -1;
        }

        for(int i = 0; i< n; i++){
            if(nums[i] >0){
                return i+1;
            }
        }
        //agar sare negative hai mtlb 1 se n tk present hai 
        return n+1;
    }
};

//T.C : O(N) 
//S.C ; O(1) 

//Approach 4 : using cyclic sort
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] > 0 && nums[i] <= nums.size()) {
                int correct = nums[i] - 1;
                if (nums[i] != nums[correct]) {
                    swap(nums[i], nums[correct]);
                    continue; // swap ke baad dobara check karo
                }
            }
            i++; // jab number correct jagah pe ho ya out of range ho
        }

        //search of the missing number
        for(int index = 0; index < nums.size(); index++){
            if(nums[index] != index+1){
                return index+1;
            }
        }

        return nums.size()+1;
    }
};

//T.C : O(n) 
//S.C : O(1) 
