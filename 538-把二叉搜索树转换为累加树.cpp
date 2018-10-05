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
    //按右-根-左顺序访问,因为是BST
    void findBigger(TreeNode* root, int& biggerSum){
        if(root == NULL)
            return;
        findBigger(root->right, biggerSum);
        root->val += biggerSum;
        //更新biggerSum
        biggerSum = root->val;
        findBigger(root->left, biggerSum);
    }
    TreeNode* convertBST(TreeNode* root) {
        int biggerSum = 0;
        findBigger(root, biggerSum);
        return root;
    }
};