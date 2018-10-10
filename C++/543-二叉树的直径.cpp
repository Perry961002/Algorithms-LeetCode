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
    //最大左右子树深度和
    int getDepth(TreeNode* root, int &len)
    {
        if(root == NULL)
            return 0;
        int left = getDepth(root->left, len);
        int right = getDepth(root->right, len);
        len = max(len, left + right);
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int len = 0;
        getDepth(root, len);
        return len;
    }
};