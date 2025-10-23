//Approach1 : using hashmap

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;

        for(int i = 0; i < n; i++){
            if(mpp.find(nums[i]) != mpp.end()){
                if(abs(i - mpp[nums[i]]) <= k) return true;
            }
            mpp[nums[i]] = i;
        }


        return false;

    }
};
//T.C :O(N)
//S.C :O(N)


//Approach2 : sliding window
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_set<int> mpp;

        int l = 0 , r = 0;
        while(r< n){
            if(abs(r-l)>k){ //abs(r-l)<=k
                mpp.erase(nums[l]);
                l++;//shring
            }

            //agar past me dekha hai 
            if(mpp.find(nums[r]) != mpp.end()){
                return true;
            }
            
            mpp.insert(nums[r]);//agar nhi dekha to set me dal do 
            r++;
        }

        return false;
    }
};

//T.c :O(N)
//S.C :O(N)
