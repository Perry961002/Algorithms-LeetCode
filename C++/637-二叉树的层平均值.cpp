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
    vector<double> averageOfLevels(TreeNode* root) {
        //只有一个节点
        if(!root->left && !root->right)
            return {root->val * 1.0};
        //BFS
        vector<double> res;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            long curSum = 0;
            int len = que.size();
            for(int i=0;i<len;i++){
                TreeNode* cur = que.front();
                que.pop();
                curSum += cur->val;
                if(cur->left)
                    que.push(cur->left);
                if(cur->right)
                    que.push(cur->right);
            }
            res.push_back(curSum / (len * 1.0));
        }
        return res;
    }
};