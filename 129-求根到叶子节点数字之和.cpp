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
    int dfs(TreeNode* root,int sum)
    {
        if(root->left == NULL && root->right == NULL)  //没有左右子树
        {
            return sum * 10 + root->val;
        }
        int left = 0,right = 0;
        if(root->left != NULL)
            left = dfs(root->left,sum * 10 + root->val);
        if(root->right != NULL)
            right = dfs(root->right,sum * 10 + root->val);
        return left + right;
    }
    int sumNumbers(TreeNode* root) {
        if(root == NULL)
            return 0;
        return dfs(root,0);
    }
};