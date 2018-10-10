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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return false;
        if(root->left == NULL && root->right == NULL && root->val == sum)//到达叶子节点并且路径和满足
            return true;
        //递归左子树
        if(hasPathSum(root->left, sum - root->val))
            return true;
        //递归右子树
        if(hasPathSum(root->right, sum - root->val))
            return true;
        return false;
    }
};