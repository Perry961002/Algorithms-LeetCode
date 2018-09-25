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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //因为是二叉搜索树,根据p,q点的大小递归寻找
        if(root == NULL || p == NULL || q == NULL)
            return NULL;
        //递归右子树
        if(p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        //递归左子树
        else if(p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        //p, q有一个是root
        else
            return root;
    }
};