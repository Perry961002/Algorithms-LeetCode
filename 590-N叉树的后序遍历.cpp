/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        //访问子节点
        if(!root->children.empty()){
            for(auto chil : root->children){
                vector<int> tmp = postorder(chil);
                for(auto val : tmp)
                    res.push_back(val);
            }
        }
        //根节点
        res.push_back(root->val);
        return res;
    }
};