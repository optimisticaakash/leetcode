//Approach1: using brute force: 
//nestedloop
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);

        for(int i = 0; i < n; i++) {
            bool found = false;
            //ito n
            for(int j = i+1; j < n; j++) {  // ek round mein max n-1 steps
                if(nums[j] > nums[i]) {
                    result[i] = nums[j];
                    found = true;
                    break;
                }
            }
            //0 to i
            if(!found) {
                for(int j = 0; j < i; j++) {
                    if(nums[j] > nums[i]) {
                        result[i] = nums[j];
                        break;
                    }
                }
            }

        }

        return result;

    }
};

//T.C : O(N2) 
//S.C :O(N) 


//alternative code: bruteforce using circular array concept
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n,-1);

        for(int i = 0; i < n; i++){
            for(int j = 1; j < n; j++){
                int idx = (i+j)%n;
                if(nums[idx] > nums[i]){
                    result[i]= nums[idx];
                    break;
                }

            }
        }

        return result;
    }
};
//T.C :O(n2)
//S.C :(n)

//Approach2 : using circular array concept doubleing the array striver
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n,-1);

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < i+n;j++){
                int ind = j%n;
                if(nums[ind] > nums[i]){
                    result[i] = nums[ind];
                    break;
                }
            }
        }
        return result;
    }
};

//T.C :O(N2)
//S.C :(N)

//Approach 3 : optimisted Approach (using stack) 
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n , -1);

        stack<int> st;

        for(int i = 2*n -1 ; i >= 0; i--){
            while(!st.empty() && st.top() <= nums[i%n]){
                st.pop();
            }
            
            //number jinke nges chahiye
            if(i < n){
                result[i] = st.empty() ? -1 : st.top();
            }
            st.push(nums[i%n]);
        }

        return result;
    }
};
//T.c :O(4N) 
//S.C :O(2N) + O(N)

