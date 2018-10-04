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
    //返回最大值下标
    int maxIndex(vector<int>& nums, int start, int end){
        if(start == end)
            return start;
        int maxNum = nums[start];
        int max_index = start;
        for(int i=start;i<end;i++){
            if(nums[i] > maxNum){
                maxNum = nums[i];
                max_index = i;
            }
        }
        return max_index;
    }
    
    //从start到end递归构造
    TreeNode* construct(vector<int>& nums, int start, int end){
        if(start == end)
            return NULL;
        int max_index = maxIndex(nums, start, end);
        //构造根节点
        TreeNode* root = new TreeNode(nums[max_index]);
        //递归构造左子树
        root->left = construct(nums, start, max_index);
        //递归构造右子树
        root->right = construct(nums, max_index+1, end);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums, 0, nums.size());
    }
};