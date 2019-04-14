/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
private:
    vector<TreeNode*> TreeList;  //不满结点的父亲结点为 (len(TreeList) - 1) / 2
public:
    CBTInserter(TreeNode* root) {
        if(root == nullptr) return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            TreeList.push_back(cur);
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
        }
    }
    
    int insert(int v) {
        TreeNode* cur = new TreeNode(v);
        TreeNode* father = TreeList[(TreeList.size() - 1) / 2];
        if(father->left)
            father->right = cur;
        else
            father->left = cur;
        TreeList.push_back(cur);
        return father->val;
    }
    
    TreeNode* get_root() {
        if(TreeList.empty())
            return nullptr;
        return TreeList[0];
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */