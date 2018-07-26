/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。
//满二叉树的节点数 = 2^h - 1, h是高度
//因为节点集中在左边，所以检查左右两边的高度，相等的话就是满二叉树
//不等的话则递归左右子树
static const auto ban_io_sync = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;  //边界
        int left = 0;  //左端高度
        int right = 0;   //右端高度
        for(TreeNode* node = root;node != NULL;node = node->left)
            left++;
        for(TreeNode* node = root;node != NULL;node = node->right)
            right++;
        if(left == right)  //满二叉树
            return (1<<left) - 1;   //满二叉树的节点公式
        else
            return countNodes(root->left) + countNodes(root->right) + 1;  //不是满二叉树的话节点数就是左子树的节点数加上右子树的节点数+1
    }
};