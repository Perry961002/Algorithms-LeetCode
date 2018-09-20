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
    //简单的深搜，用map记录子树元素和，次数
    //因为取次数最多的，所以要排序，注意map的默认排序是对key的
    void dfs(TreeNode* node, map<int,int>& m)
    {
        if(node == NULL)
            return;
        if(node->left != NULL)
        {
            dfs(node->left, m);
            node->val += node->left->val;
        }
        if(node->right != NULL)
        {
            dfs(node->right, m);
            node->val += node->right->val;
        }
        m[node->val] ++;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int, int> m;
        dfs(root,m);
        vector<int> result;
        int most = 0;
        //找最大的次数
        for(auto it = m.begin();it != m.end();it++)
            most = max(most, it->second);
        for(auto it = m.begin();it != m.end();it++)
        {
            if(it->second == most)
                result.push_back(it->first);
        }
        return result;
    }
};