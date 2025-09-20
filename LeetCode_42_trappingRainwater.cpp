//Approach1 : using prefixmin array and suffix min array
class Solution {
public:
    vector<int> getLeft_maxArray(vector<int>& height , int & n){
        vector<int> leftMax(n);

        leftMax[0] = height[0];
        for(int i = 1; i < n; i++){
            leftMax[i] = max(leftMax[i-1] , height[i]);
        }
        return leftMax;
    }

    vector<int> getRight_maxArray(vector<int>& height , int & n){
        vector<int> rightMax(n);

        rightMax[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--){
            rightMax[i] = max(rightMax[i+1] , height[i]);
        }
        return rightMax;
    }
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> left_max = getLeft_maxArray(height , n);
        vector<int> right_max = getRight_maxArray(height , n);

        int sum = 0;
        for(int i = 0; i < n; i++){
            int water = min(left_max[i] , right_max[i]) - height[i];

            sum += water;
        }

        return sum;
    }
};
//T.C : O(3n)
//S.C :O(2n) 


//Approach2 : using suffixmax array and make a variable for leftmax
class Solution {
public:
   

    vector<int> getRight_maxArray(vector<int>& height , int & n){
        vector<int> rightMax(n);

        rightMax[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--){
            rightMax[i] = max(rightMax[i+1] , height[i]);
        }
        return rightMax;
    }
    int trap(vector<int>& height) {
        int n = height.size();

        int leftMax = height[0];
        vector<int> right_max = getRight_maxArray(height , n);

        int sum = 0;
        for(int i = 0; i < n; i++){
            leftMax = max(leftMax  , height[i]);
            int water = min(leftMax, right_max[i]) - height[i];

            sum += water;
        }

        return sum;
    }
};
//T.C :O(2N)
//S.c :O(N)


//Approach3 : two pointer approach 
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int lmax = 0;
        int rmax = 0;
        int ans = 0;

        while(l < r){
            lmax = max(lmax , height[l]);
            rmax = max(rmax , height[r]);

            if(lmax < rmax){
                ans += lmax - height[l];
                l++;
            }else{
                ans += rmax - height[r];
                r--;
            }
        }

        return ans;
    }
};
//T.C :O(N) 
//S.C :O(1) 

//Approach4 : using stack 

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;

        stack<int> st;
        for(int i = 0; i < n; i++){
            //right boundary milti rhe tbtk
            while(!st.empty() && height[i] > height[st.top()]){
                int mid = st.top();
                st.pop();
                
                //left boundary nhi hai 
                if(st.empty()) break;

                int leftIndex = st.top();
                int distance = i - leftIndex - 1;

                water += (min(height[leftIndex] , height[i]) - height[mid]) * distance;
            }

            st.push(i);
        }

        return water;
    }
};

//T.C :O(n)
//S.C : O(n)
