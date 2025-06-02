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
