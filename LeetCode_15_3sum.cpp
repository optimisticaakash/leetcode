//Approach1: try every possible triplets

 class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st;

        for(int i = 0; i<n;i++){
            for(int j = i+1; j < n; j++){
                for(int k = j+1; k < n; k++){
                    if(nums[i]+nums[j]+nums[k] == 0){
                        vector<int> temp = {nums[i] , nums[j] , nums[k]};
                        sort(temp.begin() ,temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin() , st.end());
        return ans;
    }
};
//T.C : O(n^3 + log(no of unique triplests) //set takes logN
//S.C : 2*O(no of unique triplets)

//no of unique triplets vary on inputs

//Approach2: get rif of one loop  by using hashing to easy look out for third element
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st;
        //third = -(nums[i]+nums[j])

        for(int i = 0; i<n;i++){
            set<int>hashset;//set for quick lookout for third and it will become empty when i changes  inorder to 
            //give other possible triplets
            for(int j = i+1; j < n; j++){
                int third = -(nums[i]+nums[j]);
                if(hashset.find(third) != hashset.end()){//mtlb third present in hashset
                    vector<int>temp={nums[i] , nums[j] , third};
                    sort(temp.begin() , temp.end());//sort so that set st store unique triplets 
                    st.insert(temp);
                }
                hashset.insert(nums[j]);//third nhi milaa to nums[j] ko hi hashset me dal do
            }
        }
        vector<vector<int>> ans(st.begin() , st.end());
        return ans;
    }
};

//T.c : O(n^2 + log(m)) set
//S.C : O(n) + 2*O(no of unique triplets)

//Approach3 : sort the array and use two pointer

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n;i++){
            if(i>0 && nums[i] == nums[i-1]) continue;//no need to go down skip this iteration
            int j = i+1;
            int k = n-1;
            while(j < k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum < 0){
                    j++;
                }else if(sum > 0){
                    k--;
                }else{
                    vector<int>temp ={nums[i] , nums[j] , nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j< k && nums[j] == nums[j-1]) j++;
                    while(j < k &&nums[k] == nums[k+1]) k--;
                }
            }
        }

        return ans;
    }
};
//T.C : O(nlogn) sorting + O(n^2)
//S.C : O(no of unique triplets) for returning ans only 
