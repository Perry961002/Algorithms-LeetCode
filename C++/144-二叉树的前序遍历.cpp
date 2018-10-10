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
        /* 递归实现
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
        */
        //非递归实现
        vector<int> result;
        if(root == NULL)
            return result;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* p = s.top();
            s.pop(); //出栈
            result.push_back(p->val);
            if(p->right)
                s.push(p->right);
            if(p->left)
                s.push(p->left);
        }
        return result;
    }
};