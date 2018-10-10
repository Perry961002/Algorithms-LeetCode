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
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> res;
        if(N == 1){
            TreeNode* node = new TreeNode(0);
            res.push_back(node);
            return res;
        }
        N--;
        for(int i=1; i<=N; i += 2){
            //递归构造左右子树
            vector<TreeNode*> L = allPossibleFBT(i);
            vector<TreeNode*> R = allPossibleFBT(N-i);
            //组合
            for(auto l : L){
                for(auto r : R){
                    TreeNode* node = new TreeNode(0);
                    node->left = l;
                    node->right = r;
                    res.push_back(node);
                }
            }
        }
        return res;
    }
};