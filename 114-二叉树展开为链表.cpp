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
    void flatten(TreeNode* root) {
        while(root != NULL){
            if(root->left != NULL){
                TreeNode* pre = root->left;
                //找最右边的节点
                while(pre->right != NULL)
                    pre = pre->right;
                //将root的右子树接到后面
                pre->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right;
        }
    }
};