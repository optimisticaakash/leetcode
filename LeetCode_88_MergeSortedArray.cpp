//Approach1: bruteforce using 2 pointer
//Code:
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = 0;
        int right = 0;
        vector<int> ans;
        while(left < m && right < n){
            if(nums1[left] <= nums2[right]){
                ans.push_back(nums1[left]);
                left++;
            }else{
                ans.push_back(nums2[right]);
                right++;
            }
        }

        while(left < m){
            ans.push_back(nums1[left]);
            left++;
        }

        while(right < n){
            ans.push_back(nums2[right]);
            right++;
        }

        for(int i = 0 ;i < ans.size() ; i++){
            nums1[i] = ans[i];
        }

        return;
    }
};

//T.C : O(2*(m+n))
//S.C : O(m+n)

//Approach  2 : Better approach 
//copy nums2 element to nums1 and the sort 

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = 0; i < n; i++){ // o(n)
            nums1[m+i] =  nums2[i];
        }

        sort(nums1.begin() , nums1.end());//O(m+n log(m+n))


    }
};

//T.C: O((m+n)* log(m+n))
//S.C = O(1)

//Approach3: optimal approach using 2 pointer in reverse
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m-1;
        int right = n-1;
        int index = m+n-1;

        while(left >= 0 && right >= 0){
            if(nums1[left] <= nums2[right]){
                nums1[index--] = nums2[right--];
                
            }
            else{
                //nums1[left] > nums2[right]
                nums1[index--] = nums1[left--];
            }
        }

        //when left got exhausted but j me elements bche hai 
        while(right >= 0){
            nums1[index--] = nums2[right--];
        }
    }
};
//T.C : O(m+n)
//S.C + O(1) 
