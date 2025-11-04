//Approach1: using recursion

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
    void InorderTraversalHelper(TreeNode* root , vector<int>&result){
        if(root == NULL){
            return;
        }

        InorderTraversalHelper(root->left , result);
        result.push_back(root->val);
        InorderTraversalHelper(root->right , result);
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>result;

       InorderTraversalHelper(root,result);

        return result;
    }
};

//T.C : O(N)
//S.C : O(h) h = logn

//Approach2 : iterative approach using stack
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> Inorder;
        stack<TreeNode*> st;

        TreeNode* curr = root;

        while(curr != NULL || !st.empty()){
            //step1/ go to extreme left
            while(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }

            //step2.backtrack & print node
            curr = st.top();
            st.pop();
            Inorder.push_back(curr->val);

            //step3.move to right subtree
            curr = curr->right;
        }

        return Inorder;
    }
};
//T.C :O(N)
//S.C :O(N) = o(h) h = logn


//alternative code
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> Inorder;
        stack<TreeNode*> st;

        TreeNode* curr = root;

        while(true){
            if(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }else{
                if(st.empty()) break;
                
                //backtrack
                curr = st.top();
                st.pop();

                Inorder.push_back(curr->val);
                curr = curr->right;
            }
        }

        return Inorder;
    }
};
//T.c :O(N);
//S.C :O(N) = O(h) h = logn
