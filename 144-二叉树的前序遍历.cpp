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
    vector<int> preorderTraversal(TreeNode* root) {
         TreeNode *x = root;  
        vector<TreeNode*> p;  
        vector<int> res;  
        while(x != NULL || p.size() != 0){  
            res.push_back(x->val);  
            if (x->right != NULL)  
                p.push_back(x->right);  
            x = x->left;  
            if (x == NULL && p.size() != 0){  
                x = p.back();  
                p.pop_back();  
            }  
        }  
        return res;  
    }
};