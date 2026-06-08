//Approach1 : using  ans vector  and pivot vector and put less than right into the ans and equal to pivot into pivotvector
//then run loop in pivot vector and put pivots to the ans vector
//and after than again run loop to the nums and greater elemet to the ans vector

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        vector<int>ans;
        vector<int> pivots;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < pivot){
                ans.push_back(nums[i]);
            }
            else if(nums[i] == pivot){
                pivots.push_back(nums[i]);
            }
        }

        for(int it : pivots){
            ans.push_back(it);
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > pivot){
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};

//T.C : O(3n) = O(n)
//S.C : O(2n) = O(n)

//Approach2: Similar approach as 1 , but instead of pivot vector we just maintain cnt of the pivot vector
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        vector<int>ans;
        int pivots = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < pivot){
                ans.push_back(nums[i]);
            }
            else if(nums[i] == pivot){
                pivots++;
            }
        }

        while(pivots--){
            ans.push_back(pivot);
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > pivot){
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};

//T.C : O(2n) = O(n)
//S.C : O(N)

//Approach3 : using 3 pointer and ans vector
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        vector<int> ans(n , 0);

        int cntless = 0;
        int equal = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] < pivot)cntless++;
            else if(nums[i] == pivot) equal++;
        }

        int i = 0;//less pointer
        int j = cntless;//equal pointer
        int k = cntless + equal;

        for(int idx = 0; idx < n; idx++){
            if(nums[idx] < pivot){
                ans[i] = nums[idx];
                i++;
            }else if(nums[idx] == pivot){
                ans[j] = nums[idx];
                j++; 
            }else{
                ans[k] = nums[idx];
                k++;
            }
        }

        return ans;
    }
};

//T.C : O(2n)
//S.C : O(N)

//Approach4: using 2 pointers in ans and nums vector
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        vector<int> ans(n);

        //original nums
        int i = 0;
        int j = n-1;

        //ans variable
        int i_ = 0;
        int j_ = n-1;

        while(i < n && j >= 0){
            if(nums[i] < pivot){
                ans[i_] = nums[i];
                i_++;
            }
            if(nums[j] > pivot){
                ans[j_] = nums[j];
                j_--;
            }

            i++;
            j--;
        }

        while(i_ <= j_){
            ans[i_] = pivot;
            i_++;
        }

        return ans;
    }
};
