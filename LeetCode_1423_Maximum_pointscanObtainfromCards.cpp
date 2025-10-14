//Approach1 : sliding window and 2 pointer
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int lsum = 0 , rsum = 0 , maxSum = 0;

        //find lsum for all k elements from left
        for(int i = 0; i < k; i++) lsum += cardPoints[i];
        maxSum = lsum;

        //now , remove 1 element from left and add one element from right
        int rightI = n-1;
        for(int i = k-1; i >= 0; i--){
            lsum -= cardPoints[i];
            rsum += cardPoints[rightI];
            rightI--;

            maxSum = max(maxSum , lsum+rsum);
        }

        return maxSum;
    }
};

//T.C : O(2*k)
//S.C : O(1)
