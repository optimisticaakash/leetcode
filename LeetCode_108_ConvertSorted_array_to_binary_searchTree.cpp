//Approach 1 ; 
class Solution {
public:
    TreeNode* Construct(int l , int r , vector<int>& nums){
        if(l > r) return NULL;

        int mid = l + (r-l)/2;

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = Construct(l , mid-1 , nums);
        root->right = Construct(mid+1 , r, nums);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;

        return Construct(l , r , nums); // O(N) 
    }
};

//T.C : O(N) 
//S.C :O(logN) stack space 
