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
    /*
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
        */
    //非递归实现
    vector<int> postorderTraversal(TreeNode * root) {
        //按根-右-左访问，最后倒序
        vector<int> result;
        if (root == NULL)
            return result;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode* temp = s.top();
            s.pop();
            result.push_back(temp->val);
            if(temp->left)
                s.push(temp->left);
            if(temp->right)
                s.push(temp->right);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};