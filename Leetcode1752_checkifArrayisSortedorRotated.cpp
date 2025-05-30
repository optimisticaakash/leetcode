//Approach 1 : check all the possible rotated  array  of given array and then check if it is sorted or not 

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted(n);
        //check for every possible rotation 
        for(int r = 0; r < n; r++){//O(n)
            int idx = 0;
            for(int i = r; i < n ; i++){//O(n)
                sorted[idx] = nums[i];
                idx++;
            }
            //for putting remaining element in the sorted array
            for(int i = 0; i < r; i++){//O(n)
                sorted[idx] = nums[i];
                idx++;
            }

            //is the array sorted 
            bool isSorted = true;
            for(int i = 0; i < n-1; i++){//O(n)
              //n-1 bcz for for n , i+1 out of bound ho jyega
                if(sorted[i] > sorted[i+1]){
                    isSorted = false;
                    break;
                }
            }

            if(isSorted == true){
                return true;
            }
        }
        return false;
    }
};
//TC = O(N*(3N)) = O(n^2)
//SC = O(N) // due to use ofsorted array 


// NOTE :- if array is rotated 'x' no of times then the rotated array form such that 
// rotated[i] = nums[(i+x)%n] where n is size of original array 
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        vector<int> sorted(n);
        //check all possible rotations 
        for(int r = 0; r < n; r++){
            //rotate array by r times or rotate array by r positions 
            
            for(int i = 0; i < n; i++){
                sorted[i] = nums[(i+r)%n];
            }

            //check if array is sorted 
            bool isSorted = true;
            for(int i = 0; i < n-1; i++){
                if(sorted[i] > sorted[i+1]){
                    isSorted = false;
                    break;
                }
            }
            if(isSorted == true) return true;
        }
        return false;
    }
};
//slightly improved code 

//TC= O(N^2)
//SC = O(N)

