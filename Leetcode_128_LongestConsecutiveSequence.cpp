//Approach 1 : Brute force 
//har element ke liye uske aage consecutive sequence ke no ko array me search krna
//code : 
class Solution {
public:
    bool linearSearch(vector<int>& nums , int x){
        for(int i = 0; i < nums.size();i++){
            if(nums[i] == x){
                return true;
            }
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {
        int longest = 1;
        int n = nums.size();
        if(n==0) return 0;
        

        for(int i = 0; i < n; i++){
            int x = nums[i];
            int cnt = 1; 
            while( linearSearch(nums , x+1) == true){
                x=x+1;
                cnt++;
            }
            longest = max(longest , cnt);
        }
        
        return  longest;
    }
};

//T.C = O(n^2)
//S.C = O(1)

//Appraoch 2 : using sorting 
//Code : 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int longest = 0;
        int lastSmaller = INT_MIN;
        //sorting
        sort(nums.begin() , nums.end()); // nlogn

        for(int i = 0; i < n; i++){//O(n)
            if(nums[i]-1 == lastSmaller){
                cnt = cnt+1;
                lastSmaller = nums[i];
            }else if(nums[i] != lastSmaller){
                cnt = 1;
                lastSmaller = nums[i];
            }
            longest = max(longest , cnt);
        }
        return longest;
    }
};

//T.C = (nlogn)
//S.C = O(1)

//Approach 3 : optimal

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int  n= nums.size();
        int longest = 0;
        int cnt = 0;
        unordered_set<int> st;

        for(int i = 0; i < n;i++){
            st.insert(nums[i]);
        }

        for(auto it : st){
            if(st.find(it-1) == st.end()){//not present in set
                cnt = 1;
                int x = it;
                while(st.find(x+1) != st.end()){
                    x = x+1;
                    cnt= cnt+1;
                }
                longest = max(longest , cnt);
            }
        }

        return longest;
    }
};

//Alternate code 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int  n= nums.size();
        int longest = 0;
        int cnt = 0;
        unordered_set<int> st;

        for(int i = 0; i < n;i++){//O(n)
            st.insert(nums[i]);
        }

        for(auto it : st){//O(2n)
            if(st.count(it-1) == 0){//not present in set
                cnt = 1;
                int x = it;
                while(st.count(x+1) == 1){
                    x = x+1;
                    cnt= cnt+1;
                }
                longest = max(longest , cnt);
            }
        }

        return longest;
    }
};

//T.C = O(n)
//S.C = o(n) 
