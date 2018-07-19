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
    int maxDepth(TreeNode* root) {
        /*
        *************************************************************
        //dfs方法,100%击败率
        if( root == NULL)
            return 0;
        return 1 + max( maxDepth(root->left), maxDepth(root->right));
        *************************************************************
        */
        //bfs方法
        if( root == NULL)
            return 0;
        int depth = 0;
        queue<TreeNode *> que;   //队列
        que.push(root);  //入队
        int count = 1;  //记录当前层中节点的个数
        while(!que.empty())
        {
            TreeNode *temp = que.front();   //队头元素
            que.pop();
            count--;   //更新当前层所剩节点个数
            if(temp->left)   //如果左节点存在，则入队
                que.push(temp->left);
            if(temp->right)   //如果右节点存在，则入队
                que.push(temp->right);
            if(count == 0)    //如果当前层的所有节点都已经出队，则更新为下一层的节点数，并且层数加1
            {
                depth++;
                count = que.size();
            }
        }
        return depth;
    }
};