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
    //判断两个树是否相等
    bool isSame(TreeNode* s, TreeNode* t){
        //s和t都是空
        if(s == NULL && t == NULL)
            return true;
        //s和t有1个空,另一个不空
        if(s == NULL || t == NULL)
            return false;
        //节点的值不相同
        if(s->val != t->val)
            return false;
        //比较左右子树是否相等
        return isSame(s->left, t->left) && isSame(s->right, t->right);
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == NULL)
            return false;
        //s和t相等
        if(isSame(s, t))
            return true;
        //否则在s的左右子树中找t
        else
            return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};