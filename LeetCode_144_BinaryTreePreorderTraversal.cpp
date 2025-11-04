//Approach1 : using recursion 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void preorderTraverse(TreeNode* root , vector<int>&result){
        if(root == NULL) return;

        result.push_back(root->val);

        preorderTraverse(root->left , result);
        preorderTraverse(root->right, result);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorderTraverse(root , result);

        return result;
    }
};

//T.C :O(N)
//S.C : O(N)

//Approach2 : using iterative approach (using stack ) 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if(root == NULL) return preorder;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();
            preorder.push_back(curr->val);

            //rightnode dalo stack me phle
            if(curr->right != NULL){
                st.push(curr->right);
            }

            if(curr->left != NULL){
                st.push(curr->left);
            }
        }

        return preorder;
    }
};


//T.C :O(N)
//S.C :O(N) in worst case where each node have only one right node
