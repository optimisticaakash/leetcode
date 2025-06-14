//Approach1: bruteforce 
//Code
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();

        set<vector<int>> st;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                for(int k = j+1; k < n; k++){
                    for(int l = k+1; l < n; l++){
                        long long sum = nums[i]+nums[j];
                        sum += nums[k];
                        sum += nums[l];
                        if(sum == target){
                            vector<int> temp= { nums[i],nums[j],nums[k],nums[l]};
                            sort(temp.begin() , temp.end());//4log4
                            st.insert(temp);
                        }
                    }
                }
            }
        }

        vector<vector<int>>ans(st.begin() , st.end());
        return ans;
    }
};
//T.C : O(n^4)
//S.C : O(2* no of quadruplets)

//Approach2: Better approach 
//Using hashset

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();

        set<vector<int>> st;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                set<long long> hashset;
                for(int k = j+1; k < n; k++){
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    long long fourth = target - sum;
                    if(hashset.find(fourth) != hashset.end()){
                        vector<int> temp = {nums[i],nums[j],nums[k],(int)fourth};
                        sort(temp.begin() , temp.end());
                        st.insert(temp);
                    }
                    hashset.insert(nums[k]);
                }
            }
        }

        vector<vector<int>>ans(st.begin() , st.end());
        return ans;
    }
};

//T.C = O(n^3 + logm) 
// m varies as the no of element in the hashset will depend on the no of elements between j and k 

//S.C = O(n) + O(quad) *2
//ek to set me no of quad 
// and ek to vector<vector<int>> ans me no of quad 

//Approach3 : optimal using sorting and two pointer
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++){
            if(i>0 && nums[i] == nums[i-1]) continue; //dont need to go down
            for(int j = i+1; j< n;j++){
                if(j != i+1 && nums[j] == nums[j-1])continue;
                int k = j+1;
                int l = n-1;
                while(k<l){
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum == target){
                        vector<int>temp = {nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k < l && nums[k] == nums[k-1]) k++;
                        while(k < l && nums[l] == nums[l+1]) l--;
                    }
                    else if(sum < target) k++;
                    else l--;
                }
            }
        }
        return ans;
    }
};

//T.C : O(n^3)
//S.C : O(quad) to return the ans
