//Approach1 : Bruteforce using loops 

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int duplicate = -1;

        for(int i = 1; i < n; i++){
            int cnt = 0;
            //iterating through array
            for(int j = 0; j < n; j++){
                if(nums[j] == i){
                    cnt++;
                }
                if(cnt >= 2){
                duplicate = nums[j];
                break;
                }
            }
            
        }
        return duplicate;
    }
};

//T.C : O(n2)
//S.C : O(1) 

//Approach2 : using map 
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        int duplicate = -1;
        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;
        }

        //iterate through map
        for(auto it : mpp){
            if(it.second >= 2){
                duplicate = it.first;
            }
        }

        return duplicate;
    }
};
//T.C : O(n) 
//S.C : O(n) 

//Approach3 : hashing using array 
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> hasharr(n+1 , 0);

        for(int i = 0; i < n; i++){
            hasharr[nums[i]]++;
        }
        int duplicate = -1;
        for(int j = 1; j <= n; j++){
            if(hasharr[j] >= 2){
                duplicate = j;
                break;
            }
        }

        return duplicate;
    }
};
//T.C : O(n)
//S.C : O(n) 

//Approach4 : using set
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> st(nums.size());
        int duplicate = -1;
        for(int num : nums){
            if(!st.count(num)){
                st.insert(num);
            }
            else{
                duplicate = num;
            }
        }

        return duplicate;
    }
};
//T.C : O(n)
//S.C : O(n)

//Approach5 : using cyclic sort
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0;
        while(i <  nums.size()){
            if(nums[i] != i + 1){
                int correctIndex = nums[i]-1;
                if(nums[i] != nums[correctIndex]){
                    swap(nums[i] , nums[correctIndex]);
                }else{
                    return nums[i];
                }
            }else{
                i++;
            }
        }
        return -1;
    }
};
//T.C : O(n)
//S.C : O(1) 
