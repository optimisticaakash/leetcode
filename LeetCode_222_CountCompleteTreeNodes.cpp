//Approach1: recursive approach
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
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;

        int leftCnt = countNodes(root->left);
        int rightCnt = countNodes(root->right);

        return leftCnt + rightCnt +1;
    }
};
//T.C :O(N)
//S.C : O(height)

//Approach2: recursive cnt approach
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
    void PreorderTraversal(TreeNode* root , int &cnt){
        if(root == NULL) return;

        cnt++;//count current node
        PreorderTraversal(root->left,cnt);
        PreorderTraversal(root->right,cnt);
        
    }
    int countNodes(TreeNode* root) {
        int cnt = 0;
        PreorderTraversal(root, cnt);

        return cnt;
    }
};
//T.C :O(N)
//S.C :O(N)

//Approach3: level order 
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
    int countNodes(TreeNode* root) {
        int count = 0;
        if(root == NULL) return count;

        queue<TreeNode*>q;
        q.push(root);
        

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            count++;//count current node

            if(curr->left != NULL)q.push(curr->left);
            if(curr->right != NULL)q.push(curr->right);
        }

        return count;
    }
};
//T.C :O(N)
//S.c :O(N)
