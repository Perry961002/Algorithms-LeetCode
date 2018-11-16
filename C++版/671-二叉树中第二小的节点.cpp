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
    int findSecondMinimumValue(TreeNode* root) {
        //因为如果一个节点有两个子节点的话，那么这个节点的值不大于它的子节点的值
            //所以如果子节点的值和根相同的话就递归下去寻找最小值,没有的话返回-1
            //最后输出两个中不是-1的那个
        //没有子节点的话直接输出-1
        
        //如果一个节点有两个子节点
        if(root->left != nullptr && root->right != nullptr){
            int left = root->left->val;
            //如果子节点的值和根相同的话就递归下去寻找最小值,没有的话返回-1
            if(left == root->val){
                left = findSecondMinimumValue(root->left);
            }
            int right = root->right->val;
            if(right == root->val){
                right = findSecondMinimumValue(root->right);
            }
            //两个都存在的话输出最小的那个
            if(left != -1 && right != -1){
                return min(left, right);
            }
            //输出其中不是-1的
            return left == -1? right : left;
        }
        return -1;
    }
};