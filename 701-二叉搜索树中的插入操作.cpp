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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* insert = new TreeNode(val);
        if(root == NULL)
            return insert;
        TreeNode *cur = root, *pre = NULL;
        //查找插入的位置,pre是被插的根节点
        while(cur != NULL){
            pre = cur;
            if(val < cur->val)
                cur = cur->left;
            else
                cur = cur->right;
        }
        if(pre->val > val)
            pre->left = insert;
        else
            pre->right = insert;
        return root;
    }
};