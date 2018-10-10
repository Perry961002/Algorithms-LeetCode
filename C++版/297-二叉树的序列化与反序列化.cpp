/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        //空树
        if(root == NULL)
            return " #";
        string res;
        queue<TreeNode*> que;
        que.push(root);
        //层次遍历
        while(!que.empty()){
            TreeNode* node = que.front();
            que.pop();
            //节点存在
            if(node){
                res += " " + to_string(node->val);
                que.push(node->left);
                que.push(node->right);
            }
            else
                res += " #";
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        //空树
        if(data == " #")
            return NULL;
        istringstream in(data);
        string str;
        in >> str;
        //队列
        queue<TreeNode*> que;
        //构造头节点
        TreeNode* res = new TreeNode(stoi(str));
        TreeNode* node = res;
        que.push(node);
        while(!que.empty()){
            TreeNode* now = que.front();
            que.pop();
            //str应该是now的子节点
            if(!(in >> str))
                break;
            if(str != "#"){
                node = new TreeNode(stoi(str));
                que.push(node);
                now->left = node;
            }
            if(!(in >> str))
                break;
            if(str != "#"){
                node = new TreeNode(stoi(str));
                que.push(node);
                now->right = node;
            }
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));