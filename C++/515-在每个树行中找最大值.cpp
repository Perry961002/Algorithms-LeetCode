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
    vector<int> largestValues(TreeNode* root) {
        //层次遍历
        vector<int> result;
        if(!root)
            return result;
        queue<TreeNode*> que;
        que.push(root);
        //层次遍历
        while(!que.empty())
        {
            int maxNum = INT_MIN;
            int count = que.size();//每层节点的个数
            while(count--)
            {
                TreeNode* node = que.front();
                que.pop();
                maxNum = max(maxNum, node->val);
                if(node->left)
                    que.push(node->left);
                if(node->right)
                    que.push(node->right);
            }
            result.push_back(maxNum);
        }
        return result;
    }
};