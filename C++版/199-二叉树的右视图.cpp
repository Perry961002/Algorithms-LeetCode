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
    vector<int> rightSideView(TreeNode* root) {
        //去二叉树进行bfs时队列最右端的值
        vector<int> result;
        if(root == NULL)
            return result;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            result.push_back(que.back()->val);  //每轮的队尾元素就是右端节点
            int count = que.size();  //同层节点的个数
            for(int i = 0;i<count;i++)
            {
                TreeNode* node = que.front();
                que.pop();
                //将下一层的节点入队，按左右子节点的顺序
                if(node->left != NULL)
                    que.push(node->left);
                if(node->right != NULL)
                    que.push(node->right);
            }
        }
        return result;
    }
};