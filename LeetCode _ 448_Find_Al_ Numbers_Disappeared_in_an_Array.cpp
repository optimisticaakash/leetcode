//Approach1 : using vector hashing
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer;
        vector<int> freq(n+1);

        for(int num : nums){
            freq[num]++;
        }

        for(int i = 1; i <= n; i++){
            if(freq[i] == 0) answer.push_back(i);
        }

        return answer;
    }
};

//T.C : O(n) 
//S.C : O(n)

//Approach 2 : using set
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer;
        unordered_set<int> st(n);
        for(auto num : nums){
            st.insert(num);
        }

        for(int i = 1;i <=n; i++){
            if(!st.count(i)) answer.push_back(i);
        }

        return answer;
    }
};

//T.C : O(n) 
//S.C : O(n)

//Approach 3 : using cyclic sort
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        vector<int> answer;
        while(i < n){
            int correct = nums[i]-1;
            if(nums[i] != nums[correct]){
                swap(nums[i] ,nums[correct]);
            }else{
                i++;
            }
        }

        for(int i = 0; i < n; i++){
            if(nums[i] != i+1) answer.push_back(i+1);
        }
        return answer;
    }
};
//T.C : O(n)
//S.C : O(1) 
