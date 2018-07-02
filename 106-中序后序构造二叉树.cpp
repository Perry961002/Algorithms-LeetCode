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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0 || postorder.size()==0 || inorder.size()!=postorder.size() )  //序列不存在或者两个序列的大小不一样，返回null
            return NULL;
        vector<int> in_left,in_right,post_left,post_right;   //左右子树的中序、后序遍历
        int root_index = 0;    //根节点的下标
        int len = inorder.size();   //序列长度
        TreeNode * root = new TreeNode(postorder[len-1]);    //找到根节点
        int i;
        //找到中序的根节点下标
        for(i=0;i<len;i++)
        {
            if(inorder[i] == postorder[len-1])
            {
                root_index = i;
                break;
            }
        }
        //左的中序、后序遍历(除去根节点)
        for(i=0;i<root_index;i++)
        {
            in_left.push_back(inorder[i]);
            post_left.push_back(postorder[i]);
        }
        //右的中序、后序遍历(除去根节点)
        for(i=root_index+1;i<len;i++)
        {
            in_right.push_back(inorder[i]);
            post_right.push_back(postorder[i-1]);
        }
        //递归调用
        root->left = buildTree(in_left,post_left);
        root->right = buildTree(in_right,post_right);
        return root;
    }
};