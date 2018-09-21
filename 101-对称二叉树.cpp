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
    bool checkTree(TreeNode* roota, TreeNode* rootb)
    {
        if(roota == NULL && rootb == NULL)//都是空
            return true;
        else if(roota == NULL || rootb == NULL)
            return false;
        else
        {
            if(roota->val != rootb->val)//两个根节点不等
                return false;
            else//镜像比较
                return checkTree(roota->left, rootb->right) && checkTree(roota->right, rootb->left);
        }
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return checkTree(root->left, root->right);
    }
};