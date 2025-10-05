//Approach1 : bruteforce 
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        int n = nums.size();

        for(int i = 0; i <= n-k; i++){
            int maxVal = INT_MIN;
            for(int j = i; j <= i+k-1 && j < n ; j++){
                maxVal = max(maxVal , nums[j]);
            }
            result.push_back(maxVal);
        }

        return result;
    }
};

//T.C : O(n-k) * (k) 
//S.C : O(1) //no extra space 
//it gives tle

//Approach2 : using deque
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> deq;
        vector<int> result;

        for(int i = 0; i < n; i++){
            while(!deq.empty() && deq.front() <= i-k){
                deq.pop_front();//to make valid window in deq
            }

            while(!deq.empty() && nums[deq.back()] < nums[i]){
                deq.pop_back();//we want decreasing
            }

            deq.push_back(i);//maintain decreasing order

            if(i >= k-1){//now we will be getting k sized window
                result.push_back(nums[deq.front()]);
            }
        }

        return result;
    }
};

//T.C : O(N) //every element is pushed once and popped once
//S.C :O(N)

//Approach3 : using map 
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        map<int,int> mp;


        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;

            //remove element which out of window
            if(i >= k){
                mp[nums[i-k]]--;
                if(mp[nums[i-k]] == 0){
                    mp.erase(nums[i-k]);
                }
            }


            //store max element when window is valid
            if(i >= k-1){
                result.push_back(mp.rbegin()->first);//larget element of window
            }
        }
        return result;
    }
};
//T.C : 
//insertion and deletion in map takes O(Log) time
//har element ko ek baar insert kiya hai ek baar delete 
//T.c : O(Nlogk)
//S.c :(k)

