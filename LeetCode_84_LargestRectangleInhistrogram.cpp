class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int NoOfRectangle = 1;
        int maxArea = 0;

        for(int i = 0; i < n ; i++){
            int leftIndex = i;
            for(int j = i-1; j >= 0; j--){
                if(heights[j] <  heights[i])break;
                leftIndex = j;
            }

            int rightIndex = i;
            for(int k = i+1; k < n; k++){
                if(heights[i] > heights[k]) break;
                rightIndex = k;
            }

            NoOfRectangle = rightIndex - leftIndex+1;
            maxArea = max(maxArea , NoOfRectangle * heights[i]);
        }

        return maxArea;
    }
};

//T.C : O(n^2)

//Approach 2 : using stack precompute nse and pse
class Solution {
public:
    vector<int> findPSE(vector<int>& heights){
        int n = heights.size();
        vector<int> result(n);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()]  >= heights[i]){
                st.pop();
            }

            if(st.empty())result[i] = -1;
            else result[i] = st.top();

            st.push(i);
        }

        return result;
    }
    vector<int> findNSE(vector<int>& heights){
        int n = heights.size();
        vector<int> result(n);
        stack<int> st;

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()]  >= heights[i]){
                st.pop();
            }

            if(st.empty())result[i] = n;
            else result[i] = st.top();

            st.push(i);
        }

        return result;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int width = 0;
        int maxArea = 0;

        vector<int> pse = findPSE(heights);
        vector<int> nse = findNSE(heights);

        for(int i = 0; i < n; i++){
            width = nse[i]-pse[i]-1;
            maxArea = max(maxArea , heights[i] * width);
        }

        return maxArea;
    }
};
//T.C : O(5N)
//S.C :O(2N)

//Approach3 : using stack without precomputation
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int element = st.top(); st.pop();
                int nse = i;
                int pse = st.empty()?-1:st.top();

                maxArea = max(maxArea , heights[element] * (nse - pse -1));
            }
            st.push(i);
        }

        //bache huye elements ke liye jinka nse = n hoga 
        while(!st.empty()){
                int nse = n;
                int element = st.top(); st.pop();
                int pse = st.empty()?-1: st.top();

                maxArea = max(maxArea , heights[element] * (nse - pse -1));

            }


        return maxArea;
    }
};
//T.C :O(2n)
//S.C :O(1) 
