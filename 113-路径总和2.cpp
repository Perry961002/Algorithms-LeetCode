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
    //深搜函数(二叉树，最终结果，中间搜索结果，目标和)，测试中节点值有负数情况，不能剪枝
    void dfs(TreeNode* root, vector<vector<int>> &result, vector<int> &rec, int sum)
    {
        rec.push_back( root->val );
        if (root->left == NULL && root->right == NULL && sum == root->val)  //满足目标值，并且到达叶子节点
        {
            result.push_back(rec);
            return;
        }
        if (root->left != NULL)
        {
            dfs(root->left, result, rec, sum - root->val);  //向左子树递归
            rec.pop_back();  //回溯
        }
        
        if (root->right != NULL)
        {
            dfs(root->right, result, rec, sum - root->val);  //向右子树递归
            rec.pop_back();  //回溯
        }

    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > result;
        vector<int> rec;
        if (root == NULL)
        {
            return result;
        }
        dfs(root, result, rec, sum);
        return result;

    }
};