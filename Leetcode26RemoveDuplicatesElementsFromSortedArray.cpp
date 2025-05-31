//Approach 1 : use a set 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        set<int> st;
        for(int i = 0 ;i <n; i++){//O(N)
            st.insert(nums[i]);//insertion in set takes O(NlogN)
        }

        int index = 0;
        for(auto it:st){//O(N)
            nums[index] = it;
            index++;
        }

        return index;
    }
};

//TC:O(N+NlogN)
//Sc: O(N) bcz if all elements are unique they will get stored in set

//Approach 2 : using two pointer 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        int i = 0; 
        for(int j = 1; j < n; j++){
            if(nums[i] != nums[j]){
                nums[i+1] = nums[j];
                i++;
            }
        }

        return i+1;
    }
};

//TC:O(N)
//SC:O(1)
