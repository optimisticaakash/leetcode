//Approach1 : bruteforce class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int i = 0; 
        int j = 0;

        int n = n1 + n2;
        int ind2 = n/2;
        int ind1 = ind2 - 1;

        int cnt = 0;
        int ind1ele = INT_MIN;
        int ind2ele = INT_MIN;
        while(i < n1 && j < n2){
            if(nums1[i] < nums2[j]){
                if(cnt == ind1) ind1ele = nums1[i];
                if(cnt == ind2) ind2ele = nums1[i];
                cnt++;
                i++;
            }
            else{
                if(cnt == ind1) ind1ele = nums2[j];
                if(cnt == ind2) ind2ele = nums2[j];
                cnt++;
                j++;
            }
        }
        while(i < n1){
            if(cnt == ind1) ind1ele = nums1[i];
            if(cnt == ind2) ind2ele = nums1[i];
            cnt++;
            i++;
        }
        while(j<n2){
            if(cnt == ind1) ind1ele = nums2[j];
            if(cnt == ind2) ind2ele = nums2[j];
            cnt++;
            j++;
        }
        if(n%2 == 1) return ind2ele;

        return (double)((double)ind1ele + ind2ele)/2.0;
    }
};
//T.C : O(n1+n2)
//S.C : O(1)

//Approach3:

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        //if n1 is bigges swap the array , bcz we want to binary search in smaller array
        if(n1 > n2) return findMedianSortedArrays(nums2,nums1);
        int low = 0  , high = n1;
        int n = n1+n2;
        int leftHalf = (n+1)/2; //ensure correct partition for both even and odd total sizes
        while(low <= high){
            //right shift by 1 bit, which is the same as dividing an integer by 2.
            int mid1 = (low+high) >> 1; // same as mid = (low+high)/2; 
            // used to avoid overflow in some cases

            int mid2 = leftHalf - mid1;
            int l1 = INT_MIN , l2 = INT_MIN;
            int r1 = INT_MAX , r2 = INT_MAX;
            if(mid1 < n1) r1 = nums1[mid1];
            if(mid2 < n2) r2 = nums2[mid2];
            if(mid1 - 1 >= 0) l1 = nums1[mid1-1];
            if(mid2 - 1 >= 0) l2 = nums2[mid2-1];

            if(l1 <= r2 && l2 <= r1){
                if(n%2 == 1) return max(l1,l2);
                return (double)(max(l1,l2)+ min(r1,r2))/2.0;
            }
            else if(l1>r2) high = mid1-1;
            else low = mid1+1;
        }
        return 0;
    }
};
//TC : O(log(min(n1,n2)))
//S.C : O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> nums3;

        int i = 0;
        int j = 0;

        while( i < n && j < m){
            if(nums1[i] < nums2[j]) nums3.push_back(nums1[i++]);
            else nums3.push_back(nums2[j++]);
        }
        while(i < n) nums3.push_back(nums1[i++]);
        while(j < m) nums3.push_back(nums2[j++]);

        int num = n+ m;

        if(num % 2 == 1) return nums3[num/2];
        return (double)((double)nums3[num/2] + (double)nums3[num/2 - 1])/2.0;
    }

    
};

//T.C : O(n+m)
//S.C : O(n+m)

//Approach 2:
