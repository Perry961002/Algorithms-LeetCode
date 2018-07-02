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
    vector<int> answer;
    vector<int> postorderTraversal(TreeNode * root) {
        if(root!=NULL)
        {
            if(root->left!=NULL)
                postorderTraversal(root->left);
            if(root->right!=NULL)
                postorderTraversal(root->right);
            answer.push_back(root->val);
        }
        return answer;
    }
};