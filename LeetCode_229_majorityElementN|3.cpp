//Approach1 : Bruteforce 
//ek ek element pr jyenge count krenge agar list me phle se nhi hai or cnt > n/3 hai to list me dal denge 
//Code: 
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(nums[i] == nums[j]){
                    cnt++;
                }
            }
            // if(cnt > n/3 && ( ans.empty()  || ans.back() != nums[i]) && ans.size() < 2)
            //     ans.push_back(nums[i]);
            if(cnt > n/3 && find(ans.begin() , ans.end() , nums[i]) == ans.end()){
                //nums[i] not found
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};
//T.C : O(n^2)

//Alternative code:
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans;
        for(int i = 0; i < n;i++){
            if(ans.size() == 0 || ans[0] != nums[i]){
                int cnt = 0;
                for(int j = 0; j< n; j++){
                    if(nums[i] == nums[j])
                        cnt++;
                }
                if(cnt > n/3){
                    ans.push_back(nums[i]);
                }
            }
            if(ans.size() == 2) break;
        }

        return ans;
    }
};

//T.C : O(n^2)

//Approach2: using hashing 
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>mpp;
        vector<int> ans;
        int n = nums.size();

        for(int i = 0; i < n;i++){//O(n)
            mpp[nums[i]]++;
        }

        for(auto it : mpp){//O(n)
            if(it.second > n/3){
                ans.push_back(it.first);
            }
        }
        

        return ans;
    }
};
//T.C : O(n) 

//Approach 3 : using hashmap-onepass

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int n = nums.size();

        int mini = int(n/3)+1;
        vector<int> ans;

        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]] == mini){
                ans.push_back(nums[i]);
            }
            if(ans.size()==2) break;
        }

        return ans;
    }
};
//T.C= O(n) 

//Approach4: 
//Extended boyer moore's voting algorithm

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        int cnt1 = 0 , cnt2 = 0;
        int ele1 = INT_MIN;
        int ele2 = INT_MIN;

        //first pass 
        for(int i = 0; i < n; i++){
            if(cnt1 == 0 && ele2 != nums[i]){
                cnt1 = 1;
                ele1 = nums[i];
            }
            else if(cnt2 == 0 && ele1 != nums[i]){
                cnt2 = 1;
                ele2 = nums[i];
            }
            else if(nums[i] == ele1) cnt1++;
            else if(nums[i] == ele2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }

        //2ndpass for manual check ki majority elements hai ya nhi
        vector<int> ans;
        cnt1 = 0; cnt2 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == ele1) cnt1++;
            if(nums[i] == ele2) cnt2++;
        }
        int mini = int(n/3)+1;
        if(cnt1 >= mini) ans.push_back(ele1);
        if(cnt2 >= mini) ans.push_back(ele2);

        return ans;
    }
};

//T.C = O(N)
//S.C = O(1)

