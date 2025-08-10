//Approach1 : using bruteforce loop 
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> answer;

        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                if(nums[i] == nums[j]) answer.push_back(nums[i]);
            }
        }

        return answer;
    }
};

//T.C : O(n2)
//s.C : O(n) 

//Approach 2 : sorting 
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> answer;
        sort(nums.begin() , nums.end());

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]){
                answer.push_back(nums[i]);
            }
        }

        return answer;
    }
};

//T.C : O(nlogn) 
//S.C : O(1) 

//Approach 3 : class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int> st;
        vector<int> answer;
        for(auto it : nums){
            if(st.count(it)) answer.push_back(it);
            st.insert(it);
        }

        return answer;
    }
};
//T.C : O(n)
//S.C : O(n) 

//Approach 4 : using map 
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> mpp;
        vector<int> answer;
        for(int num : nums){
            mpp[num]++;
        }

        for(auto it : mpp){
            if(it.second == 2) answer.push_back(it.first);
        }

        return answer;
    }
};
//T.C : O(n) 
//S.C : O(n) 

//Approach 5 : cyclic sort
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>answer;
        int i = 0; 
        while(i < nums.size()){
            int correctIndex = nums[i]-1;
            if(nums[i] != nums[correctIndex]){
                swap(nums[i] , nums[correctIndex]);
            }else{
                i++;
            }
        }

        for(int i = 0; i < nums.size() ; i++){
            if(nums[i] != i+1){
                answer.push_back(nums[i]);
            }
        }

        return answer;
    }

//T.C : O(n)
//S.C : O(1)

//Approach6: index mapping
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();

        vector<int> answer;
        for(int i = 0; i < n; i++){
            int num = abs(nums[i]);
            int idx = num-1;
            if(nums[idx] < 0){
                answer.push_back(num);
            }else{
                nums[idx] *= -1;
            }
        }

        return answer;
    }
};

//T.C : O(n)
//S.C : O(1) 
};

//T.C : O(n) 
//S.C : O(1) 
