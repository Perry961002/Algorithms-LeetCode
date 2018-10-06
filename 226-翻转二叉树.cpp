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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return root;
        queue<TreeNode*> q;
        q.push(root);
        //迭代的交换左右子节点
        while(!q.empty()){
            TreeNode* curNode = q.front();
            q.pop();
            //保存左节点
            TreeNode* curLeft = curNode->left;
            //交换左右子节点
            curNode->left = curNode->right;
            curNode->right = curLeft;
            if(curNode->left)
                q.push(curNode->left);
            if(curNode->right)
                q.push(curNode->right);
        }
        return root;
    }
};