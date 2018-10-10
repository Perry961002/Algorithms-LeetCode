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
    //找到以root为根节点的和为sum的路径数
    int findPath(TreeNode* root, int curSum, int sum){
        if(root == NULL)
            return 0;
        curSum += root->val;
        return (curSum == sum) + findPath(root->left, curSum, sum) + findPath(root->right, curSum, sum);
    }
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return 0;
        //以root为根节点的路径数 + 左子树中的路径数 + 右子树的路径数
        int result = findPath(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
        return result;
    }
};