//Approach 1 : Bruteforce 
//pick one element at a  time and iterate thorugh the whole array , count no of frequecny of that number
//if greater than N/2 return that number 

//Code : 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++){
            int cnt = 0; 
            for(int j = 0; j < n; j++){
                if(nums[i] == nums[j]){
                    cnt++;
                }
            }
            if(cnt > n/2) return nums[i];
        }
        return -1;
    }
    
};

//T.C : o(n^2)
//S.C : O(1)

//Approach 2 : Better solution (hashing)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;
        }

        
        for(auto it : mpp){
            if(it.second > n/2){
            
            return it.first;
            }           
        }
        return -1;
    }
    
};

//Alternative code :
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;
        }

        int maxfreq = 0;
        int mostfreqEle = INT_MIN;
         for(auto it : mpp){
            if(it.second > maxfreq){
            maxfreq = it.second;
            mostfreqEle = it.first;
            }           
        }
        return mostfreqEle;
    }
    
};
//T.c : O(n)
//S.C : O(n) 

//Optimal Approach - moore's algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int ele = 0;

        for(int i = 0; i < n; i++){
            if(cnt == 0){
                cnt = 1;
                ele = nums[i];
            }else if(nums[i] == ele){
                cnt++;
            }else{
                cnt--;
            }
        }
        return ele;
    }
};

//T.C:O(n)
//S.C:O(1)
