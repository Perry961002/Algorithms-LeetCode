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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        deque<TreeNode*> deq;//双向队列
        int maxLen = 0;
        deq.push_back(root);
        while(!deq.empty())
        {
            int len = deq.size();//上一层的宽度
            maxLen = max(maxLen, len);
            while(len--)
            {
                TreeNode* node = deq.front();
                deq.pop_front();
                if(node)
                {
                    deq.push_back(node->left);
                    deq.push_back(node->right);
                }
                else
                {
                    //因为NULL也要计算长度，加入队列
                    deq.push_back(NULL);
                    deq.push_back(NULL);
                }
            }
            //对当前层处理，去掉左右端的空节点
            while(!deq.empty())
            {
                if(deq.front() == NULL)
                    deq.pop_front();
                else if(deq.back() == NULL)
                    deq.pop_back();
                else
                    break;
            }
        }
        return maxLen;
    }
};