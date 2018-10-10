/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL)
            return NULL;
        //递归修剪左子树
        root->left = pruneTree(root->left);
        //递归修剪右子树
        root->right = pruneTree(root->right);
        //整个树都可以剪去
        if(root->left == NULL && root->right == NULL && root->val == 0)
            return NULL;
        else
            return root;
    }
};