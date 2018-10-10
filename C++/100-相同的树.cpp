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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)//都是空树
            return true;
        else if(p == NULL || q == NULL)//有一个空，另一个不空
            return false;
        else
        {
            if(p->val != q->val)
                return false;
            else//比较左右子树, 都相等的话整个树相同
                return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
};