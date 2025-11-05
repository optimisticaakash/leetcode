//Approach1 : recursive appraoch
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
    void postorderTraversalHelper(TreeNode* root , vector<int>&result){
        //base case
        if(root == NULL) return;

        postorderTraversalHelper(root->left ,result);
        postorderTraversalHelper(root->right,result);
        result.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>result;

        postorderTraversalHelper(root , result);
        return result;
    }
};

//T.C :O(N)
//S.C :O(logN)

//Approach2 : iterative appraoch using 2 stack
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>postorder;
        if(root == NULL) return postorder;
        stack<TreeNode*> st1 ,st2;

        st1.push(root);
        while(!st1.empty()){
            TreeNode* curr = st1.top();
            st1.pop();
            st2.push(curr);

            if(curr->left != NULL){
                st1.push(curr->left);
            }
            if(curr->right != NULL){
                st1.push(curr->right);
            }
        }

        while(!st2.empty()){
            postorder.push_back(st2.top()->val);
            st2.pop();
        }

        return postorder;
    }
};
//T.C :O(2N)
//S.C :O(2N)


//Approach3 : using 1 stack - previous approach better version

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>postorder;
        if(root == NULL) return postorder;
        stack<TreeNode*> st1 ;

        st1.push(root);
        while(!st1.empty()){
            TreeNode* curr = st1.top();
            st1.pop();
            postorder.push_back(curr->val);

            if(curr->left != NULL){
                st1.push(curr->left);
            }
            if(curr->right != NULL){
                st1.push(curr->right);
            }
        }

        reverse(postorder.begin() , postorder.end());

        return postorder;
    }
};
//T.C :O(2N)
//S.C :O(N)

//Approach4 : using 1 stack
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        TreeNode* curr = root;
        stack<TreeNode*> st;
        while(curr != NULL || !st.empty()){
            if(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }else{
                TreeNode* temp = st.top()->right;
                if(temp == NULL){
                    temp = st.top();
                    st.pop();

                    postorder.push_back(temp->val);

                    while(!st.empty() && temp == st.top()->right){
                        temp = st.top();
                        st.pop();

                        postorder.push_back(temp->val);
                    }
                }else{
                    curr = temp;
                } 
            }
        }

        return postorder;
    }
};
//T.C :O(2N)
//s.c :O(N)
