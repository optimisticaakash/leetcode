//Approach1: bruteforce

#include<vector>

int subarrayWithMaxProduct(vector<int> &arr){
	// Write your code here.
	int pre = 1 , suf = 1;
	int ans = INT_MIN;
	int n = arr.size();

	for(int i = 0; i < n; i++){
		if(pre == 0) pre = 1;
		if(suf == 0) suf = 1;

		pre  = pre * arr[i];
		suf = suf * arr[n-i-1];
		ans = max(ans, max(pre , suf));
		
	}
	return ans;
}
//T.C : O(n^2)
//S.C : O(1)

//Approach2: 

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int pre = 1 , suf = 1;

        for(int i = 0; i < n; i++){

            if(pre == 0) pre = 1;
            if(suf == 0) suf = 1;

            pre = pre * nums[i];
            suf = suf * nums[n-i-1];
            ans = max(ans , max(pre,suf));
        }

        return ans;

    }
};

//T.C : O(n) 
//S.C : O(1) 
