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
    int target;
    void inorder(TreeNode* root, int &res){
        if(root->left)
            inorder(root->left, res);
        --target;
        if(target == 0){
            res = root->val;
        }
        if(root->right)
            inorder(root->right, res);
    }
    int kthSmallest(TreeNode* root, int k) {
        /*
        //方法一栈实现
        stack<TreeNode*> s;
        int count = k;
        TreeNode* p = root;
        while(!s.empty() || p != NULL)
        {
            if(p != NULL)  //将最左边的节点入栈
            {
                s.push(p);
                p = p->left;
            }
            else
            {
                count --;
                if(count == 0)
                    break;
                p = s.top();
                s.pop();
                p = p->right;
            }
        }
        return s.top()->val;
        */
        target = k;
        int res = 0;
        inorder(root, res);
        return res;
    }
};