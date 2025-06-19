//Approach 1 : Bruteforce 
//Stand at one number and go through all the no's of its right and check condition if right then increase the no of count

//Code : 
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j <n;j++){
                if(nums[i] > 2 * nums[j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

//Approach2 : using mergersort algorithm with some modification 

//Code using Global variable
class Solution {
public:

    int cnt = 0;//global variable

    void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}
    void countPair(vector<int> &arr, int low , int mid , int high){
        int right = mid+1;
        for(int i = low; i <= mid ; i++){
            while(right <= high && (long long)arr[i] > 2LL* arr[right]) right++;
            cnt += right - (mid+1);
        }
    }

    void mergeSort(vector<int> &arr, int low, int high) {
        if (low >= high) return;
        int mid = (low + high) / 2 ;
        mergeSort(arr, low, mid);  // left half
        mergeSort(arr, mid + 1, high); // right half
        countPair(arr , low , mid , high);
        merge(arr, low, mid, high);  // merging sorted halves
    }


    int reversePairs(vector<int>& nums) {
        int n = nums.size();

        mergeSort(nums, 0 , n-1);
        return cnt ;

    }
};

//Alternate version : 
class Solution {
public:

    

    void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}
    int countPair(vector<int> &arr, int low , int mid , int high){
        int right = mid+1;
        int cnt = 0;
        for(int i = low; i <= mid ; i++){
            while(right <= high && (long long)arr[i] > 2LL* arr[right]) right++;
            cnt += right - (mid+1);
        }
        return cnt;
    }

    int mergeSort(vector<int> &arr, int low, int high) {
        int cnt = 0;
        if (low >= high) return cnt;
        int mid = (low + high) / 2 ;
        cnt += mergeSort(arr, low, mid);  // left half
        cnt += mergeSort(arr, mid + 1, high); // right half
        cnt += countPair(arr , low , mid , high);
        merge(arr, low, mid, high);  // merging sorted halves
        return cnt;
    }


    int reversePairs(vector<int>& nums) {
        int n = nums.size();


        return mergeSort(nums, 0 , n-1);

    }
};

//T.C : O(nlogn)
//S.C : O(n)
