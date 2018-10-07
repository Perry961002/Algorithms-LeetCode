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
    //DFS求高度,发现不符合定义的就返回-1,否则返回树的真实高度
    int getHeight(TreeNode* root){
        if(root == NULL)
            return 0;
        int llen = getHeight(root->left);//左子树高度
        int rlen = getHeight(root->right);//右子树高度
        //左右子树有不符合要求的,或者当前节点不符合
        if(llen < 0 || rlen < 0 || abs(llen - rlen) > 1)
            return -1;
        else
            return max(llen, rlen) + 1;//返回高度
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        int llen = getHeight(root->left);//左子树高度
        int rlen = getHeight(root->right);//右子树高度
        //左右子树有不符合要求的,或者当前节点不符合
        if(llen < 0 || rlen < 0 || abs(llen - rlen) > 1)
            return false;
        else
            return true;
    }
};