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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        //规则很清楚了,递归着来
        if(d == 1){
            //如果 d 的值为 1，深度 d - 1 不存在，则创建一个新的根节点 v，原先的整棵树将作为 v 的左子树
            TreeNode* res = new TreeNode(v);
            res->left = root;
            return res;
        }
        if(d == 2){
            //插入左节点
            TreeNode* newLeft = new TreeNode(v);
            //原来的左子树还是新节点的左子树
            newLeft->left = root->left;
            newLeft->right = NULL;
            root->left = newLeft;
            
            //插入右节点
            TreeNode* newR = new TreeNode(v);
            //原来的右子树还是新节点的右子树
            newR->right = root->right;
            newR->left = NULL;
            root->right = newR;
            
            return root;
        }
        else{
            if(root->left){
                addOneRow(root->left, v, d - 1);
            }
            if(root->right){
                addOneRow(root->right, v, d - 1);
            }
        }
        return root;
    }
};