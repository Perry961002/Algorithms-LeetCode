/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static const auto ban_io_sync = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    /*
    *在每一个节点时有下面4种情况：
    * 1.root->val(左、右子树最大值都是非正的)
    * 2.leftmax + root->val(右子树最大值非正，左子树最大值是正值)
    * 3.rightmax + root->val(左子树最大值非正，右子树最大值是正值)
    * 4.rightmax + leftmax + root->val(左子树最大值是正值，右子树最大值是正值)
    * 从上面情况中选出成立的，与暂存的最大值比较
    */
    int maxSum(TreeNode* root,int &maxresult)
    {
        if(root == NULL)
            return 0;
        int leftmax = maxSum(root->left,maxresult);
        int rightmax = maxSum(root->right,maxresult);
        int rootmax = root->val + max(leftmax, 0) + max(rightmax, 0);
        maxresult = max(maxresult,rootmax);
        return root->val + max(max(leftmax, 0), max(rightmax, 0) );
    }
    int maxPathSum(TreeNode* root) {
        int maxresult = root->val;
        maxSum(root,maxresult);
        return maxresult;
    }
};