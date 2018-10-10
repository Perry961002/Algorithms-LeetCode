/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL)
            return;
        queue<TreeLinkNode*> q;  //存放同层的兄弟节点
        q.push(root);
        while(!q.empty())
        {
            int count = q.size();  //兄弟节点的个数
            for(int i=0;i<count;i++)
            {
                //兄弟依次出队，除了最右端节点外，每个节点的next指针要指向下一个节点
                TreeLinkNode* node = q.front();
                q.pop();
                //将下一层的节点入队，按左右子节点的顺序
                if(node->left != NULL)
                    q.push(node->left);
                if(node->right != NULL)
                    q.push(node->right);
                if( i != count - 1)
                    node->next = q.front();
                //else
                    //node->next = NULL;
            }
        }
    }
};