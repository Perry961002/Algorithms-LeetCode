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
    //简单的深搜
    void dfs_path(vector<string>& res, string s, TreeNode* node)
    {
        if(node->left == NULL && node->right == NULL)//扫描到了叶子节点
        {
            res.push_back(s);
            return;
        }
        else
        {
            if(node->left)
                dfs_path(res, s + "->" + to_string(node->left->val), node->left);
            if(node->right)
                dfs_path(res, s + "->" + to_string(node->right->val), node->right);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(root == NULL)
            return result;
        dfs_path(result, to_string(root->val), root);
        return result;
    }
};