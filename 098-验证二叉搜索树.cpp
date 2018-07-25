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
    void create(TreeNode* root, vector<int>& rec)
    {
        //按中序遍历取出节点值
        if(root)
        {
            create(root->left,rec);
            rec.push_back(root->val);
            create(root->right,rec);
        }
    }
    bool isValidBST(TreeNode* root) {
        vector<int> rec;
        create(root,rec);
        for(int i=1;i<rec.size();i++)  //判断是否满足升序
            if(rec[i] <= rec[i - 1])
                return false;
        return true;
    }
};