//Approach 1 : Brute force - apply sorting algorithm
//Bubble sort 
class Solution {
public:
    //Bubble sort (O(n^2))
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n-1; j++){
                if(nums[j] > nums[j+1]){
                    swap(nums[j] ,nums[j+1]);
                }
            }
        }
    }
};
//T.c : O(n^2)
//S.C : O(1)

//Merge sort 
class Solution {
public:
    void merge(vector<int> &nums,int low , int mid , int high){
        vector<int> temp;
        //[low .... mid]
        //[mid+1 ..... high]

        int left = low;
        int right = mid+1;
        while(left <= mid && right <= high){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left]);
                left++;
            }else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        //if right get exhausted and elements remain in left put without comparing
        while(left <= mid){
            temp.push_back(nums[left]);
            left++;
        }

        //if left get exhauseted and elements remain in  right
        while(right <= high){
            temp.push_back(nums[right]);
            right++;
        }

        // till this step we can say left sorted and right array is sorted but we need to
        // put into third array temp . but we need to. put from low to high bcz original 
        // we need like that  
        for(int i = low ; i <= high ; i++){
            nums[i] = temp[i-low];
        }
    }
    void ms(vector<int> &nums , int low , int high){
        if(low == high) return;
        int mid = (low + high)/2;

        ms(nums,low , mid);
        ms(nums,mid+1 , high);
        merge(nums,low,mid,high);
    }
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        ms(nums,0 , n-1);
    }
};

//T.C = O(NlogN)
//S.C = O(N)

//Approach 2 : better 
//count no of 0's , 1's and 2's and then fill array first with 0's then 1's and at last with 2's

class Solution {
public:
    void sortColors(vector<int>& nums) {
        //T.C = O(n)
        //S.C = O(1)
        int n = nums.size();
        int cnt0 = 0 , cnt1 = 0 , cnt2 = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == 0) cnt0++;
            else if(nums[i]==1) cnt1++;
            else cnt2++;
        }

        for(int i = 0; i < cnt0;i++){
            nums[i] = 0;
        }

        for(int i = cnt0; i < cnt0 + cnt1; i++){
            nums[i] = 1;
        }

        for(int i = cnt0+cnt1; i < n; i++){
            nums[i] = 2;
        }
    }
};

//Approach 3 : Optimal Approach (Dutch National Flag Algorithm)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int low = 0 , mid = 0 , high = n-1;

        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low] , nums[mid]);
                low++;
                mid++;
            }else if(nums[mid] == 1){
                mid++;
            }else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};

//T.C : O(n)
//S.C : O(1)
