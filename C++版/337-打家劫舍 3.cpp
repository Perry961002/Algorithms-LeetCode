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
    int rob(TreeNode* root) {
        if(root == NULL)
            return 0;
        int grandchild = 0;  //根节点的孙辈
        if (root->left != NULL)
        {
            grandchild += rob(root->left->left) + rob(root->left->right);
        }
        if (root->right != NULL)
        {
            grandchild += rob(root->right->left) + rob(root->right->right);
        }
        //偷根节点和孙辈， 偷子辈
        return max(grandchild + root->val, rob(root->left) + rob(root->right));
    }
};