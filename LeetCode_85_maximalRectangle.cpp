//Approach1 : 
class Solution {
public:
    int findMaxArea(vector<int>&height){
        int n = height.size();
        stack<int> st;

        int maxArea = 0;

        for(int i = 0; i < n; i++){
            while(!st.empty() && height[st.top()] > height[i]){
                int element = st.top(); st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                maxArea = max(maxArea , height[element] * (nse - pse - 1));
            }
            st.push(i);
        }

        while(!st.empty()){
            int nse = n;
            int element = st.top(); st.pop();
            
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea , height[element] * (nse - pse - 1));
        }

        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();//row
        int m = matrix[0].size();//col

        
        vector<int> height(m);

        for(int i = 0; i < m; i++){
            height[i] = (matrix[0][i] == '1') ? 1 : 0;
        }

        int maxArea = findMaxArea(height);

        for(int row = 1; row < n;row++){
            for(int col = 0; col < m; col++){

                if(matrix[row][col] == '0'){
                    height[col] = 0;
                }else{
                    height[col]+= 1;
                }
            }

            maxArea = max(maxArea , findMaxArea(height));
        }

    return maxArea;
    }
};

//T.c :(m*n) + O(2m) 
//S.C :O(M)
//Approach 2 :
class Solution {
public:
    int findMaxArea(vector<int>&height){
        int n = height.size();
        stack<int> st;

        int maxArea = 0;

        for(int i = 0; i < n; i++){
            while(!st.empty() && height[st.top()] > height[i]){
                int element = st.top(); st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                maxArea = max(maxArea , height[element] * (nse - pse - 1));
            }
            st.push(i);
        }

        while(!st.empty()){
            int nse = n;
            int element = st.top(); st.pop();
            
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea , height[element] * (nse - pse - 1));
        }

        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();//row
        int m = matrix[0].size(); //col

        vector<vector<int>> psum(n , vector<int>(m , 0));

        for(int j = 0; j < m; j++){
            int sum = 0;
            for(int i = 0; i < n; i++){
                sum += (matrix[i][j]-'0');
                if(matrix[i][j] == '0') sum = 0;
                
                psum[i][j] = sum;
            }
        }

        int maxArea = 0;
        for(int i = 0; i < n; i++){
            maxArea = max(maxArea , findMaxArea(psum[i]));
        }
        return maxArea;
    }
};
//T.C :O(m*n) + O(n) 
//S.C :O(M*N)
