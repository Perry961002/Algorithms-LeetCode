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
    TreeNode* deleteNode(TreeNode* root, int key) {
        //二分查找结点
        //删除节点
        if(root == NULL)
            return root;
        //在左子树中
        if(key < root->val)
        {
            root->left = deleteNode(root->left, key);
            return root;
        }
        else if(key > root->val)
        {
            //在右子树中
            root->right = deleteNode(root->right, key);
            return root;
        }
        else
        {
            //找到key
            TreeNode* left = root->left, *right = root->right, *tem = left;
            delete root;
            if(!left || !right) 
                return left?left: right;
            while(tem->right) 
                tem = tem->right;
            tem->right = right->left; right->left = left;
            return right;
        }
    }
};