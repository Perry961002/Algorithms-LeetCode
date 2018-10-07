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
    //得到树的深度
    int depth(TreeNode* root){
        if(root == NULL)
            return 0;
        int llen = depth(root->left), rlen = depth(root->right);
        return max(llen, rlen) + 1;
    }
    
    //用先序遍历方式读二叉树
    //leval表示root节点所在的层数, l, r表示节点在当前层的列标范围
    void inorder(vector<vector<string>>& res, TreeNode* root, int level, int l, int r){
        if(root == NULL)
            return;
        //root所在列
        int mid = (l + r) / 2;
        res[level][mid] = to_string(root->val);
        //遍历左右子节点
        inorder(res, root->left, level+1, l, mid-1);
        inorder(res, root->right, level+1, mid+1, r);
    }
    
    vector<vector<string>> printTree(TreeNode* root) {
        //行数, 列数
        int m = depth(root), n = (2 << (m-1)) - 1;
        vector<vector<string>> res(m, vector<string>(n, ""));
        inorder(res, root, 0, 0, n);
        return res;
    }
};