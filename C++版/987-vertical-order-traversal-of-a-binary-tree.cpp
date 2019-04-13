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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;  //最后的结果
        map<int, vector<int>> res;  //以<列标, 对应的节点值数组>暂存结果, 列标自动排序
        queue<pair<int, TreeNode*>> Q;  //存放<列标, 结点>的序对, 用于层次遍历
        Q.push(make_pair(0, root));
        while(!Q.empty()){
            //层次遍历
            int curRowSize = Q.size();
            map<int, vector<int>> curRow; //当前行以<列标, 对应的节点值数组>暂存结果
            for(int i = 0; i < curRowSize; ++i){
                pair<int, TreeNode*> father = Q.front();
                Q.pop();
                //孩子结点入队
                if(father.second->left)
                    Q.push(make_pair(father.first - 1, father.second->left)); //左孩子列标-1
                if(father.second->right)
                    Q.push(make_pair(father.first + 1, father.second->right)); //右孩子列标+1
                curRow[father.first].push_back(father.second->val);
            }
            for(auto iter : curRow){
                //因为已经是同一行, 所以对每个iter里的vector排序
                sort(iter.second.begin(), iter.second.end());
                res[iter.first].insert(res[iter.first].end(), iter.second.begin(), iter.second.end());
            }
        }
        for(auto iter : res){
            result.push_back(iter.second);
        }
        return result;
    }
};