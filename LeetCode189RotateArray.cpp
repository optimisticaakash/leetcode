//Approach 1 : Brute Froce 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k=k%n;

        vector<int> temp;
        //store first (n-k) no of elements to temp
        for(int i = 0; i <n-k; i++){//O(n-k)
            temp.push_back(nums[i]);
        }

        //now shift last k elements to front of the array 
        int j = 0;
        for(int i = n-k; i < n; i++){//O(k)
            nums[j] = nums[i];
            j++;
        }

        //now put back temp elements to nums last
        for(int i = k; i<n; i++){//O(k)
            nums[i] = temp[(i-(k))];
        }

    }
};

//Diiferent version code

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k=k%n;

        vector<int> temp;
        //store first (n-k) no of elements to temp
        for(int i = 0; i <n-k; i++){
            temp.push_back(nums[i]);
        }

        //now shift last k elements to front of the array 
        
        for(int i = n-k; i < n; i++){
            nums[i-(n-k)] = nums[i];
            
        }

        //now put back temp elements to nums last
        for(int i = k; i<n; i++){
            nums[i] = temp[(i-(k))];
        }

    }
};
//T.C = O(n-k+k+k) = O(n+k)
//S.C = O(k)

//Approach 2 : better appraoch 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> rotated(n);

        for(int i = 0; i < n; i++){//O(n)
            rotated[(i+k)%n] = nums[i];
        }

        for(int i = 0; i < n; i++){//(n)
            nums[i] = rotated[i];
        }
    }
};

//T.C= O(n)
//S.C= O(n)

//Appraoch 3 : reverse logic 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;


        reverse(nums.begin() , nums.end());//0 to. n-1 reverse
        reverse(nums.begin() , nums.begin()+(k));//0 to k-1 tk reverse
        reverse(nums.begin()+k , nums.end());//k t0 n-1 ; reverse
        

    }
};

//T.C = O(2N)
//S.c = O(1)
