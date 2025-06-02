//Approach 1 : brute force 
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int> visited(n2,0);
        vector<int> ans;

        for(int i = 0; i < n1; i++){
            for(int j = 0; j < n2; j++){
                if(nums1[i] == nums2[j] && visited[j] == 0){
                    ans.push_back(nums1[i]);
                    visited[j]=1;
                    break;
                }

                
            }
        }

        return ans;
    }
};

//T.C = O(n1*n2)
//S.c = O(n2)

//similar code - if arrays are sorted 
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        sort(nums1.begin() , nums1.end());
        sort(nums2.begin() , nums2.end());


        vector<int> visited(n2,0);
        vector<int> ans;

        for(int i = 0; i < n1; i++){
            for(int j = 0; j < n2; j++){
                if(nums1[i] == nums2[j] && visited[j] == 0){
                    ans.push_back(nums1[i]);
                    visited[j]=1;
                    break;
                }

                if( nums2[j] >nums1[i]) break;
            }
        }

        return ans;
    }
};
//Appraoch 2 : optimal two pointer approach 
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        sort(nums1.begin() , nums1.end());//n1logn1
        sort(nums2.begin() , nums2.end());//n2logn2

        vector<int> ans;

        int i = 0;
        int j = 0;

        while(i<n1 && j < n2){//O(n1+n2)
            if(nums1[i]<nums2[j]){
                i++;
            }else if(nums2[j]<nums1[i]){
                j++;
            }else{
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }

        return ans;
    }
};

//T.C = O(n1logn1 + n2logn2)
//S.C = O(min(n1 , n2)

//Approach 3 : using unordered map 
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;

        // for(auto it : nums1){
        //     mp[it]++;
        // }

        for(int &num : nums1){//this can modify the vector //O(n)
            mp[num]++;
        }

        vector<int> result;
        for(int i = 0; i < nums2.size();i++){//O(m)
            int num=nums2[i];

            if(mp[num] >0){
                result.push_back(num);
                mp[num]--;
            }
        }

        return result;
    }
};
//T.C :O(m+n)
//S.C: O(n) for map 
//     O(min(n,m)
