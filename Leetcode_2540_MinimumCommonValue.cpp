//Approach1 
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> mp;

        for(int &i : nums1){
            mp.insert(i);
        }


        for(int &i: nums2){
            if(mp.find(i) != mp.end()) return i;
        }

        return -1;
    }
};

//T.C :O(n+m)
//S.C :O(m) or O(N)

//Approach2: binarysearch bcz both are sorted
class Solution {
public:
    bool binarySearch(vector<int>& nums , int target){
        int low = 0;
        int high = nums.size()-1;

        while( low <= high){
            int mid = low+(high-low)/2;

            if(nums[mid] == target){
                return true;
            }if(nums[mid]<target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }

        return false;
    }
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for(int&num:nums1){
            if(binarySearch(nums2 , num)){
                return num;
            }
        }

        return -1;
    }
};

//T.C :O(n) * O(logm)
//S.C :O(1)
//Approach3 : 2 pointer
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int i = 0 , j = 0;

        while( i < n && j < m){
            if(nums1[i] == nums2[j]){
                return nums1[i];
            }else if(nums1[i] < nums2[j]){
                i++;
            }else{
                j++;
            }
        }

        return -1;
    }
};
//T.C :O(n+m)
