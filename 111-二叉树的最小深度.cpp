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
    int minDepth(TreeNode* root) {
        //递归解法
        if(root == NULL)
            return 0;
        //无左右子树
        if(root->left == NULL && root->right == NULL)
            return 1;
        int leftMinDepth = INT_MAX, rightMinDepth = INT_MAX;
        //递归左子树
        if(root->left)
            leftMinDepth = minDepth(root->left);
        //递归右子树
        if(root->right)
            rightMinDepth = minDepth(root->right);
        return min(leftMinDepth, rightMinDepth) + 1;
    }
};