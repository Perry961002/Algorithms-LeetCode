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
    //中序遍历,但是要使用常数空间,很明显要设置局部和全局统计量
    vector<int> res;
    //全局最大的频率,当前的值,当前值的频率
    int maxCnt = 0, curVal, tmpCnt = 0;
    void inorder(TreeNode* root){
        //结束方式
        if(root == NULL)
            return;
        //遍历左子树
        inorder(root->left);
        
        //处理根节点
        tmpCnt ++;
        //因为是中序遍历,出现和curVal值不一样的就更新curVal和tmpCnt
        if(root->val != curVal){
            curVal = root->val;
            tmpCnt = 1;
        }
        //curVal的频率更大
        if(tmpCnt > maxCnt){
            maxCnt = tmpCnt;
            //res之前的内容要清空
            res.clear();
            res.push_back(root->val);
        }
        //出现了新的最大频率的数
        else if(tmpCnt == maxCnt){
            res.push_back(root->val);
        }
        
        //处理右子树
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return res;
    }
};