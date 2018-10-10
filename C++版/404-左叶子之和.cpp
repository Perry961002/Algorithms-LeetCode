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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL)
            return 0;
        //root的左节点是叶子节点
        if(root->left != NULL && root->left->left == NULL && root->left->right == NULL)
            return root->left->val + sumOfLeftLeaves(root->right);
        //左右子树的左节点
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};