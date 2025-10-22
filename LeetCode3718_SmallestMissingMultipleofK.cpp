class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;

        for(int i = 0; i < nums.size(); i++){
            st.insert(nums[i]);
        }

        int value = k;
        while(st.find(value) != st.end()){
            value += k;
        }

        return value;
    }
};
