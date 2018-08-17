/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static const auto __ = []()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();
class Solution {
public:
    //中序遍历二叉树，找到递减的节点，如果有一个交换他们相邻的，如果有两个，交换这两个
    TreeNode *first = NULL, *second = NULL, *pre = NULL;
    void inorder(TreeNode* root)
    {
        if(root == NULL)
            return;
        //中序查找，找到递减的
        if(root->left)
            inorder(root->left);
        //当前节点的值比根节点的值大
        if(pre != NULL && pre->val > root->val)
        {
            if(first == NULL)
                first = pre;
            second = root;
        }
        pre = root;
        if(root->right)
            inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        if(root == NULL)
            return;
        inorder(root);
        swap(first->val, second->val);
    }
};