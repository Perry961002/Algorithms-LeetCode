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
    *  C(n) = C(i - 1) * C(n - i), i = 1, 2, 3,...,n;
    *  对每个i产生左子树和右子树
    *左子树是1到i - 1的可能
    *右子树是i + 1到n的可能
    */
    vector<TreeNode*> create(int start, int end)   //从start到end构造子树
    {
        if(start > end)
            return vector<TreeNode*> {NULL};
        else if(start == end)
        {
            vector<TreeNode*> result;
            TreeNode* root=new TreeNode(start);
            result.push_back(root);
            return result;
        }
        vector<TreeNode*> result;
        for(int i=start;i<=end;i++)
        {
            vector<TreeNode*> left = create(start, i - 1);
            vector<TreeNode*> right = create(i + 1, end);
            for(int j=0;j<left.size();j++)
                for(int k=0;k<right.size();k++)
                {
                    TreeNode* root = new TreeNode(i);   //i作为根节点
                    root->left = left[j];
                    root->right = right[k];
                    result.push_back(root);
                }
        }
        return result;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)
            return {};
        return create(1, n);
    }
};