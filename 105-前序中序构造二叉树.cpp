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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0||inorder.size() == 0||preorder.size()!=inorder.size())  //非法输入
            return NULL;
        vector<int> preorder_l,inorder_l,preorder_r,inorder_r;  //左右子树的前序、中序遍历
        int root_index;  //中序遍历根节点的下标
        int len = preorder.size();  //长度
        TreeNode * root = new TreeNode(preorder[0]);   //构造的二叉树，放根节点(前序的第一个)
        int i;
        //找到中序的根节点位置
        for(i=0;i<len;i++)
        {
            if(inorder[i] == preorder[0] )
            {
                root_index = i;
                break;
            }
        }
        //找左右子树的前序，中序遍历
        for(i=0;i<root_index;i++)
        {
            inorder_l.push_back(inorder[i]);
            preorder_l.push_back(preorder[i+1]);
        }
        for(i=root_index+1;i<len;i++)
        {
            inorder_r.push_back(inorder[i]);
            preorder_r.push_back(preorder[i]);
        }
        root->left = buildTree(preorder_l,inorder_l);   //递归左子树
        root->right = buildTree(preorder_r,inorder_r);  //递归右子树
        return root;
    }
};