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
    int kthSmallest(TreeNode* root, int k) {
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
    }
};