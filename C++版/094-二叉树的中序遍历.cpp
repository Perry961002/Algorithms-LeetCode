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
    /*递归实现
    vector<int> answer;
    vector<int> inorderTraversal(TreeNode * root) {
        if(root!=NULL)
        {
            if(root->left!=NULL)
                inorderTraversal(root->left);
            answer.push_back(root->val);
            if(root->right!=NULL)
                inorderTraversal(root->right);
        }
        return answer;
    }
        */
    //非递归实现
     vector<int> inorderTraversal(TreeNode * root) {
         vector<int> result;
         stack<TreeNode*> s;
         TreeNode * node = root;
         while(node || !s.empty())
         {
             if(node != NULL)
             {
                 //将最左边的节点入栈
                 s.push(node);
                 node = node->left;
             }
             else
             {
                 //开始访问每个子树根节点和右子树
                 node = s.top();
                 s.pop();
                 result.push_back(node->val);
                 node = node->right; //右子树
             }
         }
         return result;
    }
};