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
        //采用先序遍历
        if(root == NULL)//用 # 表示NULL
            return " #";//不能忘了 # 前的空格,否则istringstream不能正常读取
        //用" "断开各个节点的值
        string res = " " + to_string(root->val);
        //根-左-右
        return res + serialize(root->left) + serialize(root->right);
    }
    
    //采用dfs方法恢复二叉树,因为每个节点的左右子树情况都必须说明
    //用的istringstream,用它读取字符串后可以迭代的返回他的空格符分割之后的字符
    TreeNode* createTree(istringstream &s){
        string str;
        s >> str;//将s的顶端迭代器的值传给str
        //构造二叉树
        if(str == "#")
            return NULL;
        TreeNode* root = new TreeNode( stoi(str) );
        //每次取完字符串之后,istringstream自动迭代到下一个
        root->left = createTree(s), root->right = createTree(s);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream s(data);
        return createTree(s);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));