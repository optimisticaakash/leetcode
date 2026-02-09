//Approach 1: 
class Solution {
public:
    TreeNode* Construct(int l , int r , vector<int>& vec){
        if(l > r) return NULL;

        int mid = l + (r-l)/2;

        TreeNode* newRoot = new TreeNode(vec[mid]);

        newRoot->left = Construct(l , mid-1 , vec);//left subtree
        newRoot->right = Construct(mid+1 , r , vec);//right subtree

        return newRoot;
    }
    void Inorder(TreeNode* root , vector<int>& vec){
        if(root == NULL) return;

        Inorder(root->left,vec);//Left
        vec.push_back(root->val);//root
        Inorder(root->right,vec); //Right
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>vec;

        Inorder(root,vec);//O(N)

        int l = 0;
        int r = vec.size()-1;

        return Construct(l , r , vec);//O(N)
    }
};

//T.C : O(N + N) = O(N) 
//S.C : O(N) for vector
